#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QDial>
//#include <QtGui>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QSpinBox* spinBox = new QSpinBox();
    QDial* dial = new QDial();

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
    QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    spinBox->show();
    dial->show();

    return a.exec();
}
