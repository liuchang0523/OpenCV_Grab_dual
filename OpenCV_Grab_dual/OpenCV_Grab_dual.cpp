#include "OpenCV_Grab_dual.h"
#include "AfFineClock/AfFineClock.h"


OpenCV_Grab_dual::OpenCV_Grab_dual(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	readSettings();

	//获取可用相机数目
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	m_cam_nums = 0;//安装了basler驱动的话会有一个basler的相机

	for (int i = 0; i < cameras.size(); ++i)
	{
		if (cameras[i].deviceName().contains("usb"))
		{
			open_vec.push_back(i);
			m_cam_nums++;
		}
	}

	if (m_cam_nums == 1)
	{
		connect(ui.lineEdit, SIGNAL(editingFinished(QString)), &m_thread, SLOT(prefixChanged(QString)));
		connect(&m_thread, SIGNAL(pic(QImage, QString)), this, SLOT(received_img(QImage, QString)));
		connect(ui.actionExplorer, SIGNAL(triggered()), &m_thread, SLOT(startExplorer()));
		connect(ui.checkBox, SIGNAL(stateChanged(int)), &m_thread, SLOT(setUnDistort(int)));
		ui.lineEdit->editingFinished(ui.lineEdit->text());
	}
	else if (m_cam_nums == 2)
	{
		connect(ui.lineEdit, SIGNAL(editingFinished(QString)), &m_thread, SLOT(prefixChanged(QString)));
		connect(ui.lineEdit_2, SIGNAL(editingFinished(QString)), &m_thread_2, SLOT(prefixChanged(QString)));
		connect(&m_thread, SIGNAL(pic(QImage, QString)), this, SLOT(received_img(QImage, QString)));
		connect(&m_thread_2, SIGNAL(pic(QImage, QString)), this, SLOT(received_img_2(QImage, QString)));
		connect(ui.checkBox, SIGNAL(stateChanged(int)), &m_thread, SLOT(setUnDistort(int)));
		connect(ui.checkBox, SIGNAL(stateChanged(int)), &m_thread_2, SLOT(setUnDistort(int)));
		connect(ui.actionExplorer, SIGNAL(triggered()), &m_thread, SLOT(startExplorer()));
		connect(ui.actionExplorer, SIGNAL(triggered()), &m_thread_2, SLOT(startExplorer()));
		ui.lineEdit->editingFinished(ui.lineEdit->text());
		ui.lineEdit_2->editingFinished(ui.lineEdit_2->text());
	}

	QFile calibL("MatrixL.xml");
	if (calibL.exists())
	{
		qDebug() << QStringLiteral("从MatrixL.xml读取标定参数");
		FileStorage fs("MatrixL.xml", FileStorage::READ);
		Mat matrix, distCoeffs;
		fs["MatrixL"] >> matrix;
		fs["K"] >> distCoeffs;
		fs.release();
		cv::Size imageSize(1280, 720);
		initUndistortRectifyMap(matrix, distCoeffs, cv::noArray(), matrix, imageSize, CV_32FC1, mapx_1, mapy_1);
	}
	QFile calibR("MatrixR.xml");
	if (calibR.exists())
	{
		qDebug() << QStringLiteral("从MatrixR.xml读取标定参数");
		FileStorage fs("MatrixR.xml", FileStorage::READ);
		Mat matrix, distCoeffs;
		fs["MatrixR"] >> matrix;
		fs["K"] >> distCoeffs;
		fs.release();
		cv::Size imageSize(1280, 720);
		initUndistortRectifyMap(matrix, distCoeffs, cv::noArray(), matrix, imageSize, CV_32FC1, mapx_2, mapy_2);
	}

	//设置默认为黑白
	ui.actionColor->setChecked(true);
	emit on_actionOpen_triggered();
	emit on_actionColor_triggered();

	m_ImageViewer = new MyImageViewerDialog(this);

	double a = m_capture.get(CV_CAP_PROP_BUFFERSIZE);


	connect(ui.img1, SIGNAL(labelDoubleClicked()), this, SLOT(label_doubleClicked()));
	connect(ui.img2, SIGNAL(labelDoubleClicked()), this, SLOT(label_doubleClicked_2()));
	connect(m_ImageViewer, SIGNAL(rejected()), this, SLOT(dialog_closed()));
}


//===============================================================
// @brief: 显示图片于标签
// @param[in] img: 图片
// @param[in] label: 标签
// @return: void
//===============================================================
void OpenCV_Grab_dual::display(QImage img, QLabel &label)
{
	if (!img.isNull())
	{
		QImage imgScaled = img.scaled(label.size(), Qt::KeepAspectRatio);//2-3ms
		label.setPixmap(QPixmap::fromImage(imgScaled));
	}
}
//===============================================================
// @brief 						重写关闭事件
// @param[in] event:  事件
// @return 
//===============================================================
void OpenCV_Grab_dual::closeEvent(QCloseEvent *event)
{
	if (m_cam_nums == 1)
	{
		m_thread.stop();
		m_thread.exit();
	}
	else if (m_cam_nums == 2)
	{
		m_thread.stop();
		m_thread.exit();
		m_thread_2.stop();
		m_thread_2.exit();
	}
	writeSettings();
	QMainWindow::closeEvent(event);
}

//===============================================================
// @brief 					从线程1接收到图片	
// @param[in] img:  图片
// @param[in] Fps:  带有帧数的字符串
// @return 					void
//===============================================================

void OpenCV_Grab_dual::received_img(QImage img, QString Fps)
{

	if (m_detailshow == 1)
		m_ImageViewer->open(img);
	else
		display(img, *ui.img1);
	ui.statusBar->showMessage(Fps);
}

//===============================================================
// @brief						从线程2接收到图片
// @param[in] img:  图片
// @param[in] Fps:  带有帧数的字符串
// @return
//===============================================================
void OpenCV_Grab_dual::received_img_2(QImage img, QString Fps)
{
	if (m_detailshow == 2)
		m_ImageViewer->open(img);
	else
		display(img, *ui.img2);
}
//===============================================================
// @brief   Open动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionOpen_triggered()
{
	if (!m_capture.isOpened())
	{
		if (m_cam_nums == 1)
		{
			m_capture.open(open_vec[0]);
			m_capture.set(CAP_PROP_EXPOSURE, -7);
			m_thread.init(m_capture, mapx_1, mapy_1);
		}
		else if (m_cam_nums == 2)
		{
			m_capture.open(open_vec[0]);
			m_capture_2.open(open_vec[1]);
			m_capture.set(CAP_PROP_EXPOSURE, -7);
			m_capture_2.set(CAP_PROP_EXPOSURE, -7);
			m_thread.init(m_capture, mapx_1, mapy_1);
			m_thread_2.init(m_capture_2, mapx_2, mapy_2);
		}
	}
	if (m_cam_nums == 1)
	{
		m_thread.start();
	}
	else if (m_cam_nums == 2)
	{
		m_thread.start();
		m_thread_2.start();
	}
	ui.actionStop->setEnabled(true);
	ui.actionOpen->setEnabled(false);
}
//===============================================================
// @brief   Stop动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionStop_triggered()
{
	if (m_cam_nums == 1)
	{
		m_thread.stop();
	}
	else if (m_cam_nums == 2)
	{
		m_thread.stop();
		m_thread_2.stop();
	}
	ui.actionOpen->setEnabled(true);
	ui.actionStop->setEnabled(false);
}
//===============================================================
// @brief   Record动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionRecord_triggered()
{
	if (m_cam_nums == 1)
	{
		ui.lineEdit->editingFinished(ui.lineEdit->text());
		m_thread.save();
	}
	else if (m_cam_nums == 2)
	{
		ui.lineEdit->editingFinished(ui.lineEdit->text());
		ui.lineEdit_2->editingFinished(ui.lineEdit_2->text());
		m_thread.save();
		m_thread_2.save();
	}
	ui.actionDelete->setIcon(QIcon(":/OpenCV_Grab_dual/Resources/full_garbage.ico"));
}
//===============================================================
// @brief   Settings动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionSettings_triggered()
{
	if (m_cam_nums == 1)
	{
		if (m_capture.isOpened())
		{
			m_capture.set(CV_CAP_PROP_SETTINGS, 1);
		}
	}
	else if (m_cam_nums == 2)
	{
		if (m_capture.isOpened() && m_capture_2.isOpened())
		{
			m_capture.set(CV_CAP_PROP_SETTINGS, 1);
			m_capture_2.set(CV_CAP_PROP_SETTINGS, 1);
		}
	}
}
//===============================================================
// @brief   Color动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionColor_triggered()
{
	if (m_cam_nums == 1)
	{
		m_thread.color();
	}
	else if (m_cam_nums == 2)
	{
		m_thread.color();
		m_thread_2.color();
	}
}
//===============================================================
// @brief   Delete动作响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::on_actionDelete_triggered()
{
	int ret = QMessageBox::warning(this, QString::fromLocal8Bit("注意!!!"),
		QString::fromLocal8Bit("你确定要清空所有文件夹吗？"),
		QMessageBox::Yes | QMessageBox::Cancel,
		QMessageBox::Yes);
	if (ret == QMessageBox::Yes)
	{
		int ret2 = QMessageBox::warning(this, QString::fromLocal8Bit("注意!!!"),
			QString::fromLocal8Bit("不可恢复噢！？"),
			QMessageBox::Yes | QMessageBox::Cancel,
			QMessageBox::Yes);
		if (ret2 == QMessageBox::Yes)
		{
			ui.actionDelete->setIcon(QIcon(":/OpenCV_Grab_dual/Resources/bin_empty.ico"));
			QDir t_path = "./Images/";
			t_path.removeRecursively();
			m_thread.m_num = 0;
			m_thread_2.m_num = 0;
		}
	}
}

void OpenCV_Grab_dual::printStateChanged(int t)
{
	qDebug() << t;
}

//===============================================================
// @brief   label双击事件响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::label_doubleClicked()
{
	m_detailshow = 1;
	m_ImageViewer->show();
}
//===============================================================
// @brief   label2双击事件响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::label_doubleClicked_2()
{
	m_detailshow = 2;
	m_ImageViewer->show();
}
//===============================================================
// @brief   对话框关闭事件响应
// @param   
// @return  
//===============================================================
void OpenCV_Grab_dual::dialog_closed()
{
	m_detailshow = 0;
}
//===============================================================
// @brief   读取设置
// @param   
// @return  
//===============================================================

void OpenCV_Grab_dual::readSettings()
{
	QSettings m_settings("my", "OpenCV_Grab_dual");

	//设置窗体大小为屏幕大小的2/3
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect screenRect = desktopWidget->screenGeometry();
	//this->resize(screenRect.width() * 2 / 3, screenRect.height() * 2 / 3);
	m_settings.beginGroup("mainWindow");

	if (m_settings.value("size").toSize().width() < screenRect.width() &&
		m_settings.value("size").toSize().height() < screenRect.height())
	{
		resize(m_settings.value("size", QSize(screenRect.width() * 2 / 3, screenRect.height() * 2 / 3)).toSize());
	}
	else
		resize(screenRect.size() * 2 / 3);

	move(m_settings.value("pos", QPoint(screenRect.width() * 1 / 3, screenRect.height() * 1 / 3)).toPoint());
	m_settings.endGroup();
}
//===============================================================
// @brief   写入设置
// @param   
// @return  
//===============================================================

void OpenCV_Grab_dual::writeSettings()
{
	QSettings m_settings("my", "OpenCV_Grab_dual");
	m_settings.beginGroup("mainWindow");
	m_settings.setValue("size", size());
	m_settings.setValue("pos", pos());
	m_settings.endGroup();
}
