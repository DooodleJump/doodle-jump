#include "Blueboard.h"


Blueboard::Blueboard(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/board.png"));
}
