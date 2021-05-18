#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Int24.h"
#include "Int48.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Int48 int48 = 1000;
    Int24 int24 = 100;
    qDebug()<<int48 + int24;
    qDebug()<<int24 + int48;
    qDebug()<<++int24;
    qDebug()<<int24++;
    qDebug()<<int24;
}

MainWindow::~MainWindow()
{
    delete ui;
}

