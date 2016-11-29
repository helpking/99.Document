#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
class QAction;
class QMenu;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

#pragma mark-
#pragma mark Event Settings

private:
    /**
     * \brief 关闭事件
     */
    void closeEvent(QCloseEvent* event);

#pragma mark-
#pragma mark Settings

private:

    /**
     * \brief 写入设定
     */
    void writeSettings();

    /**
     * \brief 读取设定
     */
    void readSettings();

#pragma mark-
#pragma mark UI&Action

private:

    /** \brief 主UI */
    Ui::MainWindow* mainUi;
    /** \brief 新建文件Action */
    QAction* newFileAct;
    /** \brief 打开文件Action */
    QAction* openFileAct;
    /** \brief 保存文件Action */
    QAction* saveFileAct;

    /** \brief 文件菜单 */
    QMenu* fileMenu;
    /** \brief 编辑菜单 */
    QMenu* editMenu;

    /**
     * \brief 创建Actions
     */
    void createActions();


    /**
     * \brief 创建Menus
     */
    void createMenus();

#pragma mark-
#pragma mark SIGNAL&SLOT

public Q_SLOTS:
    void newFile();
    void saveAs();

};

#endif // MAINWINDOW_H
