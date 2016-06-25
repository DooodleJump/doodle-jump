#ifndef MISSILE_H
#define MISSILE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Award.h"
#include "Board.h"

class Missile: public Board //, public Award
{
    Q_OBJECT

public:
   Missile(QGraphicsItem * parent=0);
   virtual void setpixmap();

public slots:
  // void move();
   //virtual void ability();
};//

#endif // MISSILE_H
