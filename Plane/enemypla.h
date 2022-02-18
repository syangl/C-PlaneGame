#ifndef ENEMYPLA_H
#define ENEMYPLA_H
#include <QPixmap>
#include <QRect>
#include "config.h"

class enemypla
{
public:
    enemypla();

    //设置初始坐标位置，加载飞机图片
    QPixmap _enemypla;
    int eplx; int eply;
    int rand = 5;

    //矩形边框
    QRect _ePRect;

};

#endif // ENEMYPLA_H
