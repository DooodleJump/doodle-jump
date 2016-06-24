#ifndef SPRING_H
#define SPRING_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Award.h"

class Spring: public Award{
    Q_OBJECT
public:
   Spring(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};

#endif // SPRING_H
