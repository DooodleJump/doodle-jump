#include "Fly.h"


Fly::Fly(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bulemon.png"));


}

void Fly::move()
{
     setPos(x(), y()+30);

}

