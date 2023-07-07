#ifndef TASK_EDIT_H
#define TASK_EDIT_H

#include <QMainWindow>
#include<task.h>

namespace Ui {
class task_edit;
}

class task_edit : public QMainWindow
{
    Q_OBJECT

public:
    task* mytask;//该界面对应的task，计划的任务记录(name and content)
    task* myfinish;// 完成的任务记录(name and content)
    explicit task_edit(QWidget *parent = nullptr,task *Plan=nullptr,task *Record=nullptr);

    ~task_edit();



private slots:
    void on_complete_clicked();

    void on_sweep_clicked();

public slots:
    void time_update(void);
private:
    Ui::task_edit *ui;
};

#endif // TASK_EDIT_H
