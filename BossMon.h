#ifndef BOSSMON_H
#define BOSSMON_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"

class BossMon: public Enemy{
    Q_OBJECT
public:
    BossMon(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BOSSMON_H
