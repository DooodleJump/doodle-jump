#ifndef BROWNBOARD_H
#define BROWNBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Brownboard : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Brownboard(QGraphicsItem * parent=0);

public slots:
    void move();
};


#endif // BROWNBOARD_H
