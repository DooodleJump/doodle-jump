#ifndef FLY_H
#define FLY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Fly: public QObject,public QGraphicsPixmapItem, public Enemy{
    Q_OBJECT
public:
    Fly(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // FLY_H
