#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <QCloseEvent>
#include <qtconcurrentrun.h>
#include <QFutureWatcher>
#include <QApplication>

#include "progresswindow.h"
#include "paretowindow.h"
#include "qcustomplot.h"

#include "NSGA.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    ProgressWindow *pw;
    ParetoWindow   *paretow;

    // Genetic algortihms variables
    QString Which_Algorithm;
    QFuture<void> Algorithm_Thread;

    QFutureWatcher<void> *watcher;

    Population *P0;
    Population A_NonDom;
    Population A_Dom;

    int n;
    int N;     // <- Population size
    int T;     // <- Max population number
    int t;     // <- Actual population number
    int Pc;
    int Pm;

    double Niche_Radius;

    NSGA nsga; // <- NSGA algorithm instantion

    double Progress;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool A_Cancel;
    bool A_Stop;

signals:
    void Progress_Value_Changed(int progress, int t, int T);
    void Plot_Pareto_Graph();
    void Plot_Preview_Graph(Population P);
    void Function_Value_Error();

private slots:
    void on_Population_Size_spinBox_valueChanged(int arg1);
    void on_Max_Population_Number_spinBox_valueChanged(int arg1);
    void on_Crossing_Probability_spinBox_valueChanged(int arg1);
    void on_Mutation_Probability_spinBox_valueChanged(int arg1);
    void on_Test_Function_comboBox_currentIndexChanged(int index);
    void on_Algorithm_Start_pushButton_clicked();

    void Algorithm_Cancel();
    void Algorithm_Stop();
    void on_Add_Function_pushButton_clicked();
    void on_Delete_Function_pushButton_clicked();
    void on_Add_Variable_pushButton_clicked();
    void on_Delete_Variable_pushButton_clicked();

    void closeEvent(QCloseEvent *event);

    void on_Radius_doubleSpinBox_valueChanged(double arg1);

    void Function_Value_Error_Handle();

public slots:
    void NSGA_Algorithm_Run();
};

#endif // MAINWINDOW_H
