#ifndef SPRINGBOARD_H
#define SPRINGBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Springboard:public QObject,public QGraphicsPixmapItem , public Award{
    Q_OBJECT
public:
   Springboard(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};


#endif // SPRINGBOARD_H
