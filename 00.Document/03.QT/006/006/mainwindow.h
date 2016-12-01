#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include/common.h"

// QT
#include <QMainWindow>

// 自定义类型定义
#include "include/memory_check.h"
#include "include/ui/ui_types.h"
#include "include/language/languagePackage.h"

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

};

#endif // MAINWINDOW_H
