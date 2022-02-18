#ifndef ENBULLET_H
#define ENBULLET_H
#include <QRect>
#include <QPixmap>
#include "config.h"
#include <QRect>
#include "enemypla.h"

class enbullet
{
public:
    enbullet();
    QRect _ebRect;
    //坐标，加载图片
    QPixmap _ebullet;
    int eblx; int ebly;

    int flag = 0;

    int rand = 5;

};

#endif // ENBULLET_H
