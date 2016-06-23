#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem
{
        Q_OBJECT

    public:
        QTimer* timer;
        Enemy(QGraphicsItem * parent=0);
        void move_down(int fasele);

    public slots:
        void move();
};

#endif // ENEMY_H
