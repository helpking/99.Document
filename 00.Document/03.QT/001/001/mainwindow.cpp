#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    // HTMLタグを使っても、効かれる
    QLabel *label = new QLabel("<font size=\"12px\" color=\"#FF0000\">Hello World.</font>");
    ui->setupUi(this);
    this->setCentralWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}
