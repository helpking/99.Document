#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "include/language/languagePackage.h"

#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainUi(new Ui::MainWindow)
{
    // Main UI设置
    this->mainUi->setupUi(this);

    // UI情报初始化
    this->initUiInfo();
}

MainWindow::~MainWindow()
{
    delete this->mainUi;
}

#pragma mark －
#pragma mark UI初始化

/**
 * \brief UI情报初始化
 */
void MainWindow::initUiInfo() {
    // 加载设置信息
    this->loadSettingInfo();
    // 加载UI设定情报
    this->loadUISettingInfo();


}

/**
 * \brief 加载UI设定情报
 */
void MainWindow::loadUISettingInfo() {
    QSettings settings;

    // MainWindow的位置以及尺寸情报保存
    restoreGeometry(settings.value("geometry").toByteArray());

    // ToolBar以及ドック・ウィジェット的位置以及尺寸信息
    restoreState(settings.value("windowState").toByteArray());
}

/**
 * \brief 加载设定情报
 */
void MainWindow::loadSettingInfo() {
    Language::languagePackage::getInstance()->loadLanguagePackage(Language::kTLanguageEnglish);
}
