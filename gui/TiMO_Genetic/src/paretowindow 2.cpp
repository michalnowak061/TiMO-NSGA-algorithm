#include "paretowindow.h"
#include "ui_paretowindow.h"

ParetoWindow::ParetoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParetoWindow)
{
    ui->setupUi(this);
}

ParetoWindow::~ParetoWindow()
{
    delete ui;
}
