#ifndef OPENCV_GRAB_DUAL
#define OPENCV_GRAB_DUAL
/*!
 * \file OpenCV_Grab_dual.h
 * \author LC
 * \date 九月 2017
 * \brief OpenCV双相机采集程序主界面
 */
 /************************************************************************/
 /* 2017.09.15 添加了放大显示操作
 /* 2017.09.19 添加QSettings记录打开和关闭的位置
 /************************************************************************/


#include <Qtwidgets>
#include <QtCore>
#include <QtGui>
#include <QCameraInfo>

#include <QtWidgets/QMainWindow>
#include "ui_OpenCV_Grab_dual.h"
#include "GrabThread.h"
#include "MyImageViewerDialog.h"


class OpenCV_Grab_dual : public QMainWindow
{
	Q_OBJECT

public:
	OpenCV_Grab_dual(QWidget *parent = Q_NULLPTR);
	void display(QImage img, QLabel &label);
	void closeEvent(QCloseEvent *event);

	VideoCapture m_capture;
	VideoCapture m_capture_2;
	cv::Mat mapx_1, mapy_1;
	cv::Mat mapx_2, mapy_2;
	GrabThread m_thread;
	GrabThread m_thread_2;
	MyImageViewerDialog *m_ImageViewer;
	int m_cam_nums;
	int m_detailshow;

	std::vector<int> open_vec;


	public slots:
	void received_img(QImage img, QString Fps);
	void received_img_2(QImage img, QString Fps);

	void on_actionOpen_triggered();
	void on_actionStop_triggered();
	void on_actionRecord_triggered();
	void on_actionSettings_triggered();
	void on_actionColor_triggered();
	void on_actionDelete_triggered();
	void on_spinBox_valueChanged(int);

	void label_doubleClicked();
	void label_doubleClicked_2();
	void dialog_closed();

private:
	Ui::OpenCV_Grab_dualClass ui;
	void readSettings();
	void writeSettings();
};
#endif
