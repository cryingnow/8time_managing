#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include <QPushButton>
#include <QPair>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QTimer>
#include <QDateTime>

#include<alltasks.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Alltasks *MAINONE;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;//托盘
    void redraw();//重新显示主界面

protected:
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::MainWindow *ui;
    QColor currentBackgroundColor;
private slots:
    void changeBackgroundButton();
//    void changeBackgroundColor();
    void changeColorAction();
//    void on_fontButton_clicked();

    void exit_all();

    void on_timeone_clicked();

    void on_timetwo_clicked();

    void on_timethree_clicked();

    void on_timefour_clicked();

    void on_timefive_clicked();

    void on_timesix_clicked();

    void on_timeseven_clicked();

    void on_timeeight_clicked();

    void on_timenine_clicked();

    void on_pushButton_clicked();
    void on_timerecord_clicked();

    void fontButton();

public slots:
    void time_update(void);
    void remind_time(void);



signals:
    void save_all();
};
#endif // MAINWINDOW_H
