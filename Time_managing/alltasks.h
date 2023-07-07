#ifndef ALLTASKS_H
#define ALLTASKS_H
#include<task.h>
#include<QFile>
#include<QTextStream>
class Alltasks
{
public:
    Alltasks();
    task* allmyplan[10];//存放9个时间段的计划情况
    task* allmyfinish[10];//存放9个时间段的完成情况
    //只实现了一天内的情况，在考虑实现导出一天的情况的对比图。
    ~Alltasks();
    void Writefile();
};

#endif // ALLTASKS_H
