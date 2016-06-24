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
    virtual void move_down(int fasele);
public slots:
    void move();
};
//

#endif // FLY_H
