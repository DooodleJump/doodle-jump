#include "Bluemon.h"


Bluemon::Bluemon(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bulemon.png"));


}

void Bluemon::move()
{
     setPos(x(), y()+30);

}