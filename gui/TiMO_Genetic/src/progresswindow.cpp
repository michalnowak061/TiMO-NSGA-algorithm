#include "progresswindow.h"
#include "ui_progresswindow.h"

ProgressWindow::ProgressWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ProgressWindow) {

    ui->setupUi(this);

    totalNumberOfSeconds = 0;

    timer->start(1000);

    connect(timer, SIGNAL( timeout() ), this, SLOT( Time_Update() ) );
}

ProgressWindow::~ProgressWindow() {

    delete ui;
    delete timer;
}
