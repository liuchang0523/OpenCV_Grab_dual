/********************************************************************************
** Form generated from reading UI file 'OpenCV_Grab_dual.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCV_GRAB_DUAL_H
#define UI_OPENCV_GRAB_DUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <mylabel.h>
#include <mylineedit.h>

QT_BEGIN_NAMESPACE

class Ui_OpenCV_Grab_dualClass
{
public:
    QAction *actionOpen;
    QAction *actionStop;
    QAction *actionRecord;
    QAction *actionSettings;
    QAction *actionColor;
    QAction *actionExplorer;
    QAction *actionDelete;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    MyLineEdit *lineEdit;
    QLabel *label_2;
    MyLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    MyLabel *img1;
    MyLabel *img2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenCV_Grab_dualClass)
    {
        if (OpenCV_Grab_dualClass->objectName().isEmpty())
            OpenCV_Grab_dualClass->setObjectName(QStringLiteral("OpenCV_Grab_dualClass"));
        OpenCV_Grab_dualClass->resize(601, 400);
        actionOpen = new QAction(OpenCV_Grab_dualClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/Start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionStop = new QAction(OpenCV_Grab_dualClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/Stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon1);
        actionRecord = new QAction(OpenCV_Grab_dualClass);
        actionRecord->setObjectName(QStringLiteral("actionRecord"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/Save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecord->setIcon(icon2);
        actionSettings = new QAction(OpenCV_Grab_dualClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/Setting.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon3);
        actionColor = new QAction(OpenCV_Grab_dualClass);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionColor->setCheckable(true);
        actionColor->setChecked(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/cai.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/gray.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionColor->setIcon(icon4);
        actionExplorer = new QAction(OpenCV_Grab_dualClass);
        actionExplorer->setObjectName(QStringLiteral("actionExplorer"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/Explorer.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExplorer->setIcon(icon5);
        actionDelete = new QAction(OpenCV_Grab_dualClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/full_garbage.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/OpenCV_Grab_dual/Resources/bin_empty.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionDelete->setIcon(icon6);
        centralWidget = new QWidget(OpenCV_Grab_dualClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(5000, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit = new MyLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new MyLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(lineEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(false);

        horizontalLayout->addWidget(checkBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        img1 = new MyLabel(centralWidget);
        img1->setObjectName(QStringLiteral("img1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(img1->sizePolicy().hasHeightForWidth());
        img1->setSizePolicy(sizePolicy2);
        img1->setScaledContents(false);
        img1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(img1);

        img2 = new MyLabel(centralWidget);
        img2->setObjectName(QStringLiteral("img2"));
        sizePolicy2.setHeightForWidth(img2->sizePolicy().hasHeightForWidth());
        img2->setSizePolicy(sizePolicy2);
        img2->setScaledContents(false);
        img2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(img2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 9);
        OpenCV_Grab_dualClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(OpenCV_Grab_dualClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        OpenCV_Grab_dualClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenCV_Grab_dualClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OpenCV_Grab_dualClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionRecord);
        mainToolBar->addAction(actionSettings);
        mainToolBar->addAction(actionColor);
        mainToolBar->addAction(actionExplorer);
        mainToolBar->addAction(actionDelete);

        retranslateUi(OpenCV_Grab_dualClass);

        QMetaObject::connectSlotsByName(OpenCV_Grab_dualClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenCV_Grab_dualClass)
    {
        OpenCV_Grab_dualClass->setWindowTitle(QApplication::translate("OpenCV_Grab_dualClass", "OpenCV_Grab_dual", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("OpenCV_Grab_dualClass", "Open", Q_NULLPTR));
        actionStop->setText(QApplication::translate("OpenCV_Grab_dualClass", "Stop", Q_NULLPTR));
        actionRecord->setText(QApplication::translate("OpenCV_Grab_dualClass", "Record", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("OpenCV_Grab_dualClass", "Settings", Q_NULLPTR));
        actionColor->setText(QApplication::translate("OpenCV_Grab_dualClass", "Color", Q_NULLPTR));
        actionExplorer->setText(QApplication::translate("OpenCV_Grab_dualClass", "Explorer", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("OpenCV_Grab_dualClass", "Delete", Q_NULLPTR));
        label->setText(QApplication::translate("OpenCV_Grab_dualClass", "\347\233\270\346\234\2721\345\211\215\347\274\200\345\220\215", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("OpenCV_Grab_dualClass", "L", Q_NULLPTR));
        label_2->setText(QApplication::translate("OpenCV_Grab_dualClass", "\347\233\270\346\234\2722\345\211\215\347\274\200\345\220\215", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("OpenCV_Grab_dualClass", "R", Q_NULLPTR));
        checkBox->setText(QApplication::translate("OpenCV_Grab_dualClass", "\345\216\273\347\225\270\345\217\230", Q_NULLPTR));
        img1->setText(QString());
        img2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenCV_Grab_dualClass: public Ui_OpenCV_Grab_dualClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCV_GRAB_DUAL_H
