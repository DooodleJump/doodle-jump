#ifndef DOODLE_H
#define DOODLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
//#include <QMediaPlayer>
#include <iostream>
#include <QObject>
#include <QEvent>

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
    float y_board_ghabli;
    float y_board_jadid;
    bool isCOllide;

    //QMediaPlayer *jump;

private:
    void ComputeY();

private slots:
    void move_down(int fasele);
    void set_board();
    void collide();
    void set_pos();
    void fall();
};

#endif // DOODLE_H
