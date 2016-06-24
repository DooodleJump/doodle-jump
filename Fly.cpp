#include "Fly.h"
//

Fly::Fly(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/bulemon.png"));


}

void Fly::move()
{
     setPos(x(), y()+30);

}

