#include "bullet.h"
#include "config.h"
#include "myplane.h"

bullet::bullet()
{
    _bullet.load(_MYBULLET);
    blx = (WIDTH - _bullet.width())/2; bly = HIGH - 83 - _bullet.height();

    _bRect.setWidth(_bullet.width());_bRect.setHeight(_bullet.height());
    _bRect.moveTo(blx,bly);

}
