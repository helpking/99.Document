#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include/common.h"

// QT
#include <QMainWindow>

// 自定义类型定义
#include "include/ui/ui_types.h"
#include "include/SystemLib/language/languagePackage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

#pragma mark －
#pragma mark UI初始化

private:
    /** \brief mainUi */
    Ui::MainWindow* mainUi;

    /**
     * \brief UI情报初始化
     */
    void initUiInfo();

    /**
     * \brief 加载设定情报
     */
    void loadSettingInfo();

    /**
     * \brief 加载UI设定情报
     */
    void loadUISettingInfo();

    /**
     * \brief 保存UI设定情报
     */
    void saveUISettingInfo();


#pragma mark －
#pragma mark Slots

public slots:

    /**
     * \brief (方法命名规则 on_Action名_triggered())
     */
    /**
     * \brief 打开新文件
     */
    void on_actionNew_triggered();

    /**
     * \brief 追加文件
     */
    void on_actionAdd_triggered();

    /**
     * \brief 打开文件
     */
    void on_actionOpen_triggered();

    /**
     * \brief 保存文件
     */
    void on_actionSaveAs_triggered();

    /**
     * \brief 切换语言
     */
    void on_actionLanguage_triggered();

    /**
     * \brief 帮助
     */
    void on_actionHelp_triggered();


#pragma mark －
#pragma mark Event Setting

private:

    /**
     * \brief 关闭事件
     * \param[in] iEvent 事件
     */
    void closeEvent(QCloseEvent* iEvent);

};

#endif // MAINWINDOW_H
