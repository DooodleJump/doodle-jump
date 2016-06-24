#ifndef SPRING_H
#define SPRING_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Board.h"

class Spring: public Board
{
    Q_OBJECT

public:
   float v_0;
   float g;
   Spring(QGraphicsItem * parent=0);

public slots:
   void move();
};//

#endif // SPRING_H
