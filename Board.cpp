#include "Board.h"

Board::Board(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/board.png"));

//    QTimer * timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

//    // start the timer
//    timer->start(50);
}

void Board::move()
{

    setPos(x(), y()+30);

//    if (pos().y() < 0)
//    {
//        scene()->removeItem(this);
//        delete this;
//    }
}
