#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsItemAnimation>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include <QVector>
#include "Doodle.h"
#include "Board.h"
#include <QPushButton>
//#include "menu.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    QVector<Board*> board;
    Doodle *doodle;
   // menu *Menu;
    Board *boardm;
    QPushButton *button1;
    QPushButton *button2;

    //Score * score;
   // Health * health;

};

#endif // GAME_H
