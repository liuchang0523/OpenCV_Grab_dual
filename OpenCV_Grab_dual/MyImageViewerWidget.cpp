#include "MyImageViewerWidget.h"
/*!
 * \file MyImageViewerWidget.cpp
 *
 * \author LC
 * \date 九月 2017
 *
 */
MyImageViewerWidget::MyImageViewerWidget(QWidget *parent)
: QWidget(parent), m_moveStart(false), m_ContinuousMove(false), m_MousePoint(QPoint(0,0))
{
	ui.setupUi(this);
	scaleFactor = 1.0;
	ui.label->setBackgroundRole(QPalette::Base);
	ui.label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.label->setScaledContents(true);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	installEventFilter(this); //添加鼠标拖动支持
}
//===============================================================
// @brief   打开图片
// @param   
// @return  
//===============================================================
void MyImageViewerWidget::open()
{
	QPixmap img("0.png");
	ui.label->setPixmap(img);
	ui.label->adjustSize();
	ui.scrollAreaWidgetContents->adjustSize();
	scaleFactor = 1.0;
}

//===============================================================
// @brief   图片名打开图片
// @param   Qstring 图片名
// @return  
//===============================================================
void MyImageViewerWidget::open(QString pic_name)
{
	QPixmap img(pic_name);
	ui.label->setPixmap(img);
	ui.label->adjustSize();
	scaleImage(1.0);
	ui.scrollAreaWidgetContents->adjustSize();
}

//===============================================================
// @brief   打开QImage类型
// @param   QImage 图片
// @return  
//===============================================================
void MyImageViewerWidget::open(QImage image)
{
	ui.label->setPixmap(QPixmap::fromImage(image));
	ui.label->adjustSize();
	scaleImage(1.0);
	ui.scrollAreaWidgetContents->adjustSize();
}

//===============================================================
// @brief   放大
// @param   
// @return  
//===============================================================
void MyImageViewerWidget::zoomIn()
{
	ui.scrollArea->setWidgetResizable(false);
	scaleImage(1.25);
}

//===============================================================
// @brief   缩小
// @param   
// @return  
//===============================================================
void MyImageViewerWidget::zoomOut()
{
	ui.scrollArea->setWidgetResizable(false);
	scaleImage(0.8);
}

//===============================================================
// @brief   原始尺寸
// @param   
// @return  
//===============================================================
void MyImageViewerWidget::normalSize()
{
	ui.scrollArea->setWidgetResizable(false);
	ui.label->adjustSize();
	ui.scrollAreaWidgetContents->adjustSize();
	scaleFactor = 1.0;
}

//===============================================================
// @brief   适应窗口
// @param   
// @return  
//===============================================================
void MyImageViewerWidget::fitToWindow()
{
	ui.scrollArea->setWidgetResizable(true);
	ui.scrollAreaWidgetContents->adjustSize();
	ui.label->resize(ui.scrollAreaWidgetContents->size());
}
//===============================================================
// @brief   重写Widget的按钮事件
// @param   QKeyEvent event
// @return  
//===============================================================
void MyImageViewerWidget::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case 48:
		//emit fitToWindow();
		break;
	case 49:
		emit normalSize();
		break;
	case 43:
		emit zoomIn();
		break;
	case 45:
	case 95:
		emit zoomOut();
		break;
	default:
		break;
	}
	QWidget::keyPressEvent(event);
}
//===============================================================
// @brief   添加鼠标拖动支持，重写事件过滤器
// @param   QObject ，QEvent
// @return  
//===============================================================
bool MyImageViewerWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (e->type() == QEvent::MouseMove)
	{
		QMouseEvent *me = (QMouseEvent*)e;
		if (me->buttons() & Qt::LeftButton)
		{
			if (!m_moveStart)
			{
				m_moveStart = true;
				m_ContinuousMove = false;
				m_MousePoint = me->globalPos();
			}
			else
			{
				QScrollBar *scrollBarx = ui.scrollArea->horizontalScrollBar();
				QScrollBar *scrollBary = ui.scrollArea->verticalScrollBar();

				QPoint p = me->globalPos();
				int offsetx = p.x() - m_MousePoint.x();
				int offsety = p.y() - m_MousePoint.y();
				if (!m_ContinuousMove && (offsetx > -10 && offsetx < 10) && (offsety > -10 && offsety < 10))
					return false;

				m_ContinuousMove = true;

				scrollBarx->setValue(scrollBarx->value() - offsetx);
				scrollBary->setValue(scrollBary->value() - offsety);
				m_MousePoint = p;
			}
			return true;
		}
	}
	else if (e->type() == QEvent::MouseButtonRelease)
	{
		m_moveStart = false;
	}
	return QObject::eventFilter(obj, e);
}
//===============================================================
// @brief   放大和缩小图片
// @param   factor比例
// @return  
//===============================================================
void MyImageViewerWidget::scaleImage(double factor)
{
	Q_ASSERT(ui.label->pixmap());
	if (0.2 <= scaleFactor * factor && scaleFactor * factor <= 3.0)
	{
		scaleFactor *= factor;
		ui.label->resize(scaleFactor * ui.label->pixmap()->size());
		ui.scrollAreaWidgetContents->adjustSize();

		adjustScrollBar(ui.scrollArea->horizontalScrollBar(), factor);
		adjustScrollBar(ui.scrollArea->verticalScrollBar(), factor);
	}
}
//===============================================================
// @brief   调整滚动条
// @param   scrollBar 滚动条，factor 比例
// @return  
//===============================================================
void MyImageViewerWidget::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
	scrollBar->setValue(int(factor * scrollBar->value()
		+ ((factor - 1) * scrollBar->pageStep() / 2)));
}
