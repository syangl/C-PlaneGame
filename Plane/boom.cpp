#include "boom.h"
#include <QPixmap>
#include "config.h"

boom::boom()
{
   booom.load(BOOOM);

}

void boom::paintbooom()
{
    QPainter paintboom;
    paintboom.drawPixmap(boox, booy, booom);
}
