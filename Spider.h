#ifndef SPIDER_H
#define SPIDER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"

class Spider: public Enemy{
    Q_OBJECT
public:
    Spider(QGraphicsItem * parent=0);
    virtual void move_down(int fasele);
public slots:
    void move();
};

//
#endif // SPIDER_H
