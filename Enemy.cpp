#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include <QTimer>

extern Game * game;

int flag = 0;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Spider.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);
}

void Enemy::move_down(int fasele)
{
    setY(y() + fasele);
}

void Enemy::move()
{
    if (flag == 0)
    {
       setX(x() + 20);
    }
    if(x() > 500)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        setX(x() - 20);
    }
    if (x() < 0)
    {

        flag = 0;
    }
}

