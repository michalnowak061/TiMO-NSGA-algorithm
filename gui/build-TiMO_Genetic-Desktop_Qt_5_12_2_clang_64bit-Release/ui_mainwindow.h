/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionO_Programie;
    QAction *actionInstrukcja;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *Functions_tableWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Add_Function_pushButton;
    QPushButton *Delete_Function_pushButton;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Test_Function_label;
    QComboBox *Test_Function_comboBox;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *Variables_tableWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *Add_Variable_pushButton;
    QPushButton *Delete_Variable_pushButton;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Algorithm_Start_pushButton;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QDoubleSpinBox *Radius_doubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Population_Size_label;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *Population_Size_spinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *Max_Population_Number_label;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *Max_Population_Number_spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Crossing_Probability_label;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *Crossing_Probability_spinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Mutation_Probability_label;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *Mutation_Probability_spinBox;
    QMenuBar *menubar;
    QMenu *menuTiMO_Genetic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 666);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../png/dna.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionO_Programie = new QAction(MainWindow);
        actionO_Programie->setObjectName(QString::fromUtf8("actionO_Programie"));
        actionInstrukcja = new QAction(MainWindow);
        actionInstrukcja->setObjectName(QString::fromUtf8("actionInstrukcja"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Functions_tableWidget = new QTableWidget(groupBox_2);
        if (Functions_tableWidget->columnCount() < 2)
            Functions_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Functions_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Functions_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (Functions_tableWidget->rowCount() < 1)
            Functions_tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        Functions_tableWidget->setItem(0, 0, __qtablewidgetitem2);
        Functions_tableWidget->setObjectName(QString::fromUtf8("Functions_tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Functions_tableWidget->sizePolicy().hasHeightForWidth());
        Functions_tableWidget->setSizePolicy(sizePolicy);
        Functions_tableWidget->setMinimumSize(QSize(500, 190));
        Functions_tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Functions_tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Functions_tableWidget->setRowCount(1);
        Functions_tableWidget->horizontalHeader()->setVisible(true);
        Functions_tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        Functions_tableWidget->horizontalHeader()->setHighlightSections(true);
        Functions_tableWidget->horizontalHeader()->setStretchLastSection(false);
        Functions_tableWidget->verticalHeader()->setVisible(true);
        Functions_tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        Functions_tableWidget->verticalHeader()->setHighlightSections(true);

        verticalLayout_2->addWidget(Functions_tableWidget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Add_Function_pushButton = new QPushButton(groupBox_2);
        Add_Function_pushButton->setObjectName(QString::fromUtf8("Add_Function_pushButton"));

        horizontalLayout_7->addWidget(Add_Function_pushButton);

        Delete_Function_pushButton = new QPushButton(groupBox_2);
        Delete_Function_pushButton->setObjectName(QString::fromUtf8("Delete_Function_pushButton"));

        horizontalLayout_7->addWidget(Delete_Function_pushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Test_Function_label = new QLabel(groupBox_2);
        Test_Function_label->setObjectName(QString::fromUtf8("Test_Function_label"));
        Test_Function_label->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_5->addWidget(Test_Function_label);

        Test_Function_comboBox = new QComboBox(groupBox_2);
        Test_Function_comboBox->setObjectName(QString::fromUtf8("Test_Function_comboBox"));
        Test_Function_comboBox->setMinimumSize(QSize(200, 0));
        Test_Function_comboBox->setLayoutDirection(Qt::LeftToRight);
        Test_Function_comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_5->addWidget(Test_Function_comboBox);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Variables_tableWidget = new QTableWidget(groupBox_3);
        if (Variables_tableWidget->columnCount() < 3)
            Variables_tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Variables_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Variables_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Variables_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        if (Variables_tableWidget->rowCount() < 1)
            Variables_tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Variables_tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        Variables_tableWidget->setObjectName(QString::fromUtf8("Variables_tableWidget"));
        Variables_tableWidget->setMinimumSize(QSize(500, 190));
        Variables_tableWidget->horizontalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(Variables_tableWidget);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        Add_Variable_pushButton = new QPushButton(groupBox_3);
        Add_Variable_pushButton->setObjectName(QString::fromUtf8("Add_Variable_pushButton"));

        horizontalLayout_8->addWidget(Add_Variable_pushButton);

        Delete_Variable_pushButton = new QPushButton(groupBox_3);
        Delete_Variable_pushButton->setObjectName(QString::fromUtf8("Delete_Variable_pushButton"));

        horizontalLayout_8->addWidget(Delete_Variable_pushButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_8);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        Algorithm_Start_pushButton = new QPushButton(centralwidget);
        Algorithm_Start_pushButton->setObjectName(QString::fromUtf8("Algorithm_Start_pushButton"));
        Algorithm_Start_pushButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(Algorithm_Start_pushButton);


        gridLayout_4->addLayout(horizontalLayout_9, 4, 0, 1, 3);

        horizontalSpacer_10 = new QSpacerItem(20, 226, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 2, 1, 2, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(400, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_10->addWidget(label);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);

        Radius_doubleSpinBox = new QDoubleSpinBox(groupBox);
        Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Radius_doubleSpinBox"));
        Radius_doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(Radius_doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Population_Size_label = new QLabel(groupBox);
        Population_Size_label->setObjectName(QString::fromUtf8("Population_Size_label"));

        horizontalLayout_2->addWidget(Population_Size_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        Population_Size_spinBox = new QSpinBox(groupBox);
        Population_Size_spinBox->setObjectName(QString::fromUtf8("Population_Size_spinBox"));
        Population_Size_spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Population_Size_spinBox->setMinimum(10);
        Population_Size_spinBox->setMaximum(9999);

        horizontalLayout_2->addWidget(Population_Size_spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Max_Population_Number_label = new QLabel(groupBox);
        Max_Population_Number_label->setObjectName(QString::fromUtf8("Max_Population_Number_label"));

        horizontalLayout->addWidget(Max_Population_Number_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Max_Population_Number_spinBox = new QSpinBox(groupBox);
        Max_Population_Number_spinBox->setObjectName(QString::fromUtf8("Max_Population_Number_spinBox"));
        Max_Population_Number_spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Max_Population_Number_spinBox->setMinimum(1);
        Max_Population_Number_spinBox->setMaximum(9999);

        horizontalLayout->addWidget(Max_Population_Number_spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Crossing_Probability_label = new QLabel(groupBox);
        Crossing_Probability_label->setObjectName(QString::fromUtf8("Crossing_Probability_label"));

        horizontalLayout_3->addWidget(Crossing_Probability_label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        Crossing_Probability_spinBox = new QSpinBox(groupBox);
        Crossing_Probability_spinBox->setObjectName(QString::fromUtf8("Crossing_Probability_spinBox"));
        Crossing_Probability_spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Crossing_Probability_spinBox->setMaximum(100);

        horizontalLayout_3->addWidget(Crossing_Probability_spinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Mutation_Probability_label = new QLabel(groupBox);
        Mutation_Probability_label->setObjectName(QString::fromUtf8("Mutation_Probability_label"));

        horizontalLayout_4->addWidget(Mutation_Probability_label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        Mutation_Probability_spinBox = new QSpinBox(groupBox);
        Mutation_Probability_spinBox->setObjectName(QString::fromUtf8("Mutation_Probability_spinBox"));
        Mutation_Probability_spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Mutation_Probability_spinBox->setMaximum(100);

        horizontalLayout_4->addWidget(Mutation_Probability_spinBox);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 919, 22));
        menuTiMO_Genetic = new QMenu(menubar);
        menuTiMO_Genetic->setObjectName(QString::fromUtf8("menuTiMO_Genetic"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuTiMO_Genetic->menuAction());
        menuTiMO_Genetic->addAction(actionO_Programie);
        menuTiMO_Genetic->addAction(actionInstrukcja);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TiMO NSGA", nullptr));
        actionO_Programie->setText(QApplication::translate("MainWindow", "O Programie", nullptr));
        actionInstrukcja->setText(QApplication::translate("MainWindow", "Instrukcja", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Wzory funkcji", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Functions_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "fn(x)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Functions_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Wz\303\263r", nullptr));

        const bool __sortingEnabled = Functions_tableWidget->isSortingEnabled();
        Functions_tableWidget->setSortingEnabled(false);
        Functions_tableWidget->setSortingEnabled(__sortingEnabled);

        Add_Function_pushButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        Delete_Function_pushButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        Test_Function_label->setText(QApplication::translate("MainWindow", "Funkcja:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Przestrze\305\204 poszukiwa\305\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Variables_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "x_n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Variables_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", ">=", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Variables_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "<=", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Variables_tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "1", nullptr));
        Add_Variable_pushButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        Delete_Variable_pushButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        Algorithm_Start_pushButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Parametry algorytmu", nullptr));
        label->setText(QApplication::translate("MainWindow", "Promie\305\204 niszy:", nullptr));
        Population_Size_label->setText(QApplication::translate("MainWindow", "Rozmiar populacji pocz\304\205tkowej:", nullptr));
        Max_Population_Number_label->setText(QApplication::translate("MainWindow", "Maksymalna ilo\305\233\304\207 pokole\305\204:", nullptr));
        Crossing_Probability_label->setText(QApplication::translate("MainWindow", "Prawdopodobie\305\204stwo krzy\305\274owania:", nullptr));
        Mutation_Probability_label->setText(QApplication::translate("MainWindow", "Prawdopodobie\305\204stwo mutacji:", nullptr));
        menuTiMO_Genetic->setTitle(QApplication::translate("MainWindow", "TiMO_Genetic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
