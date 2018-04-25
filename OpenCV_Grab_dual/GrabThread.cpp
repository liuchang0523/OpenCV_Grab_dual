#include "GrabThread.h"
#include <QApplication>
GrabThread::GrabThread()
{
	m_stop = false;
	m_capture = NULL;
	m_num = 0;
	m_save = false;
	m_color = true;
	unDistort = false;
}

GrabThread::~GrabThread()
{
}
void GrabThread::run()
{

	if (m_capture)
	{
		if (!m_capture->isOpened())
		{
			qDebug() << "打开摄像设备失败！" << endl;
			return;
		}
		while (!m_stop)
		{
			t = (double)getTickCount();//显示帧数时使用
			*m_capture >> frame;
			frame.convertTo(frame, CV_8UC3);//如果不转换会出错
			if (unDistort && !map1.empty())
			{
				remap(frame, frame, map1, map2, cv::INTER_CUBIC);
			}
			//////////////////////////////////////////////////////////////////////////
			//显示Laplacian梯度
			Mat gray_img;
			cvtColor(frame, gray_img, CV_BGR2GRAY);
			Mat imageSobel;
			cv::Laplacian(gray_img, imageSobel, CV_16U);
			double meanValue = mean(imageSobel)[0];
			cvtColor(gray_img, m_img_show, CV_GRAY2RGB);
			std::string meanValueSrting = "Laplacian: " + std::to_string(meanValue);
			putText(m_img_show, meanValueSrting, Point(20, 50), CV_FONT_HERSHEY_COMPLEX, 0.8, Scalar(255, 255, 25), 2);
			//////////////////////////////////////////////////////////////////////////

			m_qtFrame = QImage((const unsigned char*)(m_img_show.data),
				m_img_show.cols, m_img_show.rows,
				m_img_show.cols*m_img_show.channels(),
				QImage::Format_RGB888);
			//m_qtFrame = Mat2QImage(m_img_show);
			QApplication::processEvents();
			//////////////////////////////////显示帧数////////////////////////////////////////
			t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
			double fps = 1.0 / t;
			sprintf(str, "%.2f", fps);
			QString Fps(str);
			QString Resolution = QString::number(m_capture->get(CV_CAP_PROP_FRAME_WIDTH)) + "X" + QString::number(m_capture->get(CV_CAP_PROP_FRAME_HEIGHT));
			Fps = QString::fromLocal8Bit("帧数") + Fps + "FPS" + "            " + Resolution
				+ "            " + QString::fromLocal8Bit("已保存图片数：") + QString::number(m_num);
			//////////////////////////////////显示帧数////////////////////////////////////////
			emit pic(m_qtFrame, Fps);//发送信号
			if (m_save)
			{
				m_num++;
				QString	m_filename = m_prefix + "_" + QString::number(m_num) + ".bmp";
				if (!frame.empty())
				{
					if (m_color)
					{
						imwrite(m_filename.toLocal8Bit().toStdString(), frame);
					}
					else
					{
						imwrite(m_filename.toLocal8Bit().toStdString(), gray_img);
						//imwrite(m_filename.toLocal8Bit().toStdString(), img_afterChange);
					}

				}
				m_save = false;
			}
		}
		m_stop = false;
		return;
	}
}
//===============================================================
// @brief   停止
// @param   
// @return  
//===============================================================
void GrabThread::stop()
{
	if (!m_stop)
	{
		m_num = 0;
		m_stop = true;
		this->wait();
	}
}
//===============================================================
// @brief   保存
// @param   
// @return  
//===============================================================
void GrabThread::save()
{
	if (!m_save)
	{
		m_save = true;
	}
	else
	{
		m_save = false;
	}
}
//===============================================================
// @brief   
// @param   切换黑白与彩色
// @return  
//===============================================================
void GrabThread::color()
{
	m_color = !m_color;
}
//===============================================================
// @brief   初始化
// @param   captureDevice 相机实例
// @return  
//===============================================================
void GrabThread::init(VideoCapture &captureDevice, Mat &mapx, Mat &mapy)
{
	m_capture = &captureDevice;
	if (!mapx.empty())
	{
		map1 = mapx;
		map2 = mapy;
	}
	//m_capture->set(CV_CAP_PROP_FRAME_WIDTH, 1280); //设置相机分辨率大小
	//m_capture->set(CV_CAP_PROP_FRAME_HEIGHT, 720);
}

//===============================================================
// @brief   Mat转换QImage
// @param   Mat类型图片
// @return  QImage类型图片
//===============================================================
QImage GrabThread::Mat2QImage(const Mat &mat)
{
	QImage img;
	if (m_color)
	{
		//cvt Mat BGR 2 QImage RGB
		cvtColor(mat, img_afterChange, CV_BGR2RGB);
		img = QImage((const unsigned char*)(img_afterChange.data),
			img_afterChange.cols, img_afterChange.rows,
			img_afterChange.cols*img_afterChange.channels(),
			QImage::Format_RGB888);
	}
	else
	{
		cvtColor(mat, img_afterChange, CV_BGR2GRAY);
		img = QImage((const unsigned char*)(img_afterChange.data),
			img_afterChange.cols, img_afterChange.rows, QImage::Format_Grayscale8);
		//img.convertToFormat(QImage::Format_Grayscale8);
	}
	return img;
}

//===============================================================
// @brief   保存图片的前缀
// @param   前缀字符串
// @return  
//===============================================================
void GrabThread::prefixChanged(QString str)
{
	//统一保存到"./Images/"文件夹中
	QDir t_dir = QDir::currentPath() + "/Images/";
	if (!t_dir.exists())
	{
		t_dir.mkdir(t_dir.absolutePath());
	}
	//统一保存到"./Images/+prefix/ " 中
	m_dir = QDir::currentPath() + "/Images/" + str + "/";
	if (!m_dir.exists())
	{
		bool ok = m_dir.mkdir(m_dir.absolutePath());
	}
	m_prefix = "./Images/" + str + "/" + str;
}
//===============================================================
// @brief   打开explorer，浏览文件夹
// @param   
// @return  
//===============================================================
void GrabThread::startExplorer()
{
	if (QDir(m_dir.absolutePath()).isReadable())
	{
		QProcess::startDetached("explorer " + m_dir.absolutePath().replace("/", "\\"));
	}
}

void GrabThread::setUnDistort(int flag)
{
	if (flag == 2)
	{
		this->unDistort = true;
	}
	else
		this->unDistort = false;
}
