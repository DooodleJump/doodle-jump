#include "Fly.h"


Fly::Fly(QGraphicsItem *parent)
{
    flag = 0;
    setPixmap(QPixmap(":/images/bat1.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);
}

void Fly::move_down(int fasele)
{
     setPos(x(), y()+30);
}

void Fly::move()
{
    if (flag == 0)
    {
        setPixmap(QPixmap(":/images/bat2.png"));
        flag = 1;
    }

    else if (flag == 1)
    {
        setPixmap(QPixmap(":/images/bat3.png"));
        flag = 2;
    }

    else if (flag == 2)
    {
        setPixmap(QPixmap(":/images/bat1.png"));
        flag = 0;
    }
}
