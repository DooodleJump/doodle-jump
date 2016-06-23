#ifndef BLUEMON_H
#define BLUEMON_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bluemon: public QObject,public QGraphicsPixmapItem, public Enemy{
    Q_OBJECT
public:
    Bluemon(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BLUEMON_H
