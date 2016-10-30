#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QFont>
#include <QPaintEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// 描画のため、イベントハンドラ宣言
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);

    QFont font("Arial", 20);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, "Hello, World.");
}

MainWindow::~MainWindow()
{
    delete ui;
}
