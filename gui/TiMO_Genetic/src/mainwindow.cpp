#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Test_Functions.h"

// -------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    pw = new ProgressWindow();
    paretow = new ParetoWindow();

    srand( (unsigned int)( time(NULL) ) );

    n = 1;
    N = 1000;
    T = 10;
    Pc = 90;
    Pm = 1;

    Niche_Radius = 0.5;

    P0 = new Population;

    Which_Algorithm = "NSGA";

    ui->Functions_tableWidget->setRowCount(0);
    ui->Variables_tableWidget->setRowCount(0);

    ui->Test_Function_comboBox->addItem("Własna");
    ui->Test_Function_comboBox->addItem("Binh and Korn");
    ui->Test_Function_comboBox->addItem("Chankong and Haimes");
    ui->Test_Function_comboBox->addItem("Fonseca-Fleming");
    ui->Test_Function_comboBox->addItem("Test function 4");
    ui->Test_Function_comboBox->addItem("Kursawe");
    ui->Test_Function_comboBox->addItem("Schaffer N.1");
    ui->Test_Function_comboBox->addItem("Poloni's two objective");
    ui->Test_Function_comboBox->addItem("Zitzler-Deb-Thieles N.1");
    ui->Test_Function_comboBox->addItem("Zitzler-Deb-Thieles N.2");
    ui->Test_Function_comboBox->addItem("Zitzler-Deb-Thieles N.3");
    ui->Test_Function_comboBox->addItem("Zitzler-Deb-Thieles N.4");
    ui->Test_Function_comboBox->addItem("Zitzler-Deb-Thieles N.6");
    ui->Test_Function_comboBox->addItem("Osyczka and Kundu");
    ui->Test_Function_comboBox->addItem("CTP1");
    ui->Test_Function_comboBox->addItem("Constr-EX");

    ui->Radius_doubleSpinBox->setValue(Niche_Radius);
    ui->Population_Size_spinBox->setValue(N);
    ui->Max_Population_Number_spinBox->setValue(T);
    ui->Crossing_Probability_spinBox->setValue(Pc);
    ui->Mutation_Probability_spinBox->setValue(Pm);

    connect( this, SIGNAL( Progress_Value_Changed(int, int, int) ), pw, SLOT( SetProgress(int, int, int) ) );
    connect( pw, SIGNAL( Process_Cancel() ), this, SLOT( Algorithm_Cancel() ) );
    connect( pw, SIGNAL( Process_Stop() ), this, SLOT( Algorithm_Stop() ) );
    connect( this, SIGNAL( Plot_Pareto_Graph() ), paretow, SLOT( Plot_Graph() ) );
    connect( this, SIGNAL( Function_Value_Error() ), this, SLOT( Function_Value_Error_Handle() ) );
}

// -------------------------------------------------------------------------

MainWindow::~MainWindow() {

    pw->hide();
    paretow->hide();

    pw->~ProgressWindow();
    paretow->~ParetoWindow();

    delete P0;
    delete ui;
    delete pw;
    delete paretow;
}

// -------------------------------------------------------------------------

void Do_NSGA_Algorithm(MainWindow *mw) {

    mw->NSGA_Algorithm_Run();
}

// -------------------------------------------------------------------------

void MainWindow::on_Population_Size_spinBox_valueChanged(int arg1) {

    N = arg1;
    P0->Population_Set_Parameters(n, N, Pc, Pm);
    on_Test_Function_comboBox_currentIndexChanged( ui->Test_Function_comboBox->currentIndex() );
}

// -------------------------------------------------------------------------

void MainWindow::on_Max_Population_Number_spinBox_valueChanged(int arg1) {

    T = arg1;
    P0->Population_Set_Parameters(n, N, Pc, Pm);
    on_Test_Function_comboBox_currentIndexChanged( ui->Test_Function_comboBox->currentIndex() );
}

// -------------------------------------------------------------------------

void MainWindow::on_Crossing_Probability_spinBox_valueChanged(int arg1) {

    Pc = arg1;
    P0->Population_Set_Parameters(n, N, Pc, Pm);
    on_Test_Function_comboBox_currentIndexChanged( ui->Test_Function_comboBox->currentIndex() );
}

// -------------------------------------------------------------------------

void MainWindow::on_Mutation_Probability_spinBox_valueChanged(int arg1) {

    Pm = arg1;
    P0->Population_Set_Parameters(n, N, Pc, Pm);
    on_Test_Function_comboBox_currentIndexChanged( ui->Test_Function_comboBox->currentIndex() );
}

// -------------------------------------------------------------------------

void MainWindow::on_Test_Function_comboBox_currentIndexChanged(int index) {

    if(index == 0) {

        ui->Functions_tableWidget->setEditTriggers( QAbstractItemView::AllEditTriggers );
        ui->Variables_tableWidget->setEditTriggers( QAbstractItemView::AllEditTriggers );

        ui->Add_Function_pushButton->setEnabled(true);
        ui->Add_Variable_pushButton->setEnabled(true);

        ui->Delete_Function_pushButton->setEnabled(true);
        ui->Delete_Variable_pushButton->setEnabled(true);

        return;
    }
    else {

        delete P0;
        P0 = new Population;

        ui->Functions_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        ui->Variables_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );

        ui->Add_Function_pushButton->setEnabled(false);
        ui->Add_Variable_pushButton->setEnabled(false);

        ui->Delete_Function_pushButton->setEnabled(false);
        ui->Delete_Variable_pushButton->setEnabled(false);
    }

    switch(index) {

        case 0:
            break;

        case 1:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_Binh_Korn_Function(P0);
            break;

        case 2:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_Chankong_Haimes_Function(P0);
            break;

        case 3:
            n = 3;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Fonseca_Fleming_Function(P0, n);
            break;

        case 4:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_Test_Function_4(P0);
            break;

        case 5:
            n = 3;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Kursawe_Function(P0);
            break;

        case 6:
            n = 1;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Schaffers_N1_Function(P0);
            break;

        case 7:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Polonis_Function(P0);
            break;

        case 8:
            n = 30;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Zitzler_Deb_Thieles_Function_N1(P0);
            break;

        case 9:
            n = 30;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Zitzler_Deb_Thieles_Function_N2(P0);
            break;

        case 10:
            n = 30;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Zitzler_Deb_Thieles_Function_N3(P0);
            break;

        case 11:
            n = 10;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Zitzler_Deb_Thieles_Function_N4(P0);
            break;

        case 12:
            n = 10;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Zitzler_Deb_Thieles_Function_N6(P0);
            break;

        case 13:
            n = 6;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_Osyczka_Kundu_Function(P0);
            break;

        case 14:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_CTP1_Function(P0);
            break;

        case 15:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Set_Constr_EX_Function(P0);
            break;

        case 16:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Muratas_Function(P0);
            break;

        case 17:
            n = 2;
            P0->Population_Set_Parameters(n, N, Pc, Pm);
            Population_Set_Viennet_Function(P0);
            break;
    }

    ui->Functions_tableWidget->setRowCount(0);
    ui->Variables_tableWidget->setRowCount(0);

    for(int i = 0; i < P0->Population_Get_Goal_Functions_Number(); ++i) {

        on_Add_Function_pushButton_clicked();

        QTableWidgetItem *f = new QTableWidgetItem;

        f->setText(  QString::fromStdString( P0->Population_Get_Goal_Function(i) ) );
        ui->Functions_tableWidget->setItem(i, 1, f);
    }

    for(int i = 0; i < n; ++i) {

        on_Add_Variable_pushButton_clicked();

        QTableWidgetItem *x   = new QTableWidgetItem;
        QTableWidgetItem *min = new QTableWidgetItem;
        QTableWidgetItem *max = new QTableWidgetItem;

        x->setText( QString::fromStdString( "x" + to_string(i+1) ) );
        min->setText( QString::fromStdString( to_string( P0->Get_Search_Domain_MIN()[i] ) ) );
        max->setText( QString::fromStdString( to_string( P0->Get_Search_Domain_MAX()[i] ) ) );

        ui->Variables_tableWidget->setItem(i, 0, x);
        ui->Variables_tableWidget->setItem(i, 1, min);
        ui->Variables_tableWidget->setItem(i, 2, max);
    }

    ui->Functions_tableWidget->resizeColumnsToContents();
    ui->Variables_tableWidget->resizeColumnsToContents();
}

// -------------------------------------------------------------------------

void MainWindow::NSGA_Algorithm_Run() {

    t = 0;

    nsga.NSGA_Set_Population0(*P0);
    nsga.NSGA_Set_Niche_Radius(Niche_Radius);

    pw->SetPreviewPopulation( nsga.NSGA_Get_Population_List()[0] );
    emit Progress_Value_Changed( 0, 0, 0 );

    ui->Algorithm_Start_pushButton->setEnabled(false);

    while( t < T && A_Cancel != true ) {

        nsga.NSGA_Algorithm();
        //nsga.NSGA_Get_Actual_Population().Population_Print();

        for(int i = 0; i < nsga.NSGA_Get_Actual_Population().Population_Get_Goal_Functions_Number(); ++i) {

            if( isnan( nsga.NSGA_Get_Actual_Population().Population_Get_Individual(0).Goals[i] ) ) {

                pw->hide();
                this->setEnabled(true);
                ui->Algorithm_Start_pushButton->setEnabled(true);

                emit Function_Value_Error();
                return;
            }
        }

        Progress = double(++t) / double(T) * 100;

        pw->SetPreviewPopulation( nsga.NSGA_Get_Population_List().back() );
        emit Progress_Value_Changed( (int)Progress, (int)t, (int)T );
    }

    ui->Algorithm_Start_pushButton->setEnabled(true);

    if( A_Cancel != true ) {

        A_NonDom = nsga.NSGA_Get_NonDom();
        A_Dom    = nsga.NSGA_Get_Dom();

        pw->hide();
        this->setEnabled(true);

        vector<Population> Temp_List = nsga.NSGA_Get_Population_List();
        Temp_List.push_back( A_NonDom );

        paretow->Set_Population( Temp_List , pw->Progress_Time);
        emit Plot_Pareto_Graph();
    }

    A_Cancel = false;
}

// -------------------------------------------------------------------------

void MainWindow::on_Algorithm_Start_pushButton_clicked() {

    // Functions table error handling
    if( ui->Functions_tableWidget->rowCount() == 0 ) {

        QMessageBox messageBox(QMessageBox::Information,
                                   tr("TiMO NSGA"),
                                   tr("PUSTA TABELA \"Wzory funkcji\" ! \n"
                                      "Wprowadź co najmniej jeden wzór funkcji."),
                                   QMessageBox::Ok);

        if(messageBox.exec() == QMessageBox::Ok) {

            return;
        }

        return;
    }
    else {

        for(int i = 0; i < ui->Functions_tableWidget->rowCount(); ++i) {

            if( ui->Functions_tableWidget->item(i, 1) == NULL || ui->Functions_tableWidget->item(i, 1)->text().isEmpty() == true ) {

                QTableWidgetItem *item = new QTableWidgetItem;

                ui->Functions_tableWidget->setItem(i, 1, item);
                ui->Functions_tableWidget->item(i, 1)->setBackgroundColor( QColor(220,20,60) );

                QMessageBox messageBox(QMessageBox::Information,
                                           tr("TiMO NSGA"),
                                           tr("PUSTY WIERSZ W TABELI \"Wzory funkcji\" ! \n"
                                              "Usuń pusty wiersz lub wprowadź wzór funkcji."),
                                           QMessageBox::Ok);

                if(messageBox.exec() == QMessageBox::Ok) {

                    ui->Functions_tableWidget->item(i, 1)->setBackgroundColor( QColor(30,30,30) );

                    delete item;
                    return;
                }

                return;
            }
        }
    }

    // Variables table error handling
    if( ui->Variables_tableWidget->rowCount() == 0 ) {

        QMessageBox messageBox(QMessageBox::Information,
                                   tr("TiMO NSGA"),
                                   tr("PUSTA TABELA \"Przestrzeń poszukiwań\" ! \n"
                                      "Uzupełnij tabelę przedziałami zmiennych występujących we wzorach funkcji."),
                                   QMessageBox::Ok);

        if(messageBox.exec() == QMessageBox::Ok) {

            return;
        }

        return;
    }
    else {
        for(int i = 0; i < ui->Variables_tableWidget->rowCount(); ++i) {

            for(int j = 0; j < ui->Variables_tableWidget->columnCount(); ++j) {

                if( ui->Variables_tableWidget->item(i, j) == NULL || ui->Variables_tableWidget->item(i, j)->text().isEmpty() ) {

                    QTableWidgetItem *item = new QTableWidgetItem;

                    ui->Variables_tableWidget->setItem(i, j, item);
                    ui->Variables_tableWidget->item(i, j)->setBackgroundColor( QColor(220,20,60) );

                    QMessageBox messageBox(QMessageBox::Information,
                                               tr("TiMO NSGA"),
                                               tr("PUSTA KOMÓRKA W TABELI \"Przestrzeń poszukiwań\" ! \n"
                                                  "Wprowadź brakujący element lub usuń cały wiersz."),
                                               QMessageBox::Ok);

                    if(messageBox.exec() == QMessageBox::Ok) {

                        ui->Variables_tableWidget->item(i, j)->setBackgroundColor( QColor(30,30,30) );

                        delete item;
                        return;
                    }

                    return;
                }
            }

            if( ui->Variables_tableWidget->item(i, 1)->text().toDouble() > ui->Variables_tableWidget->item(i, 2)->text().toDouble()  ) {

                ui->Variables_tableWidget->item(i, 0)->setBackgroundColor( QColor(220,20,60) );
                ui->Variables_tableWidget->item(i, 1)->setBackgroundColor( QColor(220,20,60) );
                ui->Variables_tableWidget->item(i, 2)->setBackgroundColor( QColor(220,20,60) );

                QMessageBox messageBox(QMessageBox::Information,
                                           tr("TiMO NSGA"),
                                           tr("NIEPOPRAWNY PRZEDZIAŁ W TABELI \"Przestrzeń poszukiwań\" ! \n"
                                              "Wprowadź dwie liczby, tak aby pierwsza z nich była mniejsza od drugiej"),
                                           QMessageBox::Ok);

                if(messageBox.exec() == QMessageBox::Ok) {

                    ui->Variables_tableWidget->item(i, 0)->setBackgroundColor( QColor(30,30,30) );
                    ui->Variables_tableWidget->item(i, 1)->setBackgroundColor( QColor(30,30,30) );
                    ui->Variables_tableWidget->item(i, 2)->setBackgroundColor( QColor(30,30,30) );

                    return;
                }

                return;
            }
        }
    }

    A_Cancel = false;

    if( ui->Test_Function_comboBox->currentIndex() == 0 ) {

        delete P0;
        P0 = new Population;

        n = ui->Variables_tableWidget->rowCount();
        P0->Population_Set_Parameters(n, N, Pc, Pm);

        int Functions_Number = ui->Functions_tableWidget->rowCount();

        for(int i = 0; i < Functions_Number; ++i) {

            QTableWidgetItem* itm = ui->Functions_tableWidget->item(i, 1);
            string function = itm->text().toStdString();

            P0->Population_Set_Goal_Function( function );
        }

        double init_min = numeric_limits<double>::max();
        double init_max = numeric_limits<double>::min();

        for(int i = 0; i < n; ++i) {

            QTableWidgetItem* itm1 = ui->Variables_tableWidget->item(i, 1);
            double min = itm1->text().toDouble();

            QTableWidgetItem* itm2 = ui->Variables_tableWidget->item(i, 2);
            double max = itm2->text().toDouble();

            P0->Population_Set_Search_Domain(min, max);

            if( min <= init_min ) {

                init_min = min;
            }

            if( max >= init_max ) {

                init_max = max;
            }
        }

        P0->Population_Initialization(init_min, init_max);
    }

    Algorithm_Thread = QtConcurrent::run( Do_NSGA_Algorithm, this );

    this->setDisabled(true);

    pw->SetProgress(0,0,T);
    pw->show();
}

// -------------------------------------------------------------------------

void MainWindow::Algorithm_Cancel() {

    A_Cancel = true;
    this->setEnabled(true);
}

// -------------------------------------------------------------------------

void MainWindow::Algorithm_Stop() {

    vector<Population> Temp_List = nsga.NSGA_Get_Population_List();

    Population Non_Dom = Temp_List[ Temp_List.size() - 1 ].Population_Delete_Return_NonDom();
    Temp_List.push_back( Non_Dom );

    paretow->Set_Population( Temp_List , pw->Progress_Time);
    emit Plot_Pareto_Graph();
}

// -------------------------------------------------------------------------

void MainWindow::on_Add_Function_pushButton_clicked() {

    int Actual_Row_Number = ui->Functions_tableWidget->rowCount();
    ui->Functions_tableWidget->insertRow( Actual_Row_Number );

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText( QString::fromStdString( "f" + to_string( Actual_Row_Number + 1 ) + "(x)" ) );
    ui->Functions_tableWidget->setItem(Actual_Row_Number, 0, item);
}

// -------------------------------------------------------------------------

void MainWindow::on_Delete_Function_pushButton_clicked()
{
    int Actual_Row_Number = ui->Functions_tableWidget->currentRow();
    ui->Functions_tableWidget->removeRow( Actual_Row_Number );
}

// -------------------------------------------------------------------------

void MainWindow::on_Add_Variable_pushButton_clicked()
{
    int Actual_Row_Number = ui->Variables_tableWidget->rowCount();
    ui->Variables_tableWidget->insertRow( Actual_Row_Number );

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText( QString::fromStdString( "x" + to_string( Actual_Row_Number + 1 ) ) );
    ui->Variables_tableWidget->setItem(Actual_Row_Number, 0, item);
}

// -------------------------------------------------------------------------

void MainWindow::on_Delete_Variable_pushButton_clicked()
{
    int Actual_Row_Number = ui->Variables_tableWidget->currentRow();
    ui->Variables_tableWidget->removeRow( Actual_Row_Number );
}

// -------------------------------------------------------------------------

void MainWindow::closeEvent(QCloseEvent *event) {

    QMessageBox messageBox(QMessageBox::Question,
                               tr("TiMO NSGA"),
                               tr("Czy na pewno chcesz zakończyć ? \n"),
                               QMessageBox::Yes | QMessageBox::No);

    messageBox.setButtonText(QMessageBox::Yes, tr("Tak"));
    messageBox.setButtonText(QMessageBox::No,  tr("Nie"));

    if(messageBox.exec() != QMessageBox::Yes) {

        event->ignore();
    }
    else {

        Algorithm_Thread.cancel();
        QApplication::quit();
    }
}

// -------------------------------------------------------------------------

void MainWindow::on_Radius_doubleSpinBox_valueChanged(double arg1) {

    Niche_Radius = arg1;
}

// -------------------------------------------------------------------------

void MainWindow::Function_Value_Error_Handle(){

    QMessageBox messageBox(QMessageBox::Information,
                           tr("TiMO NSGA"),
                           tr("BRAK MOŻLIWOŚCI WYZNACZENIA WARTOŚCI FUNKCJI !\n"
                              "Sprawdź poprawność wprowadzonych wzorów, oraz to czy zostały zdefiniowane"
                              "zakresy wartości wszystkich zmiennych w nich wystepujących."),
                           QMessageBox::Ok);

    if(messageBox.exec() == QMessageBox::Ok) {

    }
}

// -------------------------------------------------------------------------
