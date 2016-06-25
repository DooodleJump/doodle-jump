#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QTimerEvent>
#include <QtEvents>
#include "Enemy.h"
#include "Spider.h"
#include "Fly.h"
#include "BossMon.h"
#include "Bluemon.h"
#include "Game.h"
#include "Board.h"
//
extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(40);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Spider) || typeid(*(colliding_items[i])) == typeid(BossMon) ||
                typeid(*(colliding_items[i])) == typeid(Fly) || typeid(*(colliding_items[i])) == typeid(Bluemon))
        {
            //game->score->increase();

            game->scene->removeItem(colliding_items[i]);
            game->scene->removeItem(this);

            //delete colliding_items[i];
            delete this;

            return;
        }
    }

    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}



