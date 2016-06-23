#ifndef UMBRELLA_H
#define UMBRELLA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Award.h"

class Umbrella: public Award{
    Q_OBJECT
public:
   Umbrella(QGraphicsItem * parent=0);
public slots:
   void move();
   virtual void ability();
};

#endif // UMBRELLA_H
