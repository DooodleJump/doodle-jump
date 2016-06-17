#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Board : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Board(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // BOARD_H
