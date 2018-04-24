#ifndef MYLABEL
#define MYLABEL
/*!
 * \file MyLabel.h
 * \author LC
 * \date 九月 2017
 * \brief 重写mouseDoubleClickEvent使QLabel发送双击信号
 */
#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget *parent = 0) 
		: QLabel(parent)
	{
	};
signals:
	void labelDoubleClicked();

protected:
	//===============================================================
	// @brief   重写mouseDoubleClickEvent使QLabel发送双击信号
	// @param   event 鼠标事件
	// @return  
	//===============================================================
	virtual void mouseDoubleClickEvent(QMouseEvent *event)
	{
		emit labelDoubleClicked();
		QLabel::mouseDoubleClickEvent(event);
	};

};
#endif