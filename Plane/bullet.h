#ifndef BULLET_H
#define BULLET_H
#include <QRect>
#include <QPixmap>
#include "config.h"
#include <QRect>

class bullet
{
public:
    bullet();


    //矩形
    QRect _bRect;
    //坐标，加载图片
    QPixmap _bullet;
    int blx; int bly;

};

#endif // BULLET_H
