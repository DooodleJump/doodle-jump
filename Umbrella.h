#ifndef UMBRELLA_H
#define UMBRELLA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Board.h"
#include "Award.h"

class Umbrella: public Board{
    Q_OBJECT
public:
   Umbrella(QGraphicsItem * parent=0);
   virtual void setpixmap();

public slots:
   void move();
  // virtual void ability();
};//

#endif // UMBRELLA_H
