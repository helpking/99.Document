#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设定 Application名
    app.setApplicationName("MyQtApp");
    app.setOrganizationName("MyOrganizetion");

    // 主窗口生成
    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
