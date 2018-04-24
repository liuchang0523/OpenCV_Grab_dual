#ifndef MYLABEL
#define MYLABEL
/*!
 * \file MyLabel.h
 * \author LC
 * \date ���� 2017
 * \brief ��дmouseDoubleClickEventʹQLabel����˫���ź�
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
	// @brief   ��дmouseDoubleClickEventʹQLabel����˫���ź�
	// @param   event ����¼�
	// @return  
	//===============================================================
	virtual void mouseDoubleClickEvent(QMouseEvent *event)
	{
		emit labelDoubleClicked();
		QLabel::mouseDoubleClickEvent(event);
	};

};
#endif