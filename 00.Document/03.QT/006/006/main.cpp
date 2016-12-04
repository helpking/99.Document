#include "mainwindow.h"
#include <iostream>
#include <QApplication>

/**
 * \brief 内存申请失败时输出Handler
 */
void outOfMemoryHandler() {
    std::cerr << "Unable to satisfy request for memory!!!\n";
    std::abort();
}

int main(int argc, char *argv[])
{

    // 内存申请失败输出用的Handler设定
    std::set_new_handler(outOfMemoryHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
