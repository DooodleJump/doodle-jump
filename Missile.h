#ifndef MISSILE_H
#define MISSILE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Missile:public QObject,public QGraphicsPixmapItem , public Award{
    Q_OBJECT
public:
   Missile(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};

#endif // MISSILE_H
