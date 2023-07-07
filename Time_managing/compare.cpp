#include "compare.h"
#include "ui_compare.h"
#include <QDateTime>
#include <QPainter>
#include <QFile>
#include <QDir>
#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include<QMessageBox>
#include <QTime>
#include <QDateTime>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>


Compare::Compare(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Compare)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Compare my plan and record");
     setFixedSize(width(),height());
     ui->planName->setText("nothing");
     ui->plandet->setText("nothing");
     ui->recname->setText("nothing");
     ui->recdet->setText("nothing");
     ui->focusTime->setText("nothing");
     ui->reflect->setText("nothing");
     for(int i=1;i<=9;i++){
         allmyplan1[i]=new task();
         allmyfinish1[i]=new task();
     }

     readfile();

     connect(ui->compage, &QPushButton::clicked, [=]() {
         ui->stackedWidget->setCurrentIndex(0);
     });

     connect(ui->listpage, &QPushButton::clicked, [=]() {
         ui->stackedWidget->setCurrentIndex(1);
     });

     connect(ui->recpage, &QPushButton::clicked, [=]() {
         ui->stackedWidget->setCurrentIndex(2);
     });
     ui->compage->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     ui->listpage->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     ui->recpage->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     //ui->chicken_1->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     ui->compage->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     //ui->bird_3->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");
     //ui->sheep_7->setStyleSheet("QPushButton:hover { background-color: rgb(217,252,255); }");


    /*QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), SLOT(time_update()));
     timer->start(1000); //1s执行一次,定时器*/


     /*QDateTime dateTime = QDateTime::currentDateTime(); // 获取当前日期和时间
     int hour = dateTime.time().hour(); // 获取当前时间的小时数
     int ind=(hour-6)/2+1;
     switch(ind){
     case 1:ui->chicken_1->setGeometry(ui->chicken_1->x()-5,ui->chicken_1->y()-5,ui->chicken_1->width()+10,ui->chicken_1->height()+10);
     }*/



}
/*void Compare::timee_update()
{

    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->showtime->setText(str);
}*/
int Compare::currentindex=0;
int Compare::recentindex=0;


Compare::~Compare()
{
    delete ui;
}
//该界面实现（mainwindow类）计划与记录对比可视化
void Compare::readfile(){
    QString relativePath = "taskslist.txt";
    QFileInfo path("taskslist.txt");
    QString absolutePath =path.absoluteFilePath();
    QFile tasks("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskslist.txt");
    tasks.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&tasks);
    in>>allmyplan1[1]->name;
    in>>allmyplan1[1]->content;
    in>>allmyplan1[2]->name;
    in>>allmyplan1[2]->content;
    in>>allmyplan1[3]->name;
    in>>allmyplan1[3]->content;
    in>>allmyplan1[4]->name;
    in>>allmyplan1[4]->content;
    in>>allmyplan1[5]->name;
    in>>allmyplan1[5]->content;
    in>>allmyplan1[6]->name;
    in>>allmyplan1[6]->content;
    in>>allmyplan1[7]->name;
    in>>allmyplan1[7]->content;
    in>>allmyplan1[8]->name;
    in>>allmyplan1[8]->content;
    in>>allmyplan1[9]->name;
    in>>allmyplan1[9]->content;
    in>>allmyfinish1[1]->name;
    in>>allmyfinish1[1]->content;
    in>>allmyfinish1[2]->name;
    in>>allmyfinish1[2]->content;
    in>>allmyfinish1[3]->name;
    in>>allmyfinish1[3]->content;
    in>>allmyfinish1[4]->name;
    in>>allmyfinish1[4]->content;
    in>>allmyfinish1[5]->name;
    in>>allmyfinish1[5]->content;
    in>>allmyfinish1[6]->name;
    in>>allmyfinish1[6]->content;
    in>>allmyfinish1[7]->name;
    in>>allmyfinish1[7]->content;
    in>>allmyfinish1[8]->name;
    in>>allmyfinish1[8]->content;
    in>>allmyfinish1[9]->name;
    in>>allmyfinish1[9]->content;
    tasks.close();
    QString relativePath2 = "taskremind.txt";
    QString absolutePath2 = QDir::currentPath() + QDir::separator() + relativePath2;

    QFile reminding("C:\\Users\\LENOVO\\Desktop\\Time_managing\\taskremind.txt");
    reminding.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream input(&reminding);
    input>>allmyplan1[1]->need_remind>>endl;
    input>>allmyplan1[2]->need_remind>>endl;
    input>>allmyplan1[3]->need_remind>>endl;
    input>>allmyplan1[4]->need_remind>>endl;
    input>>allmyplan1[5]->need_remind>>endl;
    input>>allmyplan1[6]->need_remind>>endl;
    input>>allmyplan1[7]->need_remind>>endl;
    input>>allmyplan1[8]->need_remind>>endl;
    input>>allmyplan1[9]->need_remind>>endl;
    reminding.close();
    QString relativePath3 = "reftime.txt";
    QString absolutePath3 = QDir::currentPath() + QDir::separator() + relativePath3;
    QFile ref("C:\\Users\\LENOVO\\Desktop\\Time_managing\\reftime.txt");
    ref.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inn(&ref);
    inn>>allmyplan1[1]->reflection;
    inn>>allmyplan1[1]->timeusage;
    inn>>allmyplan1[2]->reflection>>endl;
    inn>>allmyplan1[2]->timeusage>>endl;
    inn>>allmyplan1[3]->reflection>>endl;
    inn>>allmyplan1[3]->timeusage>>endl;
    inn>>allmyplan1[4]->reflection>>endl;
    inn>>allmyplan1[4]->timeusage>>endl;
    inn>>allmyplan1[5]->reflection>>endl;
    inn>>allmyplan1[5]->timeusage>>endl;
    inn>>allmyplan1[6]->reflection>>endl;
    inn>>allmyplan1[6]->timeusage>>endl;
    inn>>allmyplan1[7]->reflection>>endl;
    inn>>allmyplan1[7]->timeusage>>endl;
    inn>>allmyplan1[8]->reflection>>endl;
    inn>>allmyplan1[8]->timeusage>>endl;
    inn>>allmyplan1[9]->reflection>>endl;
    inn>>allmyplan1[9]->timeusage>>endl;
    tasks.close();
};
void Compare::write_reftime(){

    QString relativePath = "reftime.txt";
    QString absolutePath = QDir::currentPath() + QDir::separator() + relativePath;
    QFile taskss("C:\\Users\\LENOVO\\Desktop\\Time_managing\\reftime.txt");
    taskss.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&taskss);
    out<<allmyplan1[1]->reflection<<"\n";
    out<<allmyplan1[1]->timeusage<<"\n";
    out<<allmyplan1[2]->reflection<<"\n";
    out<<allmyplan1[2]->timeusage<<"\n";
    out<<allmyplan1[3]->reflection<<"\n";
    out<<allmyplan1[3]->timeusage<<"\n";
    out<<allmyplan1[4]->reflection<<"\n";
    out<<allmyplan1[4]->timeusage<<"\n";
    out<<allmyplan1[5]->reflection<<"\n";
    out<<allmyplan1[5]->timeusage<<"\n";
    out<<allmyplan1[6]->reflection<<"\n";
    out<<allmyplan1[6]->timeusage<<"\n";
    out<<allmyplan1[7]->reflection<<"\n";
    out<<allmyplan1[7]->timeusage<<"\n";
    out<<allmyplan1[8]->reflection<<"\n";
    out<<allmyplan1[8]->timeusage<<"\n";
    out<<allmyplan1[9]->reflection<<"\n";
    out<<allmyplan1[9]->timeusage<<"\n";
    taskss.close();
};

void Compare::timeblock_clicked(int index){
    currentindex=index;
    int ti=6+2*(index-1);
    int t0=ti+2;
    QString cur=QStringLiteral("当前查询中：")+QString::number(ti)+":00-"+QString::number(t0)+":00";
    ui->querytime->setText(cur);
    ui->planName->setText(allmyplan1[index]->name);
    ui->plandet->setText(allmyplan1[index]->content);
    ui->recname->setText(allmyfinish1[index]->name);
    ui->recdet->setText(allmyfinish1[index]->content);
    ui->focusTime->setText(allmyplan1[index]->timeusage);
    ui->reflect->setText(allmyplan1[index]->reflection);//也许有初始化问题

};








void Compare::on_chicken_1_pressed()
{
    ui->chicken_1->setGeometry(ui->chicken_1->x()-5,ui->chicken_1->y()-5,ui->chicken_1->width()+10,ui->chicken_1->height()+10);
    timeblock_clicked(1);
}
void Compare::on_chicken_1_released()
{
    ui->chicken_1->setGeometry(ui->chicken_1->x()+5,ui->chicken_1->y()+5,ui->chicken_1->width()-10,ui->chicken_1->height()-10);
}

void Compare::on_rabbit_2_pressed()
{
    ui->rabbit_2->setGeometry(ui->rabbit_2->x()-5,ui->rabbit_2->y()-5,ui->rabbit_2->width()+10,ui->rabbit_2->height()+10);
    timeblock_clicked(2);
}
void Compare::on_rabbit_2_released()
{
    ui->rabbit_2->setGeometry(ui->rabbit_2->x()+5,ui->rabbit_2->y()+5,ui->rabbit_2->width()-10,ui->rabbit_2->height()-10);
}


void Compare::on_bird_3_pressed()
{
    ui->bird_3->setGeometry(ui->bird_3->x()-5,ui->bird_3->y()-5,ui->bird_3->width()+10,ui->bird_3->height()+10);
    timeblock_clicked(3);
}
void Compare::on_bird_3_released()
{
    ui->bird_3->setGeometry(ui->bird_3->x()+5,ui->bird_3->y()+5,ui->bird_3->width()-10,ui->bird_3->height()-10);
}


void Compare::on_pig_4_pressed()
{
    ui->pig_4->setGeometry(ui->pig_4->x()-5,ui->pig_4->y()-5,ui->pig_4->width()+10,ui->pig_4->height()+10);
    timeblock_clicked(4);
}
void Compare::on_pig_4_released()
{
    ui->pig_4->setGeometry(ui->pig_4->x()+5,ui->pig_4->y()+5,ui->pig_4->width()-10,ui->pig_4->height()-10);
}


void Compare::on_flower_5_pressed()
{
    ui->flower_5->setGeometry(ui->flower_5->x()-5,ui->flower_5->y()-5,ui->flower_5->width()+10,ui->flower_5->height()+10);
    timeblock_clicked(5);
}
void Compare::on_flower_5_released()
{
    ui->flower_5->setGeometry(ui->flower_5->x()+5,ui->flower_5->y()+5,ui->flower_5->width()-10,ui->flower_5->height()-10);
}

void Compare::on_cat_6_pressed()
{
    ui->cat_6->setGeometry(ui->cat_6->x()-5,ui->cat_6->y()-5,ui->cat_6->width()+10,ui->cat_6->height()+10);
    timeblock_clicked(6);
}
void Compare::on_cat_6_released()
{
    ui->cat_6->setGeometry(ui->cat_6->x()+5,ui->cat_6->y()+5,ui->cat_6->width()-10,ui->cat_6->height()-10);
}

void Compare::on_sheep_7_pressed()
{
    ui->sheep_7->setGeometry(ui->sheep_7->x()-5,ui->sheep_7->y()-5,ui->sheep_7->width()+10,ui->sheep_7->height()+10);
    timeblock_clicked(7);
}
void Compare::on_sheep_7_released()
{
    ui->sheep_7->setGeometry(ui->sheep_7->x()+5,ui->sheep_7->y()+5,ui->sheep_7->width()-10,ui->sheep_7->height()-10);
}

void Compare::on_deer_8_pressed()
{
    ui->deer_8->setGeometry(ui->deer_8->x()-5,ui->deer_8->y()-5,ui->deer_8->width()+10,ui->deer_8->height()+10);
    timeblock_clicked(8);
}
void Compare::on_deer_8_released()
{
    ui->deer_8->setGeometry(ui->deer_8->x()+5,ui->deer_8->y()+5,ui->deer_8->width()-10,ui->deer_8->height()-10);
}

void Compare::on_owl_9_pressed()
{
    ui->owl_9->setGeometry(ui->owl_9->x()-5,ui->owl_9->y()-5,ui->owl_9->width()+10,ui->owl_9->height()+10);
    timeblock_clicked(9);
}
void Compare::on_owl_9_released()
{
    ui->owl_9->setGeometry(ui->owl_9->x()+5,ui->owl_9->y()+5,ui->owl_9->width()-10,ui->owl_9->height()-10);
}

void Compare::on_save_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("save");
    msgBox.setText(QStringLiteral("是否保存？"));
    QPushButton *agreeBut = msgBox.addButton(QStringLiteral("确定"), QMessageBox::AcceptRole);
    QPushButton *disagreeBut = msgBox.addButton(QStringLiteral("取消"), QMessageBox::AcceptRole);

    msgBox.exec();
    if (msgBox.clickedButton() == (QAbstractButton*)agreeBut)
    {
        allmyplan1[currentindex]->reflection=ui->reflect->toPlainText();
        allmyplan1[currentindex]->timeusage=ui->focusTime->toPlainText();
        write_reftime();
    }

    if (msgBox.clickedButton() == (QAbstractButton*)disagreeBut)
    {

    }
}

void Compare::on_update_clicked()
{
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser_2->setAlignment(Qt::AlignCenter);
    ui->textBrowser_3->setAlignment(Qt::AlignCenter);
    ui->textBrowser_4->setAlignment(Qt::AlignCenter);
    ui->textBrowser_5->setAlignment(Qt::AlignCenter);
    ui->textBrowser_6->setAlignment(Qt::AlignCenter);
    ui->textBrowser_7->setAlignment(Qt::AlignCenter);
    ui->textBrowser_8->setAlignment(Qt::AlignCenter);
    ui->textBrowser_9->setAlignment(Qt::AlignCenter);


    ui->textBrowser->setText(allmyplan1[1]->name);
    ui->textBrowser_2->setText(allmyplan1[2]->name);
    ui->textBrowser_3->setText(allmyplan1[3]->name);
    ui->textBrowser_4->setText(allmyplan1[4]->name);
    ui->textBrowser_5->setText(allmyplan1[5]->name);
    ui->textBrowser_6->setText(allmyplan1[6]->name);
    ui->textBrowser_7->setText(allmyplan1[7]->name);
    ui->textBrowser_8->setText(allmyplan1[8]->name);
    ui->textBrowser_9->setText(allmyplan1[9]->name);
    ui->textBrowser_10->setText(allmyplan1[1]->content);
    ui->textBrowser_11->setText(allmyplan1[2]->content);
    ui->textBrowser_12->setText(allmyplan1[3]->content);
    ui->textBrowser_13->setText(allmyplan1[4]->content);
    ui->textBrowser_14->setText(allmyplan1[5]->content);
    ui->textBrowser_15->setText(allmyplan1[6]->content);
    ui->textBrowser_16->setText(allmyplan1[7]->content);
    ui->textBrowser_17->setText(allmyplan1[8]->content);
    ui->textBrowser_18->setText(allmyplan1[9]->content);

}

void Compare::on_update_2_clicked()
{
    ui->textBrowser_19->setText(allmyfinish1[1]->content);
    ui->textBrowser_20->setText(allmyfinish1[2]->content);
    ui->textBrowser_21->setText(allmyfinish1[3]->content);
    ui->textBrowser_22->setText(allmyfinish1[4]->content);
    ui->textBrowser_23->setText(allmyfinish1[5]->content);
    ui->textBrowser_24->setText(allmyfinish1[6]->content);
    ui->textBrowser_25->setText(allmyfinish1[7]->content);
    ui->textBrowser_26->setText(allmyfinish1[8]->content);
    ui->textBrowser_27->setText(allmyfinish1[9]->content);
    ui->textBrowser_28->setText(allmyfinish1[1]->name);
    ui->textBrowser_29->setText(allmyfinish1[2]->name);
    ui->textBrowser_30->setText(allmyfinish1[3]->name);
    ui->textBrowser_31->setText(allmyfinish1[4]->name);
    ui->textBrowser_32->setText(allmyfinish1[5]->name);
    ui->textBrowser_33->setText(allmyfinish1[6]->name);
    ui->textBrowser_34->setText(allmyfinish1[7]->name);
    ui->textBrowser_35->setText(allmyfinish1[8]->name);
    ui->textBrowser_36->setText(allmyfinish1[9]->name);

}



