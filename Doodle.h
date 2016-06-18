#ifndef DOODLE_H
#define DOODLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <iostream>
#include <QObject>
#include "Board.h"
#include <QEvent>
//#include <QMediaPlayer>

class Doodle : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Doodle(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    std::pair <float,float> velocity;

    int g;
    int v_0;
    int v_1;
    int dy;
    int Y;
    int y_0;
    int y_1;
    int t;

   // float Y;
    Board *b;

private:
    int ComputeY(int t1);

private slots:
    void move_up();
    void move_down(int YY);
    void set_pos();

//private:
    //QMediaPlayer * bulletsound;
};

#endif // DOODLE_H
