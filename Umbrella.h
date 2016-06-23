#ifndef UMBRELLA_H
#define UMBRELLA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Umbrella:public QObject,public QGraphicsPixmapItem , public Award{
    Q_OBJECT
public:
   Umbrella(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};

#endif // UMBRELLA_H
