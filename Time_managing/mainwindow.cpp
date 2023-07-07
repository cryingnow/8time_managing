#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QBoxLayout>
#include <QtGlobal>
#include <QDateTime>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include<QMovie>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<compare.h>
#include<task_edit.h>
#include<alltasks.h>
#include<timerecorder.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->MAINONE=new Alltasks;
#define BUTTON_STYLE "QPushButton{font: 25 12pt '华文宋体';color: rgb(255,255,255);background-color: rgb(120,196,255);" \
                    "border: none;border-radius:5px;}" \
                    "QPushButton:hover{background-color: rgb(22,218,208);}" \
                    "QPushButton:pressed{background-color: rgb(17,171,164);}"
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->timeone->setStyleSheet(BUTTON_STYLE);
    ui->timetwo->setStyleSheet(BUTTON_STYLE);
    ui->timethree->setStyleSheet(BUTTON_STYLE);
    ui->timefour->setStyleSheet(BUTTON_STYLE);
    ui->timefive->setStyleSheet(BUTTON_STYLE);
    ui->timesix->setStyleSheet(BUTTON_STYLE);
    ui->timeseven->setStyleSheet(BUTTON_STYLE);
    ui->timeeight->setStyleSheet(BUTTON_STYLE);
    ui->timenine->setStyleSheet(BUTTON_STYLE);

    QIcon btn_icon;
     btn_icon.addFile(":/new/prefix1/buttons/1.png");
    ui->timeone->setIcon(btn_icon); ui->timeone->setIconSize(QSize(32, 32));
    ui->timetwo->setIcon(btn_icon);ui->timetwo->setIconSize(QSize(32, 32));
    ui->timethree->setIcon(btn_icon);ui->timethree->setIconSize(QSize(32, 32));
    ui->timefour->setIcon(btn_icon); ui->timefour->setIconSize(QSize(32, 32));
    ui->timefive->setIcon(btn_icon);ui->timefive->setIconSize(QSize(32, 32));
    ui->timesix->setIcon(btn_icon);ui->timesix->setIconSize(QSize(32, 32));
    ui->timeseven->setIcon(btn_icon);ui->timeseven->setIconSize(QSize(32, 32));
    ui->timeeight->setIcon(btn_icon); ui->timeeight->setIconSize(QSize(32, 32));
    ui->timenine->setIcon(btn_icon);ui->timenine->setIconSize(QSize(32, 32));

    QIcon bt_icon;
     bt_icon.addFile(":/new/prefix1/buttons/3.png");
     ui->timerecord->setIcon(bt_icon); ui->timerecord->setIconSize(QSize(32, 32));
     ui->changeBackgroundButton->setIcon(bt_icon); ui->changeBackgroundButton->setIconSize(QSize(32, 32));
     ui->changeColorAction->setIcon(bt_icon); ui->changeColorAction->setIconSize(QSize(32, 32));
     ui->fontButton->setIcon(bt_icon); ui->fontButton->setIconSize(QSize(32, 32));
     ui->pushButton->setIcon(bt_icon); ui->pushButton->setIconSize(QSize(32, 32));
     //显示时间
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), SLOT(time_update()));
        timer->start(1000); //1s执行一次,定时器
     //提醒器
        QTimer *remindclock=new QTimer(this);
        connect(remindclock,SIGNAL(timeout()),SLOT(remind_time()));
        remindclock->start(1800000);//每30分钟执行一次，如果需要提醒就提醒
     //用户自定义更换背景图片
     connect(ui->changeBackgroundButton,&QPushButton::clicked,this,&MainWindow::changeBackgroundButton);
     //用户自定义全局字体
//     QPushButton *fontButton=new QPushButton("选择字体",this);
     connect(ui->fontButton,&QPushButton::clicked,this,&MainWindow::fontButton);
     //用户自定义更换背景颜色
       currentBackgroundColor=Qt::white;
       this->setStyleSheet(QString("background-color: %1;").arg(currentBackgroundColor.name()));

       connect(ui->changeColorAction,&QPushButton::clicked,this,&MainWindow::changeColorAction);

      //设置主窗口Title
       QLabel*titleLabel=new QLabel("Time managing",this);
       titleLabel->setAlignment(Qt::AlignCenter);
       QFont font("Jokerman",20,QFont::Bold);
       titleLabel->setFont(font);
       titleLabel->setStyleSheet("color:rgb(0,0,0);");
       titleLabel->setGeometry(200,70,300,50);
//       titleLabel->setGeometry(200,0,300,200);
#undef BUTTON_STYLE


      //动态gif
       QMovie *Movie = new QMovie(":/new/prefix1/gifs/bird1.jpg");   	//从文件中接收gif图
       QLabel *imgLabel = new QLabel(this);					//创建标签
       imgLabel ->setGeometry(390,465,301,220);					//设置标签大小及位置
       imgLabel ->setMovie(Movie);			//将gif图插入标签
       Movie->setScaledSize(imgLabel->size());
       Movie->start();											//播放gif图,否则图片无法显示

       QMovie *Move = new QMovie(":/new/prefix1/gifs/cock1.jpg");   	//从文件中接收gif图
       QLabel *imLabel = new QLabel(this);					//创建标签
       imLabel ->setGeometry(560,20,120,120);					//设置标签大小及位置
       imLabel ->setMovie(Move);			//将gif图插入标签
       Move->setScaledSize(imLabel->size());
       Move->start();											//播放gif图,否则图片
    // 右下角托盘
    this->trayIcon = new QSystemTrayIcon(this);
    this->trayIcon->setIcon(QIcon(":/new/prefix1/icon.ico"));
    this->trayIconMenu = new QMenu(this);
    QAction *action = trayIconMenu->addAction(QStringLiteral("显示软件"));
    connect(action, &QAction::triggered, this ,&MainWindow::show);
    action = trayIconMenu->addAction(QStringLiteral("彻底退出"));
    connect(action, &QAction::triggered, this ,&MainWindow::exit_all);
    trayIcon->setContextMenu(this->trayIconMenu);
    trayIcon->setToolTip(tr("Time_manage"));
    this->trayIcon->show();
    this->setWindowIcon(QIcon(":/new/prefix1/icon.ico"));
}

void MainWindow::fontButton(){
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok){
        this->setFont(font);
        QList<QPushButton*>buttons;
        buttons<<
            ui->timeone<<ui->timetwo<<ui->timethree<<ui->timefour<<
            ui->timefive<<ui->timesix<<ui->timeseven<<ui->timeeight<<ui->timenine<<
            ui->timerecord<<ui->pushButton<<ui->changeBackgroundButton<<ui->fontButton<<ui->changeColorAction;

        for(QPushButton*button: buttons){
            button->setFont(font);
        }
    }
}

void MainWindow::changeColorAction(){
    QColor newColor=QColorDialog::getColor(currentBackgroundColor,this,QStringLiteral("选择背景颜色"));
    if(newColor.isValid()){
        currentBackgroundColor=newColor;
        this->setStyleSheet(QString("background-color: %1;").arg(currentBackgroundColor.name()));
    }
}

void MainWindow::changeBackgroundButton(){
    QString imagePath=QFileDialog::getOpenFileName(this,tr("select background picture"),"",tr("*.png *.jpeg *.jpg"));
    if(!imagePath.isEmpty()){
        QString styleSheet=QString("background-image: url(%1);").arg(imagePath);
        this->setStyleSheet(styleSheet);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
#ifdef Q_OS_MACOS
    if (!event->spontaneous() || !isVisible()) {
        return;
    }
#endif
    trayIcon->showMessage("Time_manage", QStringLiteral("应用程序在此。若想退出，请右键此图标。"), QSystemTrayIcon::Information, 3000);
    this->hide();
    emit save_all();
    event->ignore();
}
void MainWindow::exit_all()
{
    MAINONE->Writefile();
    qApp->quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timeone_clicked()
{
         task_edit *work1=new task_edit(this,MAINONE->allmyplan[1],MAINONE->allmyfinish[1]);
         work1->show();
         MAINONE->Writefile();
}

void MainWindow::on_timetwo_clicked()
{
    task_edit *work2=new task_edit(this,MAINONE->allmyplan[2],MAINONE->allmyfinish[2]);
    work2->show();
    MAINONE->Writefile();
}

void MainWindow::on_timethree_clicked()
{
    task_edit *work3=new task_edit(this,MAINONE->allmyplan[3],MAINONE->allmyfinish[3]);
    work3->show();
    MAINONE->Writefile();
}

void MainWindow::on_timefour_clicked()
{
    task_edit *work4=new task_edit(this,MAINONE->allmyplan[4],MAINONE->allmyfinish[4]);
    work4->show();
    MAINONE->Writefile();
}

void MainWindow::on_timefive_clicked()
{
    task_edit *work5=new task_edit(this,MAINONE->allmyplan[5],MAINONE->allmyfinish[5]);
    work5->show();
    MAINONE->Writefile();
}

void MainWindow::on_timesix_clicked()
{
    task_edit *work6=new task_edit(this,MAINONE->allmyplan[6],MAINONE->allmyfinish[6]);
    work6->show();
    MAINONE->Writefile();
}

void MainWindow::on_timeseven_clicked()
{
    task_edit *work7=new task_edit(this,MAINONE->allmyplan[7],MAINONE->allmyfinish[7]);
    work7->show();
    MAINONE->Writefile();
}

void MainWindow::on_timeeight_clicked()
{
    task_edit *work8=new task_edit(this,MAINONE->allmyplan[8],MAINONE->allmyfinish[8]);
    work8->show();
    MAINONE->Writefile();
}

void MainWindow::on_timenine_clicked()
{
    task_edit *work9=new task_edit(this,MAINONE->allmyplan[9],MAINONE->allmyfinish[9]);
    work9->show();
    MAINONE->Writefile();
}

void MainWindow::on_pushButton_clicked()//这里是计划记录可视化对比的按钮，忘记修改名字了。
{
        Compare *comparewindow=new Compare(this);
        comparewindow->show();
}

void MainWindow::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
        ui->showtime->setText(str);
}

void MainWindow::on_timerecord_clicked()
{
   Timerecorder* time=new Timerecorder;
   time->show();
}
void MainWindow::remind_time()
{
    QTime current_time = QTime::currentTime();
    int hour = current_time.hour();        //当前的小时
    for(int i=1;i<=9;i++)
    {
        if(MAINONE->allmyplan[i]->need_remind==1)
        {
            if(hour==i*2+5)
            {
                //提醒将保持在10秒钟
                 this->trayIcon->showMessage(QStringLiteral("Time managing 提醒"), QStringLiteral("不要忘了 ") +MAINONE->allmyplan[i]->name +QStringLiteral( " 呀！"), QSystemTrayIcon::Information, 10000);
                MAINONE->allmyplan[i]->need_remind=0;
            }
        }
    }
}

