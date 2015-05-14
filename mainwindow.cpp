#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
// teste 2 3 4
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
