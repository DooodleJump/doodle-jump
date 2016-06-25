#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>


class Board : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    int btype;
    QTimer * timer;
    Board(QGraphicsItem * parent=0);
     virtual void setpixmap();

public slots:
    void move_down(int fasele);

};//

#endif // BOARD_H
