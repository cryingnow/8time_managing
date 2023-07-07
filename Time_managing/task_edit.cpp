#include<QTimer>
#include<QDateTime>
#include<QString>
#include<QMessageBox>
#include<QMovie>

#include "task_edit.h"
#include "ui_task_edit.h"
#include<alltasks.h>
#include<task.h>

task_edit::task_edit(QWidget *parent,task *Plan,task *Record) :
    QMainWindow(parent),
    ui(new Ui::task_edit)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    setWindowTitle("plan and record");

    //动态gif
     QMovie *Movie = new QMovie(":/new/prefix1/gifs/cat3.jpg");   	//从文件中接收gif图
     QLabel *imgLabel = new QLabel(this);					//创建标签
     imgLabel ->setGeometry(490,330,301,300);					//设置标签大小及位置
     imgLabel ->setMovie(Movie);			//将gif图插入标签
     Movie->setScaledSize(imgLabel->size());
     Movie->start();											//播放gif图,否则图片无法显示

     QIcon btn_icon;
      btn_icon.addFile(":/new/prefix1/buttons/2.png");
     ui->complete->setIcon(btn_icon); ui->complete->setIconSize(QSize(32, 32));
     ui->sweep->setIcon(btn_icon); ui->sweep->setIconSize(QSize(32, 32));

    ui->remindput->addItem(QStringLiteral("否"));
    ui->remindput->addItem(QStringLiteral("是"));
    mytask=new task;
    myfinish=new task;
    mytask=Plan;
    myfinish=Record;
    QString text1=mytask->name;
    ui->input_name->setText(text1);
    QString text2=mytask->content;
    ui->input_content->setText(text2);
    QString text3=myfinish->name;
    ui->input_name2->setText(text3);
    QString text4=myfinish->content;
    ui->inputcontent_2->setText(text4);
    ui->remindput->setCurrentIndex(mytask->need_remind);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000); //1s执行一次,定时器
}

task_edit::~task_edit()
{
    delete ui;
    // delete mytask;
    //delete myfinish;
}


void task_edit::on_complete_clicked()
{
    if(ui->input_name->toPlainText().isEmpty()) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Error",QStringLiteral( "事务名不能为空"));
        return;
    }
    else if(ui->input_name->toPlainText().length()>20) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Time managing", QStringLiteral("事务名过长！请输入不超过20个字！"));
        return;
    }
    else if(ui->input_content->toPlainText().length()>100) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Time managing", QStringLiteral("事务描述过长！请输入不超过100个字！"));
        return;
    }
    else if(ui->input_name2->toPlainText().isEmpty()) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Error",QStringLiteral( "事务名不能为空"));
        return;
    }
    else if(ui->input_name2->toPlainText().length()>20) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Time managing", QStringLiteral("事务名过长！请输入不超过20个字！"));
        return;
    }
    else if(ui->inputcontent_2->toPlainText().length()>100) {
        QMessageBox message_box;
        message_box.critical(nullptr, "Time managing", QStringLiteral("事务描述过长！请输入不超过100个字！"));
        return;
    }
    else{
       QMessageBox msgBox;
       msgBox.setWindowTitle("save");
       msgBox.setText(QStringLiteral("是否保存？"));
       QPushButton *agreeBut = msgBox.addButton(QStringLiteral("确定"), QMessageBox::AcceptRole);
        QPushButton *disagreeBut = msgBox.addButton(QStringLiteral("取消"), QMessageBox::AcceptRole);

       msgBox.exec();
       if (msgBox.clickedButton() == (QAbstractButton*)agreeBut)
       {
           QString text1=ui->input_name->toPlainText();
           mytask->name=text1;
           QString text2=ui->input_content->toPlainText();
           mytask->content=text2;
           QString text3=ui->input_name2->toPlainText();
           myfinish->name=text3;
           QString text4=ui->inputcontent_2->toPlainText();
           myfinish->content=text4;
           if(ui->remindput->currentIndex()==0)
               mytask->need_remind=0;
           else
               mytask->need_remind=1;
       }
       if (msgBox.clickedButton() == (QAbstractButton*)disagreeBut)
       {

       }
    }
}

void task_edit::on_sweep_clicked()
{
          QMessageBox msgBox;
          msgBox.setWindowTitle("delete");
          msgBox.setText(QStringLiteral("是否清除？"));
          QPushButton *agreeBut = msgBox.addButton(QStringLiteral("确定"), QMessageBox::AcceptRole);
           QPushButton *disagreeBut = msgBox.addButton(QStringLiteral("取消"), QMessageBox::AcceptRole);
          msgBox.exec();
          if (msgBox.clickedButton() == (QAbstractButton*)agreeBut)
          {
              mytask->name="nothing";
              mytask->content="nothing";
              myfinish->name="nothing";
              myfinish->content="nothing";
              mytask->need_remind=0;
              QString text1=mytask->name;
              ui->input_name->setText(text1);
              QString text2=mytask->content;
              ui->input_content->setText(text2);
              QString text3=myfinish->name;
              ui->input_name2->setText(text3);
              QString text4=myfinish->content;
              ui->inputcontent_2->setText(text4);
              ui->remindput->setCurrentIndex(mytask->need_remind);
          }
          if (msgBox.clickedButton() == (QAbstractButton*)disagreeBut)
          {

          }
}
void task_edit::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
        ui->time_show->setText(str);
}
