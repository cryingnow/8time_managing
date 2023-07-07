#include "alltasks.h"
#include<QFile>
#include<QTextStream>
#include <QMessageBox>


Alltasks::Alltasks()
{
    QFile tasks("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskslist.txt");
    tasks.open(QIODevice::ReadOnly | QIODevice::Text);
        qint64 fileSize = tasks.size();
        if(fileSize==0)
        {
            for(int i=1;i<=9;i++)
            {
                allmyplan[i]=new task;
                allmyplan[i]->name="nothing";
                allmyplan[i]->content="nothing";
                allmyfinish[i]=new task;
                allmyfinish[i]->name="nothing";
                allmyfinish[i]->content="nothing";
            }
        }
        else
        {
            for(int i=1;i<=9;i++)
            {
                allmyplan[i]=new task;
                allmyfinish[i]=new task;
             }
            int arrayflag=1;//记录现在处理哪个数组
            QString line;
            QTextStream in(&tasks);
            while(!in.atEnd())
            {
                line=in.readLine().trimmed();
                    switch(arrayflag)
                    {
                    case 1:
                        allmyplan[1]->name=line;
                        break;
                    case 2:
                        allmyplan[1]->content=line;
                        break;
                    case 3:
                        allmyplan[2]->name=line;
                        break;
                    case 4:
                        allmyplan[2]->content=line;
                        break;
                    case 5:
                        allmyplan[3]->name=line;
                        break;
                    case 6:
                        allmyplan[3]->content=line;
                        break;
                    case 7:
                        allmyplan[4]->name=line;
                        break;
                    case 8:
                        allmyplan[4]->content=line;
                        break;
                    case 9:
                        allmyplan[5]->name=line;
                        break;
                    case 10:
                        allmyplan[5]->content=line;
                        break;
                    case 11:
                            allmyplan[6]->name=line;
                            break;
                     case 12:
                            allmyplan[6]->content=line;
                            break;
                    case 13:
                        allmyplan[7]->name=line;
                        break;
                    case 14:
                        allmyplan[7]->content=line;
                        break;
                    case 15:
                        allmyplan[8]->name=line;
                        break;
                    case 16:
                        allmyplan[8]->content=line;
                        break;
                    case 17:
                        allmyplan[9]->name=line;
                        break;
                    case 18:
                        allmyplan[9]->content=line;
                        break;
                    case 19:
                        allmyfinish[1]->name=line;
                        break;
                    case 20:
                        allmyfinish[1]->content=line;
                        break;
                    case 21:
                        allmyfinish[2]->name=line;
                        break;
                    case 22:
                        allmyfinish[2]->content=line;
                        break;
                    case 23:
                        allmyfinish[3]->name=line;
                        break;
                    case 24:
                        allmyfinish[3]->content=line;
                        break;
                    case 25:
                        allmyfinish[4]->name=line;
                        break;
                    case 26:
                        allmyfinish[4]->content=line;
                        break;
                    case 27:
                        allmyfinish[5]->name=line;
                        break;
                    case 28:
                        allmyfinish[5]->content=line;
                        break;
                    case 29:
                        allmyfinish[6]->name=line;
                        break;
                    case 30:
                        allmyfinish[6]->content=line;
                        break;
                    case 31:
                        allmyfinish[7]->name=line;
                        break;
                    case 32:
                        allmyfinish[7]->content=line;
                        break;
                    case 33:
                        allmyfinish[8]->name=line;
                        break;
                    case 34:
                        allmyfinish[8]->content=line;
                        break;
                    case 35:
                        allmyfinish[9]->name=line;
                        break;
                    case 36:
                        allmyfinish[9]->content=line;
                        break;
                }
             arrayflag++;
        //注意读取按行，我们存入时也是按照  先存9个plan再存9个record来存储的，读取也这样读就好， 记住36个数据（有点麻烦）
        }
    }
    tasks.close();
    QFile reminding("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskremind.txt");
    reminding.open(QIODevice::ReadOnly | QIODevice::Text);
    int count=1;//记录现在处理哪个数组
    int temp;
    QString num;
    QTextStream login(&reminding);
    while(!login.atEnd())
    {
         num=login.readLine().trimmed();
         temp=num.toInt();
         switch(count)
         {
         case 1:
               allmyplan[1]->need_remind=temp;
               break;
         case 2:
               allmyplan[2]->need_remind=temp;
               break;
         case 3:
               allmyplan[3]->need_remind=temp;
               break;
         case 4:
               allmyplan[4]->need_remind=temp;
               break;
         case 5:
               allmyplan[5]->need_remind=temp;
               break;
         case 6:
               allmyplan[6]->need_remind=temp;
               break;
         case 7:
               allmyplan[7]->need_remind=temp;
               break;
         case 8:
               allmyplan[8]->need_remind=temp;
               break;
         case 9:
               allmyplan[9]->need_remind=temp;
               break;
         }
         count++;
    }
    reminding.close();
}
Alltasks::~Alltasks()
{
     for(int i=1;i<=9;i++)
     {
         delete allmyplan[i];
         delete allmyfinish[i];
     }
}
void Alltasks::Writefile()
{
    QFile tasks("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskslist.txt");
    tasks.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&tasks);
    out<<allmyplan[1]->name<<"\n";
    out<<allmyplan[1]->content<<"\n";
    out<<allmyplan[2]->name<<"\n";
    out<<allmyplan[2]->content<<"\n";
    out<<allmyplan[3]->name<<"\n";
    out<<allmyplan[3]->content<<"\n";
    out<<allmyplan[4]->name<<"\n";
    out<<allmyplan[4]->content<<"\n";
    out<<allmyplan[5]->name<<"\n";
    out<<allmyplan[5]->content<<"\n";
    out<<allmyplan[6]->name<<"\n";
    out<<allmyplan[6]->content<<"\n";
    out<<allmyplan[7]->name<<"\n";
    out<<allmyplan[7]->content<<"\n";
    out<<allmyplan[8]->name<<"\n";
    out<<allmyplan[8]->content<<"\n";
    out<<allmyplan[9]->name<<"\n";
    out<<allmyplan[9]->content<<"\n";
    out<<allmyfinish[1]->name<<"\n";
    out<<allmyfinish[1]->content<<"\n";
    out<<allmyfinish[2]->name<<"\n";
    out<<allmyfinish[2]->content<<"\n";
    out<<allmyfinish[3]->name<<"\n";
    out<<allmyfinish[3]->content<<"\n";
    out<<allmyfinish[4]->name<<"\n";
    out<<allmyfinish[4]->content<<"\n";
    out<<allmyfinish[5]->name<<"\n";
    out<<allmyfinish[5]->content<<"\n";
    out<<allmyfinish[6]->name<<"\n";
    out<<allmyfinish[6]->content<<"\n";
    out<<allmyfinish[7]->name<<"\n";
    out<<allmyfinish[7]->content<<"\n";
    out<<allmyfinish[8]->name<<"\n";
    out<<allmyfinish[8]->content<<"\n";
    out<<allmyfinish[9]->name<<"\n";
    out<<allmyfinish[9]->content<<"\n";
    tasks.close();
    QFile reminding("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskremind.txt");
    reminding.open(QIODevice::WriteOnly | QIODevice::Text);
     QTextStream output(&reminding);
     output<<allmyplan[1]->need_remind<<endl;
     output<<allmyplan[2]->need_remind<<endl;
     output<<allmyplan[3]->need_remind<<endl;
     output<<allmyplan[4]->need_remind<<endl;
     output<<allmyplan[5]->need_remind<<endl;
     output<<allmyplan[6]->need_remind<<endl;
     output<<allmyplan[7]->need_remind<<endl;
     output<<allmyplan[8]->need_remind<<endl;
     output<<allmyplan[9]->need_remind<<endl;
   reminding.close();
}
