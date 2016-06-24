#include "BossMon.h"


BossMon::BossMon(QGraphicsItem *parent)
{
    flag = 0;
    setPixmap(QPixmap(":/images/bossMon.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);

}
void BossMon::move_down(int fasele)
{
     setPos(x(), y()+30);
}

void BossMon::move()
{
    if (flag == 0)
    {
        setX(x() + 10);
        flag = 1;
    }
    else if (flag == 1)
    {
        setX(x() - 10);
        flag = 0;
    }
}
