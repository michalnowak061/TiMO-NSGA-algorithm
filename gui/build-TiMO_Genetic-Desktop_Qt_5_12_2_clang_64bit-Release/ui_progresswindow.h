/********************************************************************************
** Form generated from reading UI file 'progresswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSWINDOW_H
#define UI_PROGRESSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ProgressWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *Actual_Population_Number_label;
    QLabel *label_3;
    QLabel *Maximum_Population_Number_label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *Stop_pushButton;
    QLabel *Time_label;
    QCustomPlot *Preview_Plot_label;
    QHBoxLayout *horizontalLayout;
    QProgressBar *Progress_progressBar;

    void setupUi(QDialog *ProgressWindow)
    {
        if (ProgressWindow->objectName().isEmpty())
            ProgressWindow->setObjectName(QString::fromUtf8("ProgressWindow"));
        ProgressWindow->resize(420, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../png/dna.png"), QSize(), QIcon::Normal, QIcon::Off);
        ProgressWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(ProgressWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(ProgressWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(label);

        Actual_Population_Number_label = new QLabel(ProgressWindow);
        Actual_Population_Number_label->setObjectName(QString::fromUtf8("Actual_Population_Number_label"));
        Actual_Population_Number_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(Actual_Population_Number_label);

        label_3 = new QLabel(ProgressWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(label_3);

        Maximum_Population_Number_label = new QLabel(ProgressWindow);
        Maximum_Population_Number_label->setObjectName(QString::fromUtf8("Maximum_Population_Number_label"));
        Maximum_Population_Number_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(Maximum_Population_Number_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(ProgressWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(pushButton);

        Stop_pushButton = new QPushButton(ProgressWindow);
        Stop_pushButton->setObjectName(QString::fromUtf8("Stop_pushButton"));
        Stop_pushButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(Stop_pushButton);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        Time_label = new QLabel(ProgressWindow);
        Time_label->setObjectName(QString::fromUtf8("Time_label"));
        Time_label->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(Time_label, 3, 0, 1, 1);

        Preview_Plot_label = new QCustomPlot(ProgressWindow);
        Preview_Plot_label->setObjectName(QString::fromUtf8("Preview_Plot_label"));
        Preview_Plot_label->setMinimumSize(QSize(400, 400));

        gridLayout->addWidget(Preview_Plot_label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Progress_progressBar = new QProgressBar(ProgressWindow);
        Progress_progressBar->setObjectName(QString::fromUtf8("Progress_progressBar"));
        Progress_progressBar->setMinimumSize(QSize(0, 0));
        Progress_progressBar->setMaximumSize(QSize(16777215, 25));
        Progress_progressBar->setValue(0);

        horizontalLayout->addWidget(Progress_progressBar);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(ProgressWindow);

        QMetaObject::connectSlotsByName(ProgressWindow);
    } // setupUi

    void retranslateUi(QDialog *ProgressWindow)
    {
        ProgressWindow->setWindowTitle(QApplication::translate("ProgressWindow", "Post\304\231p", nullptr));
        label->setText(QApplication::translate("ProgressWindow", "Populacja:", nullptr));
        Actual_Population_Number_label->setText(QApplication::translate("ProgressWindow", "0", nullptr));
        label_3->setText(QApplication::translate("ProgressWindow", "/", nullptr));
        Maximum_Population_Number_label->setText(QApplication::translate("ProgressWindow", "0", nullptr));
        pushButton->setText(QApplication::translate("ProgressWindow", "Anuluj", nullptr));
        Stop_pushButton->setText(QApplication::translate("ProgressWindow", "Zapisz", nullptr));
        Time_label->setText(QApplication::translate("ProgressWindow", "00:00:00", nullptr));
        Preview_Plot_label->setText(QApplication::translate("ProgressWindow", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressWindow: public Ui_ProgressWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSWINDOW_H
