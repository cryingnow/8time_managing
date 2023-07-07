#ifndef TIMERECORDER_H
#define TIMERECORDER_H

#include <QMainWindow>
#include <QString>
#include<QTime>
#include<QMediaPlayer>

namespace Ui {
class Timerecorder;
}

class Timerecorder : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timerecorder(QWidget *parent = nullptr);
    ~Timerecorder();
    int Timelong;//要计时的时长
    QString secsToTime(int s);
    QTimer *timer1;

public slots:
    void time_update(void);
    void daojishi(void);

private slots:
    void on_start_clicked();
    void on_selectAudio_clicked();
    void on_playAudio_clicked();
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    Ui::Timerecorder *ui;
    QString filePath;
    QMediaPlayer *player;
};

#endif // TIMERECORDER_H
