#ifndef MYLINEEDIT
#define MYLINEEDIT
/*!
 * \file MyLineEdit.h
 * \author LC
 * \date 九月 2017
 * \brief 重写QLineEdit使其可以发送"editingFinished(QString)"信号
 */

#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>

class MyLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit MyLineEdit(QWidget *parent = 0):
		QLineEdit(parent)
	{

	}
signals:
	void editingFinished(QString);

protected:
	virtual void keyPressEvent(QKeyEvent *e)
	{
		if (e->key() == Qt::Key_Return)
		{
			emit editingFinished(this->text());
		}
		QLineEdit::keyPressEvent(e);
	}
	virtual void focusOutEvent(QFocusEvent *e)
	{
		emit editingFinished(this->text());
		QLineEdit::focusOutEvent(e);
	}
};
#endif