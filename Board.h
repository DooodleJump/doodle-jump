#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>


class Board : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    int type;
    Board(QGraphicsItem * parent=0);

public slots:
    void move_down(int fasele);

};

#endif // BOARD_H
