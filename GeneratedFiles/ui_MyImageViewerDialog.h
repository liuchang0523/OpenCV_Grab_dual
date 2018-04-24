/********************************************************************************
** Form generated from reading UI file 'MyImageViewerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYIMAGEVIEWERDIALOG_H
#define UI_MYIMAGEVIEWERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "myimageviewerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MyImageViewerDialog
{
public:
    QGridLayout *gridLayout;
    MyImageViewerWidget *widget;

    void setupUi(QDialog *MyImageViewerDialog)
    {
        if (MyImageViewerDialog->objectName().isEmpty())
            MyImageViewerDialog->setObjectName(QStringLiteral("MyImageViewerDialog"));
        MyImageViewerDialog->resize(400, 300);
        gridLayout = new QGridLayout(MyImageViewerDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        widget = new MyImageViewerWidget(MyImageViewerDialog);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(MyImageViewerDialog);

        QMetaObject::connectSlotsByName(MyImageViewerDialog);
    } // setupUi

    void retranslateUi(QDialog *MyImageViewerDialog)
    {
        MyImageViewerDialog->setWindowTitle(QApplication::translate("MyImageViewerDialog", "+ \346\224\276\345\244\247  - \347\274\251\345\260\217  0\351\200\202\345\220\210\347\252\227\345\217\243  1\345\216\237\345\247\213\345\260\272\345\257\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyImageViewerDialog: public Ui_MyImageViewerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIMAGEVIEWERDIALOG_H
