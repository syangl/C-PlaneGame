#include "myplane.h"
#include "config.h"
#include "bullet.h"

MyPlane::MyPlane()
{
    _myplane.load(_MYPLANE);
    plx = (WIDTH - _myplane.width())>>1; ply = (HIGH - _myplane.height());

    _PRect.setWidth(_myplane.width()- 18);_PRect.setHeight(_myplane.height() - 16);
    _PRect.moveTo(plx + 9, ply + 8);


}



