#include "enemypla.h"
#include "config.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QString>

enemypla::enemypla()
{
    _enemypla.load(_ENEMY);

    eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1); eply = 0;

    _ePRect.setWidth(_enemypla.width()); _ePRect.setHeight(_enemypla.height());
    _ePRect.moveTo(eplx,eply);
}
