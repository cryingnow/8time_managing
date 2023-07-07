#include "timerecorder.h"
#include "mainwindow.h"
#include<QFile>
#include<QTextStream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(100,100,700,700);
    w.setStyleSheet("QWidget{"
                    "background-image: url(:/new/prefix1/backgrounds/9.png);"
                    "background-repeat: no-repeat;"
                    "background-position: center;"
                    "}"
                    );
    w.show();

//    t.show();
    return a.exec();
}
