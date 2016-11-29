#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QSettings>
#include <QAction>
#include <QIcon>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainUi(new Ui::MainWindow)
{
    // 读取设定
    this->readSettings();

    // 创建Actions
    this->createActions();

    // 创建Menus
    this->createMenus();

    mainUi->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mainUi;
}
#pragma mark-
#pragma mark Event Settings

/**
 * \brief 关闭事件
 */
void MainWindow::closeEvent(QCloseEvent* event) {

    // 写入设定
    this->writeSettings();
}

#pragma mark-
#pragma mark Event Settings

/**
 * \brief 写入设定
 */
void MainWindow::writeSettings() {
    QSettings settings;
    // QMainWindow的位置以及尺寸大小
    settings.setValue("geometry", saveGeometry());
    // ツールバー・ドック・ウィジェットの位置以及尺寸大小
    settings.setValue("windowState", saveState());
}

/**
 * \brief 读取设定
 */
void MainWindow::readSettings() {
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

#pragma mark-
#pragma mark UI&Action

/**
 * \brief 创建Actions
 */
void MainWindow::createActions() {

    // 新建文件Action
//    this->newFileAct = new QAction(QIcon("401.png"), tr("&New"), this);
    this->newFileAct = new QAction(tr("&New"), this);
    this->newFileAct->setShortcuts(QKeySequence::New);
    this->newFileAct->setStatusTip(tr("Open a file : 401.png"));

    connect(this->newFileAct, SIGNAL(triggered()), this, SLOT(newFile()));

    // 保存文件Action
    this->saveFileAct = new QAction(tr("Save&As..."), this);
    this->saveFileAct->setShortcuts(QKeySequence::SaveAs);
    this->saveFileAct->setStatusTip(tr("save a file : 401.png"));

    connect(this->saveFileAct, SIGNAL(triggered()), this, SLOT(saveAs()));

}

/**
 * \brief 创建Menus
 */
void MainWindow::createMenus() {
    // 文件菜单
    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(this->newFileAct);
}

#pragma mark-
#pragma mark SIGNAL&SLOT

void MainWindow::newFile() {
    QMessageBox::information(0, "Info", (fileMenu) ? "OK" : "NG");
}

void MainWindow::saveAs() {

}
