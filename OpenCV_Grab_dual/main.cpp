#include "OpenCV_Grab_dual.h"
#include <QtWidgets/QApplication>
#include <QCameraInfo>
#include <iostream>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//获取可用相机数目
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	int m_cam_nums = 0;//安装了basler驱动的话会有一个basler的相机

	for (int i = 0; i < cameras.size(); ++i)
	{
		if (cameras[i].deviceName().contains("usb"))
		{
			m_cam_nums++;
		}
	}
	// 	//获取可用相机数目
	// 	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	// 	int m_cam_nums = cameras.size();//安装了busler驱动的话会有一个busler的相机
	QSplashScreen splash;
	QPixmap pixmap;
	switch (m_cam_nums)
	{
	case 0:
		pixmap.load(":/OpenCV_Grab_dual/Resources/0.png");
		splash.setPixmap(pixmap);
		splash.show();
		Sleep(2000);//如果没有连接相机，停留2秒
		return -1;
	case 1:
		pixmap.load(":/OpenCV_Grab_dual/Resources/1.png");
		splash.setPixmap(pixmap);
		splash.show();
		a.processEvents();
		break;
	default:
		pixmap.load(":/OpenCV_Grab_dual/Resources/2.png");
		splash.setPixmap(pixmap);
		splash.show();
		a.processEvents();
		break;
	}
	OpenCV_Grab_dual w;
	w.show();
	splash.finish(&w);
	return a.exec();
}
