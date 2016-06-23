#ifndef AWARD_H
#define AWARD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Award: public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    Award(QGraphicsItem * parent=0);
public slots:
    void move();
    virtual void ability() = 0;
};

#endif // AWARD_H
