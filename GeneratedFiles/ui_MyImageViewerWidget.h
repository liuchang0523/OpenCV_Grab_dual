/********************************************************************************
** Form generated from reading UI file 'MyImageViewerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYIMAGEVIEWERWIDGET_H
#define UI_MYIMAGEVIEWERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyImageViewerWidgetClass
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;

    void setupUi(QWidget *MyImageViewerWidgetClass)
    {
        if (MyImageViewerWidgetClass->objectName().isEmpty())
            MyImageViewerWidgetClass->setObjectName(QStringLiteral("MyImageViewerWidgetClass"));
        MyImageViewerWidgetClass->resize(534, 407);
        gridLayout = new QGridLayout(MyImageViewerWidgetClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(MyImageViewerWidgetClass);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(214, 150, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::SizeAllCursor));
        scrollAreaWidgetContents->setContextMenuPolicy(Qt::DefaultContextMenu);
        scrollAreaWidgetContents->setLayoutDirection(Qt::LeftToRight);
        scrollAreaWidgetContents->setAutoFillBackground(true);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 16, 16));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setAutoFillBackground(false);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(0);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(MyImageViewerWidgetClass);

        QMetaObject::connectSlotsByName(MyImageViewerWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyImageViewerWidgetClass)
    {
        MyImageViewerWidgetClass->setWindowTitle(QApplication::translate("MyImageViewerWidgetClass", "+ \346\224\276\345\244\247  - \347\274\251\345\260\217  0\351\200\202\345\220\210\347\252\227\345\217\243  1\345\216\237\345\247\213\345\260\272\345\257\270", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyImageViewerWidgetClass: public Ui_MyImageViewerWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIMAGEVIEWERWIDGET_H
