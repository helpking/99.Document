#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QSettings>
#include <QAction>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainUi(new Ui::MainWindow)
{

    // 读取设定
    this->readSettings();

    // 主UI设定
    this->mainUi->setupUi(this);

    // 创建Actions
    this->createActions();

    // 创建Menus
    this->createMenus();
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

    /* 初始化File菜单 */
    fileMenu = new QMenu(tr("File"), this);

    QAction* fileOpenAction = new QAction("&Open...", this);

    QAction* fileSaveAction = new QAction("&Save...", this);

    fileMenu->addAction(fileOpenAction);

    fileMenu->addAction(fileSaveAction);
    fileMenu->setLayoutDirection(Qt::LeftToRight);

    /* 初始化Edit菜单 */
    editMenu = new QMenu("&Edit");

    QAction* editCopyAction = editMenu->addAction("&Copy");

    QAction* editCutAction = editMenu->addAction("&Cut");

    editMenu->addAction(editCopyAction);
    editMenu->addAction(editCutAction);

    /* 将菜单添加到菜单栏上 */
    QMenuBar *menuBar = this->menuBar();

    menuBar->addMenu(fileMenu);

    menuBar->addMenu(editMenu);
    // 下拉菜单为向下
    menuBar->setDefaultUp(false);
}

#pragma mark-
#pragma mark SIGNAL&SLOT

void MainWindow::newFile() {
    QMessageBox::information(0, "Info", (fileMenu) ? "OK" : "NG");
}

void MainWindow::saveAs() {

}
