#ifndef GRABTHREAD
#define GRABTHREAD
/*!
 * \file GrabThread.h
 * \author LC
 * \date 九月 2017
 * \brief 相机获取图片线程
 */
#include <QThread>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QtGui>
#include <QtCore>
#include <QLabel>
using namespace cv;

class GrabThread : public QThread
{
	Q_OBJECT

public:
	GrabThread();
	~GrabThread();

	void run();
	void stop();
	void save();
	void color();
	void init(VideoCapture &captureDevice, Mat &mapx = Mat(), Mat &mapy = Mat());

	QImage Mat2QImage(const Mat &mat);

	Mat img_afterChange;
	VideoCapture *m_capture;
	Mat frame;
	QImage m_qtFrame;
	QString m_prefix;
	QDir m_dir;
	bool m_stop;
	bool m_save;
	bool m_color;
	int m_num;
	bool unDistort = true;
	double t = 0;
	char str[10];

	//畸变矫正矩阵
	Mat map1, map2;

	public slots:
	void prefixChanged(QString);
	void startExplorer();
	void setUnDistort(int flag);

signals:
	void pic(QImage m_qtFrame, QString Fps);
};
#endif
