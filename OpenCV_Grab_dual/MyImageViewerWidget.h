#ifndef MYIMAGEVIEWERWIDGET
#define MYIMAGEVIEWERWIDGET

#include <QtWidgets>
#include "ui_MyImageViewerWidget.h"

/*!
 * \class MyImageViewerWidget
 *
 * \brief ���õĿ��Ϸ�ͼƬ�鿴�ؼ���֧�ֶ���+�Ŵ� -��С 0�ʺϴ���  1ԭʼ�ߴ�
 *				֧������϶���֧������������
 *
 * \author LC
 * \date ���� 2017
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
	 *	�������϶�֧��
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