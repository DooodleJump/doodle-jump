#include "Brownboard.h"

int f = 0;
Brownboard::Brownboard(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/p-brown-1.png"));
    btype = 4;
}

void Brownboard::setpixmap()
{
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(set()));

        timer->start(100);
}

void Brownboard::set()
{
    if (f == 0)
    {
        setPixmap(QPixmap(":/images/p-brown-1.png"));
        f = 1;
    }
    else if (f == 1)
    {
        setPixmap(QPixmap(":/images/p-brown-2.png"));
        f = 2;
    }
    else if (f == 2)
    {
         setPixmap(QPixmap(":/images/p-brown-3.png"));
         f = 3;
    }
    else if (f == 3)
    {
        setPixmap(QPixmap(":/images/p-brown-4.png"));
        f = 4;
    }
    else if (f == 4)
    {
        setPixmap(QPixmap(":/images/p-brown-5.png"));
        f = 5;
    }
    else if (f == 5)
    {
         setPixmap(QPixmap(":/images/p-brown-6.png"));
         f = 0;
    }
}
