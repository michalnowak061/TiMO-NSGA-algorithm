#ifndef PROGRESSWINDOW_H
#define PROGRESSWINDOW_H

#include <QDialog>
#include <QTimer>

#include "ui_progresswindow.h"
#include "paretowindow.h"

namespace Ui {
class ProgressWindow;
}

class ProgressWindow : public QDialog
{
    Q_OBJECT

private:

    QTimer *timer = new QTimer(this);
    int totalNumberOfSeconds;
    int seconds;
    int minutes;
    int hours;

    Population PP;

public:  
    explicit ProgressWindow(QWidget *parent = nullptr);
    ~ProgressWindow();

    Ui::ProgressWindow *ui;

    QString Progress_Time;

public slots:
    void SetProgress(int progress, int t, int T) {

        ui->Progress_progressBar->setValue(progress);
        ui->Actual_Population_Number_label->setNum(t);
        ui->Maximum_Population_Number_label->setNum(T);

        Plot_Graph();
    }

    void SetPreviewPopulation(Population P) {

        PP = P;
    }

    void Time_Update() {

        if( this->isHidden() == false || this->isVisible() == true ) {

            totalNumberOfSeconds++;
            seconds = totalNumberOfSeconds % 60;
            minutes = (totalNumberOfSeconds / 60) % 60;
            hours = (totalNumberOfSeconds / 60 / 60);

            Progress_Time = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0'))
                                               .arg(minutes, 2, 10, QChar('0'))
                                               .arg(seconds, 2, 10, QChar('0'));

            ui->Time_label->setText( Progress_Time );
        }
        else {

            totalNumberOfSeconds = 0;
            ui->Time_label->setText("00:00:00");
        }
    }

    void Plot_Graph() {

        if( this->isHidden() == true ) {

            PP.Population_Clear();
        }


        int size = PP.Population_Get_Size();

        // Load data:
        QVector<double> x( size ), y( size );

        for(int i = 0; i < PP.Population_Get_Size(); ++i) {

            Individual I_Temp = PP.Population_Get_Individual(i);

            x[i] = I_Temp.Goals[0];
            y[i] = I_Temp.Goals[1];
        }

        // create graph and assign data to it:
        ui->Preview_Plot_label->addGraph();
        ui->Preview_Plot_label->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->Preview_Plot_label->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
        ui->Preview_Plot_label->graph(0)->setData(x, y);

        // give the axes some labels:
        ui->Preview_Plot_label->xAxis->setLabel("f1(x)");
        ui->Preview_Plot_label->yAxis->setLabel("f2(x)");

        // set axes ranges, so we see all data:
        ui->Preview_Plot_label->graph(0)->rescaleAxes();
        ui->Preview_Plot_label->replot();
    }

signals:
    void Process_Cancel();
    void Process_Stop();

private slots:
    void on_pushButton_clicked() {

        this->close();
    }

    void closeEvent(QCloseEvent *event) {

        QMessageBox messageBox(QMessageBox::Question,
                                   tr("TiMO_Genetic"),
                                   tr("Czy na pewno chcesz anulować ? \n"),
                                   QMessageBox::Yes | QMessageBox::No);

        messageBox.setButtonText(QMessageBox::Yes, tr("Tak"));
        messageBox.setButtonText(QMessageBox::No,  tr("Nie"));

        if(messageBox.exec() != QMessageBox::Yes) {

            event->ignore();
        }
        else {

            emit Process_Cancel();

            totalNumberOfSeconds = 0;
            ui->Time_label->setText("00:00:00");
        }
    }

    void on_Stop_pushButton_clicked() {

        emit Process_Stop();
    }
};

#endif // PROGRESSWINDOW_H
