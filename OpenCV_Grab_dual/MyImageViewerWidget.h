#ifndef MYIMAGEVIEWERWIDGET
#define MYIMAGEVIEWERWIDGET

#include <QtWidgets>
#include "ui_MyImageViewerWidget.h"

/*!
 * \class MyImageViewerWidget
 *
 * \brief 自用的可拖放图片查看控件，支持动作+放大 -缩小 0适合窗口  1原始尺寸
 *				支持鼠标拖动，支持鼠标滚轮缩放
 *
 * \author LC
 * \date 九月 2017
 */
class MyImageViewerWidget : public QWidget
{
	Q_OBJECT

public:
	MyImageViewerWidget(QWidget *parent = Q_NULLPTR);


public:
	void open(QString pic_name);
	void open(QImage image);
private slots:
	void open();
	void zoomIn();
	void zoomOut();
	void normalSize();
	void fitToWindow();

protected:
	void keyPressEvent(QKeyEvent * event);

	/*
	 *	添加鼠标拖动支持
	 */
	bool eventFilter(QObject *obj, QEvent *e);
	bool m_moveStart;
	bool m_ContinuousMove;
	QPoint m_MousePoint;


private:
	void scaleImage(double factor);
	void adjustScrollBar(QScrollBar *scrollBar, double factor);
	double scaleFactor;

	Ui::MyImageViewerWidgetClass ui;
};
#endif