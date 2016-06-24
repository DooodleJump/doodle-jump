#include "Spider.h"


Spider::Spider(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/Spider.png"));


}

void Spider::move()
{
     setPos(x(), y()+30);

}
