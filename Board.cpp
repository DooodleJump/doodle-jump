#include "Board.h"
//
Board::Board(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/board.png"));
    btype = 0;
}

void Board::setpixmap()
{

}

void Board::move_down(int fasele)
{
    setPos(x(), y() + fasele);
}
