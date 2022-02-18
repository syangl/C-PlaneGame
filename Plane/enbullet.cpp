#include "enbullet.h"

enbullet::enbullet()
{
    _ebullet.load(_ENEMYBULLET);

    eblx = -30; ebly = -30;

    _ebRect.setWidth(_ebullet.width()); _ebRect.setHeight(_ebullet.height());
    _ebRect.moveTo(eblx, ebly);


}
