#ifndef BLUEMON_H
#define BLUEMON_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"

class Bluemon: public Enemy{
    Q_OBJECT
public:
    Bluemon(QGraphicsItem * parent=0);
public slots:
    void move();
};//

#endif // BLUEMON_H
