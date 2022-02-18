#ifndef MYPLANE_H
#define MYPLANE_H
#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"

class MyPlane
{
public:
    MyPlane();

    //设置初始坐标位置，加载飞机图片
    QPixmap _myplane;
    int plx; int ply;
    //矩形边框
    QRect _PRect;


};

#endif // MYPLANE_H
