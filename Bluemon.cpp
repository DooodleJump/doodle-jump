#include "Bluemon.h"


Bluemon::Bluemon(QGraphicsItem *parent)
{
    flag = 0;
    setPixmap(QPixmap(":/images/Bluemon.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);

}

void Bluemon::move_down(int fasele)
{
     setPos(x(), y() + 30);

}

void Bluemon::move()
{
    if (flag == 0)
    {
        setPos(x() + 20, y() - 20);
        flag = 1;
    }

    else if (flag == 1)
    {
        setPos(x() + 20,y() + 20);
        flag = 0;
    }

    if (x() > 450)
    {
        setX(20);
    }

    if (x() < 10)
    {
         setX(430);
    }
}
