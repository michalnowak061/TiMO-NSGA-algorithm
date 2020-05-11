#ifndef PARETOWINDOW_H
#define PARETOWINDOW_H

#include <QDialog>
#include <QFileDialog>

#include "ui_paretowindow.h"
#include "Population.hpp"

namespace Ui {
class ParetoWindow;
}

class ParetoWindow : public QDialog
{
    Q_OBJECT

private:
    Population A;
    vector<Population> A_List;

    int A_List_Index;

public:
    explicit ParetoWindow(QWidget *parent = nullptr);
    ~ParetoWindow();

public slots:
    void Set_Population(vector<Population> P, QString time) {

        A_List = P;
        ui->Algorithm_Time_label->setText( time );

        A_List_Index = A_List.size() - 1;

        ui->Actual_Step_label->setNum( A_List_Index );
        ui->Max_Step_label->setNum( A_List_Index );
    }

    void Plot_Graph() {

        int size = A_List[A_List_Index].Population_Get_Size();

        // Load data:
        QVector<double> x( size ), y( size );

        for(int i = 0; i < A_List[A_List_Index].Population_Get_Size(); ++i) {

            Individual I_Temp = A_List[A_List_Index].Population_Get_Individual(i);

            x[i] = I_Temp.Goals[0];
            y[i] = I_Temp.Goals[1];
        }

        // create graph and assign data to it:
        ui->ParetoGraph->addGraph();
        ui->ParetoGraph->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->ParetoGraph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
        ui->ParetoGraph->graph(0)->setData(x, y);

        // give the axes some labels:
        ui->ParetoGraph->xAxis->setLabel("f1(x)");
        ui->ParetoGraph->yAxis->setLabel("f2(x)");

        // set axes ranges, so we see all data:
        ui->ParetoGraph->graph(0)->rescaleAxes();
        ui->ParetoGraph->replot();

        this->show();

        ui->NonDom_Count_label->setNum( A_List[A_List_Index].Population_Get_Size() );
    }

private slots:
    void on_Save_pushButton_clicked() {

        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::AnyFile);
        dialog.setViewMode(QFileDialog::Detail);
        dialog.setAcceptMode(QFileDialog::AcceptSave);

        QString fileName = QFileDialog::getSaveFileName( this, tr("Zapisz do pliku"), "", tr("") );
        A_List[A_List_Index].Population_Save_To_File( fileName.toStdString() );
    }

    void on_Previous_Step_pushButton_clicked() {

        A_List_Index = A_List_Index - 1;

        if( A_List_Index <= 0 ) {

            A_List_Index = 0;
        }

        ui->Actual_Step_label->setNum( A_List_Index );
        Plot_Graph();
    }

    void on_Next_Step_pushButton_clicked() {

        A_List_Index = A_List_Index + 1;

        if( A_List_Index >= (int)A_List.size() ) {

            A_List_Index = A_List.size() - 1;
        }

        ui->Actual_Step_label->setNum( A_List_Index );
        Plot_Graph();
    }

private:
    Ui::ParetoWindow *ui;
};

#endif // PARETOWINDOW_H
