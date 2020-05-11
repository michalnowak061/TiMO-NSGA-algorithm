/********************************************************************************
** Form generated from reading UI file 'paretowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARETOWINDOW_H
#define UI_PARETOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ParetoWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *Algorithm_Time_label;
    QSpacerItem *horizontalSpacer_2;
    QCustomPlot *ParetoGraph;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *NonDom_Count_label;
    QSpacerItem *horizontalSpacer;
    QPushButton *Save_pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *Actual_Step_label;
    QLabel *label_5;
    QLabel *Max_Step_label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Previous_Step_pushButton;
    QPushButton *Next_Step_pushButton;

    void setupUi(QDialog *ParetoWindow)
    {
        if (ParetoWindow->objectName().isEmpty())
            ParetoWindow->setObjectName(QString::fromUtf8("ParetoWindow"));
        ParetoWindow->setEnabled(true);
        ParetoWindow->resize(613, 573);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../png/dna.png"), QSize(), QIcon::Normal, QIcon::Off);
        ParetoWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(ParetoWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(ParetoWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(180, 20));
        label_2->setMaximumSize(QSize(180, 20));

        horizontalLayout_3->addWidget(label_2);

        Algorithm_Time_label = new QLabel(ParetoWindow);
        Algorithm_Time_label->setObjectName(QString::fromUtf8("Algorithm_Time_label"));
        Algorithm_Time_label->setMaximumSize(QSize(16777215, 20));
        Algorithm_Time_label->setSizeIncrement(QSize(55, 20));

        horizontalLayout_3->addWidget(Algorithm_Time_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 3);

        ParetoGraph = new QCustomPlot(ParetoWindow);
        ParetoGraph->setObjectName(QString::fromUtf8("ParetoGraph"));
        ParetoGraph->setMinimumSize(QSize(400, 400));

        gridLayout->addWidget(ParetoGraph, 0, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ParetoWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(220, 20));

        horizontalLayout->addWidget(label);

        NonDom_Count_label = new QLabel(ParetoWindow);
        NonDom_Count_label->setObjectName(QString::fromUtf8("NonDom_Count_label"));
        NonDom_Count_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(NonDom_Count_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Save_pushButton = new QPushButton(ParetoWindow);
        Save_pushButton->setObjectName(QString::fromUtf8("Save_pushButton"));
        Save_pushButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Save_pushButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(ParetoWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Actual_Step_label = new QLabel(ParetoWindow);
        Actual_Step_label->setObjectName(QString::fromUtf8("Actual_Step_label"));

        horizontalLayout_2->addWidget(Actual_Step_label);

        label_5 = new QLabel(ParetoWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        Max_Step_label = new QLabel(ParetoWindow);
        Max_Step_label->setObjectName(QString::fromUtf8("Max_Step_label"));

        horizontalLayout_2->addWidget(Max_Step_label);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        Previous_Step_pushButton = new QPushButton(ParetoWindow);
        Previous_Step_pushButton->setObjectName(QString::fromUtf8("Previous_Step_pushButton"));
        Previous_Step_pushButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(Previous_Step_pushButton);

        Next_Step_pushButton = new QPushButton(ParetoWindow);
        Next_Step_pushButton->setObjectName(QString::fromUtf8("Next_Step_pushButton"));
        Next_Step_pushButton->setEnabled(true);
        Next_Step_pushButton->setCheckable(false);
        Next_Step_pushButton->setChecked(false);
        Next_Step_pushButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(Next_Step_pushButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 3);


        retranslateUi(ParetoWindow);

        Previous_Step_pushButton->setDefault(true);
        Next_Step_pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(ParetoWindow);
    } // setupUi

    void retranslateUi(QDialog *ParetoWindow)
    {
        ParetoWindow->setWindowTitle(QApplication::translate("ParetoWindow", "Zbi\303\263r rozwi\304\205za\305\204 niezdominowanych", nullptr));
        label_2->setText(QApplication::translate("ParetoWindow", "Czas wykonywania algorytmu:", nullptr));
        Algorithm_Time_label->setText(QApplication::translate("ParetoWindow", "00:00:00", nullptr));
        ParetoGraph->setText(QApplication::translate("ParetoWindow", "Pareto Graph", nullptr));
        label->setText(QApplication::translate("ParetoWindow", "Ilo\305\233\304\207 osobnik\303\263w na wykresie: ", nullptr));
        NonDom_Count_label->setText(QApplication::translate("ParetoWindow", "0", nullptr));
        Save_pushButton->setText(QApplication::translate("ParetoWindow", "Zapisz do pliku", nullptr));
        label_3->setText(QApplication::translate("ParetoWindow", "Krok algorytmu:", nullptr));
        Actual_Step_label->setText(QApplication::translate("ParetoWindow", "0", nullptr));
        label_5->setText(QApplication::translate("ParetoWindow", "/", nullptr));
        Max_Step_label->setText(QApplication::translate("ParetoWindow", "0", nullptr));
        Previous_Step_pushButton->setText(QApplication::translate("ParetoWindow", "-", nullptr));
        Next_Step_pushButton->setText(QApplication::translate("ParetoWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParetoWindow: public Ui_ParetoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARETOWINDOW_H
