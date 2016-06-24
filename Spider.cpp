#include "Spider.h"


Spider::Spider(QGraphicsItem *parent)
{
    flag = 0;
    setPixmap(QPixmap(":/images/Spider.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);
}

void Spider::move_down(int fasele)
{
    setY(y() + fasele);
}

void Spider::move()
{
    if (flag == 0)
    {
       setX(x() + 20);
    }
    if(x() > 450)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        setX(x() - 20);
    }
    if (x() < 20)
    {
        flag = 0;
    }

}
