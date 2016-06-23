#ifndef SPRING_H
#define SPRING_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Spring:public QObject,public QGraphicsPixmapItem , public Award{
    Q_OBJECT
public:
   Spring(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};

#endif // SPRING_H
