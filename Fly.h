#ifndef FLY_H
#define FLY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"

class Fly: public Enemy{
    Q_OBJECT
public:
    Fly(QGraphicsItem * parent=0);
public slots:
    void move();
};
//

#endif // FLY_H
