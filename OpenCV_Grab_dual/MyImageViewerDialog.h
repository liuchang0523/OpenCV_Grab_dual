#ifndef __MYIMAGEVIEWERDIALOG_H__
#define __MYIMAGEVIEWERDIALOG_H__


#include <QDialog>
#include <Qtwidgets>
#include "ui_MyImageViewerDialog.h"

/*!
* \class MyImageViewerDialog
*
* \brief ���õĿ��Ϸ�ͼƬ�鿴�Ի���֧�ֶ���+�Ŵ� -��С 0�ʺϴ���  1ԭʼ�ߴ�
*				֧������϶���֧������������
*
* \author LC
* \date ���� 2017
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
		 *	���ô��ڴ�С
		 */
		QSettings m_settings("my", "OpenCV_Grab_dual");

		//��ȡ��Ļ��С
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
	// @brief   ����MyImageViewerWidget��open����
	// @param   img ͼƬ
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