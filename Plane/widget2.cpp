#include "widget2.h"
#include <QIcon>
#include<QDebug>
#include <QApplication>
#include <widget.h>

widget2::widget2(QWidget *parent) : QWidget(parent)
{
    windowset2();

    QPushButton* GRade = new QPushButton;
    GRade->setParent(this);
    GRade->resize(WIDTH + 2,HIGH + 2);
    GRade->move(-1,-1);
    GRade->setText("GAME OVER");
    GRade->setStyleSheet(" QPushButton{font-family:'华文彩云';font-size:120px;color:rgb(0,0,0,255);}\
                           QPushButton{background-color:rgb(98,182,153)}");

    QPushButton* restart = new QPushButton;
    restart->setParent(this);
    restart->resize(200,100);
    restart->move(150,500);
    restart->setText("重新开始");
    restart->setStyleSheet(" QPushButton{font-family:'华文琥珀';font-size:20px;border-radius:20px;color:rgb(0,0,0,255);}\
                           QPushButton{background-color:rgb(224,223,180)}\
                           QPushButton:hover{background-color:rgb(242,234,147)}");



    connect(restart, &QPushButton::clicked, this, [=]{

        _tryagain();

    });

    QPushButton* _quit = new QPushButton;
    _quit->setParent(this);
    _quit->resize(200, 100);
    _quit->move(450, 500);
    _quit->setText("退出游戏");
    _quit->setStyleSheet(" QPushButton{font-family:'华文琥珀';font-size:20px;border-radius:20px;color:rgb(0,0,0,255);}\
                           QPushButton{background-color:rgb(224,223,180)}\
                           QPushButton:hover{background-color:rgb(242,234,147)}");

    connect(_quit, &QPushButton::clicked, this, [=]{

        QApplication *app2;
        app2->quit();
    });

}

void widget2::_tryagain(){

    emit mysignal();

}


void widget2::windowset2()
{

    setFixedSize(WIDTH,HIGH);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(_ICON));

    QImage _ima;
    _ima.load(OVERGROUND);
    setAutoFillBackground(true);
    QPalette _pal(palette());
    _pal.setBrush(QPalette::Window,QBrush(_ima.scaled(size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(_pal);


}


