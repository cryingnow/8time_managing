#ifndef TASK_H
#define TASK_H
#pragma once

#include <vector>
#include <functional>
#include <QDebug>
#include <QString>
#include <QVector>


class task
{
public:
    QString name;
    QString content;//任务的名字和内容
    int timenum;//时间段编号（1-9）
    bool is_finish;//此处不予理会，供计划与记录可视化对比用
    int need_remind;//0表示不需要，1表示需要。我定义为int型的主要原因是方便存储到txt中
    QString reflection;
    QString timeusage;
    task();
    ~task();

    friend QDebug operator<< (QDebug debug, const task &tasking);
    friend bool operator== (const task &task1, const task &task2);
};

#endif // TASK_H
