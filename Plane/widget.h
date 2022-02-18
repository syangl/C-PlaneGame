#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QIcon>
#include<QTimer>
#include "myplane.h"
#include <QRect>
#include "bullet.h"
#include <QTime>
#include "enemypla.h"
#include <QRandomGenerator>
#include "enbullet.h"
#include "boom.h"
#include "widget2.h"
#include <QPushButton>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


//设置窗口
    void windowset();
//启动游戏

    void play();
//改变坐标
    void updposition();
//刷新屏幕
  //重写绘制事件函数
   MyPlane mpla;
   bullet mybullet1, mybullet2;
   enemypla eplane1, eplane2, eplane3;
   enbullet ebullet1, ebullet2, ebullet3;
    void paintEvent(QPaintEvent *);
  //定时器
    QTimer timer, bullettime;

    void mouseMoveEvent(QMouseEvent *);

    void crash();

    boom bom1, bom2, bom3, mbom;



    widget2 *over = new widget2();



    void _resetposition();

};
#endif // WIDGET_H
