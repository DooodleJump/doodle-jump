#ifndef SPRINGBOARD_H
#define SPRINGBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Award.h"

class Springboard: public Award{
    Q_OBJECT
public:
   Springboard(QGraphicsItem * parent=0);
public slots:
   void move();
   virtual void ability();
};


#endif // SPRINGBOARD_H
