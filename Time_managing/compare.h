#ifndef COMPARE_H
#define COMPARE_H

#include <QMainWindow>
#include<task.h>
#include "ui_compare.h"



namespace Ui {
class Compare;
}

class Compare : public QMainWindow
{
    Q_OBJECT

public:
    explicit Compare(QWidget *parent = nullptr);
    ~Compare();
    static int currentindex;
    static int recentindex;

private:
    Ui::Compare *ui;
public:
    task* allmyplan1[10];//存放9个时间段的计划情况
    task* allmyfinish1[10];//存放9个时间段的完成情况
    void readfile();
    void write_reftime();


private slots:
    void timeblock_clicked(int index);



    void on_save_clicked();

    void on_update_clicked();
    void on_update_2_clicked();
    void on_chicken_1_released();
    void on_chicken_1_pressed();
    void on_rabbit_2_pressed();
    void on_rabbit_2_released();
    void on_bird_3_pressed();
    void on_bird_3_released();
    void on_pig_4_pressed();
    void on_pig_4_released();
    void on_flower_5_pressed();
    void on_flower_5_released();
    void on_cat_6_pressed();
    void on_cat_6_released();
    void on_sheep_7_pressed();
    void on_sheep_7_released();
    void on_deer_8_pressed();
    void on_deer_8_released();
    void on_owl_9_pressed();
    void on_owl_9_released();

};
#endif // COMPARE_H



