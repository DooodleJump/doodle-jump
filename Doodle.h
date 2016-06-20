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

    float g;
    float v_0;
    float v_1;
    float dy;
    float Y;
    float y_0;
    float y_1;
    float dx;
    float X;
    float x_0;
    float x_1;
    float t;

   // float Y;
    Board *b;

private:
    int ComputeY(long double t1);

private slots:
    void move_up();
    void move_down(int YY);
    void set_pos();

//private:
    //QMediaPlayer * bulletsound;
};

#endif // DOODLE_H
