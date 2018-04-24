#ifndef __MYIMAGEVIEWERDIALOG_H__
#define __MYIMAGEVIEWERDIALOG_H__


#include <QDialog>
#include <Qtwidgets>
#include "ui_MyImageViewerDialog.h"

/*!
* \class MyImageViewerDialog
*
* \brief 自用的可拖放图片查看对话框，支持动作+放大 -缩小 0适合窗口  1原始尺寸
*				支持鼠标拖动，支持鼠标滚轮缩放
*
* \author LC
* \date 九月 2017
*/
class MyImageViewerDialog : public QDialog
{
	Q_OBJECT

public:
	MyImageViewerDialog(QWidget *parent = Q_NULLPTR)
		: QDialog(parent)
	{
		ui.setupUi(this);
		/*
		 *	设置窗口大小
		 */
		QSettings m_settings("my", "OpenCV_Grab_dual");

		//获取屏幕大小
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
		
				//ui.widget->adjustSize();
	};

	~MyImageViewerDialog()
	{
	};
	//===============================================================
	// @brief   调用MyImageViewerWidget的open函数
	// @param   img 图片
	// @return  
	//===============================================================
	void open(QImage img)
	{
		ui.widget->open(img);
	}

protected:
	virtual void closeEvent(QCloseEvent *e)
	{
		QDialog::closeEvent(e);
	};

private:
	Ui::MyImageViewerDialog ui;
};
#endif  //__MYIMAGEVIEWERDIALOG_H__
//  [9/25/2017 LC]