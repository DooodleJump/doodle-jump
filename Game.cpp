#include "Game.h"
#include <QBrush>
#include <QImage>
#include <time.h>
#include "Bullet.h"
#include <QKeyEvent>



Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,700);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,700);

    doodle = new Doodle();
    doodle->setPos(240,600);

    doodle->setFlag(QGraphicsItem::ItemIsFocusable);
    doodle->setFocus();

    scene->addItem(doodle);

    qsrand(time(NULL));
    int n = rand()%10 + 10;
    for (int i = 0; i < n; ++i)
    {
       Board *b = new Board();
       b->setX( (rand() % 30)*15 );
       b->setY( (rand() % 50)*15 );

       for (int j = 0; j < i-1; ++j){
           while(b->x() < board[j]->x()+30 && b->x() > board[j]->x()-30)
           {
               b->setX( (rand() % 30)*15 );
           }
       }

       for (int j = 0; j < i-1; ++j){
           while(b->y() < board[j]->y()+30 && b->y() > board[j]->y()-30)
           {
               b->setY( (rand() % 50)*15 );
           }
       }

       b->setPos(b->x(), b->y());
       b->setFlag(QGraphicsItem::ItemIsFocusable);

       scene->addItem(b);

       board.push_back(b);
    }
//    while(doodle->y() > 0)
//    {
//       doodle->setX(doodle->x() + 0.1);
//       doodle->setY(doodle->y() - 0.5);
//    }
}

