#include "timerecorder.h"
#include "ui_timerecorder.h"

#include<QDateTime>
#include<QTimer>
#include<QComboBox>
#include<QDebug>
#include<QObject>
#include<QMessageBox>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QDebug>
#include<QMovie>

Timerecorder::Timerecorder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timerecorder)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
//    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
//    Timerecorder t;
     setWindowTitle(QStringLiteral("计时学习"));
    this->setStyleSheet("QWidget{"
                    "background-image: url(:/new/prefix1/backgrounds/9.png);"
                    "background-repeat: no-repeat;"
                    "background-position: center;"
                    "}"
                    );
     //动态gif
      QMovie *Movie = new QMovie(":/new/prefix1/gifs/cat5.jpg");   	//从文件中接收gif图
      QLabel *imgLabel = new QLabel(this);					//创建标签
      imgLabel ->setGeometry(480,130,260,233);					//设置标签大小及位置
      imgLabel ->setMovie(Movie);			//将gif图插入标签
      Movie->setScaledSize(imgLabel->size());
      Movie->start();	//播放gif图,否则图片无法显示

      QIcon btn_icon;
       btn_icon.addFile(":/new/prefix1/buttons/4.png");
      ui->playAudioButton->setIcon(btn_icon); ui->playAudioButton->setIconSize(QSize(32, 32));
       ui->selectAudioButton->setIcon(btn_icon); ui->selectAudioButton->setIconSize(QSize(32, 32));
       ui->start->setIcon(btn_icon); ui->start->setIconSize(QSize(32, 32));
    ui->Timechoose->addItem("30");
     ui->Timechoose->addItem("60");
      ui->Timechoose->addItem("90");
      ui->Timechoose->addItem("120");
       ui->Timechoose->addItem("150");
        ui->Timechoose->addItem("180");

    Timelong=30;//如果没有确定的话，默认30秒
    timer1=nullptr;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000); //1s执行一次,定时器

    player=new QMediaPlayer(this);
    connect(ui->selectAudioButton,&QPushButton::clicked,this,&Timerecorder::on_selectAudio_clicked);
    connect(ui->playAudioButton,&QPushButton::clicked,this,&Timerecorder::on_playAudio_clicked);
    connect(player,&QMediaPlayer::mediaStatusChanged,this,&Timerecorder::onMediaStatusChanged);
}

Timerecorder::~Timerecorder()
{
    if(timer1!=nullptr)
        delete timer1;
    delete ui;
}
void Timerecorder::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
        ui->showtime->setText(str);
}

QString Timerecorder::secsToTime(int s)
{
    int h=0,m=0;
    h=s/3600;
    s%=3600;
    m=s/60;
    s%=60;
    QString str=QString::number(h)+":"+QString::number(m)+":"+QString::number(s);
    return str;
}


void Timerecorder:: onMediaStatusChanged(QMediaPlayer::MediaStatus status){
    if(status==QMediaPlayer::EndOfMedia){
        player->setPosition(0);
        player->play();
    }
}

void Timerecorder::on_selectAudio_clicked(){
    Timerecorder::filePath=QFileDialog::getOpenFileName(this,"选择音频文件","",tr("*.mp3 *.wav"));
}


void Timerecorder::on_playAudio_clicked(){
    /*QMediaPlayer player=new QMediaPlayer (this);*/
//    QString filePath="";
    if(filePath.isEmpty())
        QMessageBox::warning(this,"Oops","Please choose a mp3/wav file");
   else{
        qDebug()<<filePath;
    player->setMedia(QUrl::fromLocalFile(filePath));
//    player->setMedia(QUrl::fromLocalFile("C:\\Users\\LENOVO\\Desktop\\Time_managing\\river.mp3"));
    player->play();
    }
}

void Timerecorder::on_start_clicked()
{
    Timelong=ui->Timechoose->currentIndex()*30+30;
    Timelong*=60;
    timer1=new QTimer(this);
    timer1->setInterval(1000);//间隔是1s
    connect(timer1,SIGNAL(timeout()),SLOT(daojishi()));
    timer1->start();
}

void Timerecorder::daojishi()
{
    if(Timelong>=0)
    {
        Timelong--;
        ui->lasttime->setText(secsToTime(Timelong));
    }
    else
    {
        QMessageBox message_box;
        message_box.critical(nullptr, QStringLiteral("计时器"),QStringLiteral( "时间到！你已经专注了")+(ui->Timechoose->currentIndex()*30+30)+QStringLiteral("分钟啦！"));
       timer1->stop();
       delete timer1;
    }
}
