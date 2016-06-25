#ifndef BROWNBOARD_H
#define BROWNBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include "Board.h"

class Brownboard : public Board{//public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Brownboard(QGraphicsItem * parent=0);
    virtual void setpixmap();

public slots:
    void set();
};

//
#endif // BROWNBOARD_H
