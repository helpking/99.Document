#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "include/common.h"
#include "include/SystemLib/language/languagePackage.h"

#include <QSettings>
#include <QTextEdit>
#include <QString>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainUi(new Ui::MainWindow)
{
    // Main UI设置
    this->mainUi->setupUi(this);

    // 解决中文字符乱码问题
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

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

 //   this->mainUi->actionNew
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
 * \brief 保存UI设定情报
 */
void MainWindow::saveUISettingInfo() {
    QSettings settings;

    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
}

/**
 * \brief 加载设定情报
 */
void MainWindow::loadSettingInfo() {
    SystemLib::languagePackage::getInstance()->loadLanguagePackage(SystemLib::kTLanguageEnglish);
}

#pragma mark －
#pragma mark Slots

/**
 * \brief 打开新文件
 */
void MainWindow::on_actionNew_triggered() {
    INFO_LOG("MainWindow::actionNew a");
}

/**
 * \brief 追加文件
 */
void MainWindow::on_actionAdd_triggered() {
    INFO_LOG("MainWindow::actionAdd a");
}

/**
 * \brief 打开文件
 */
void MainWindow::on_actionOpen_triggered() {
    INFO_LOG("MainWindow::actionOpen a");
}

/**
 * \brief 保存文件
 */
void MainWindow::on_actionSaveAs_triggered() {
    INFO_LOG("MainWindow::actionSaveAs a");
}

/**
 * \brief 切换语言
 */
void MainWindow::on_actionLanguage_triggered() {
    INFO_LOG("MainWindow::actionLanguage a");
}

/**
 * \brief 帮助
 */
void MainWindow::on_actionHelp_triggered() {
    INFO_LOG("MainWindow::actionHelp a");
}

#pragma mark －
#pragma mark Event Setting

/**
 * \brief 关闭事件
 * \param[in] iEvent 事件
 */
void MainWindow::closeEvent(QCloseEvent* iEvent) {
    // 保存UI设定情报
    this->saveUISettingInfo();
}
