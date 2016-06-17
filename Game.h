#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <vector>
#include <QVector>
#include "Doodle.h"
#include "Board.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    QVector<Board*> board;
    Doodle * doodle;

    //Score * score;
   // Health * health;

};

#endif // GAME_H
