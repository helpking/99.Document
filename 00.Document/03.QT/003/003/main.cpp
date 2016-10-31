#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QPushButton *button = new QPushButton(QObject::tr("Quit"));
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();
    return a.exec();
}
