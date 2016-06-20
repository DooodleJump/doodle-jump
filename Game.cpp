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
    setFixedSize(550,800);

    doodle = new Doodle();
    doodle->setPos(240,500);

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
}














//    doodle = new Doodle();
//    doodle->setPos(110,450);
//    doodle->setFlag(QGraphicsItem::ItemIsFocusable);
//    doodle->setFocus();

//    boardm = new Board();
//    boardm->setPos(100,600);

//    button1 = new QPushButton();
//    //button1->setIconSize()

////    QPixmap p(":/images/play.jpg");

//    button1->setIcon(QIcon(QPixmap(":/images/play.jpg")));
////    button1->setIconSize(p.rect().size());
////    button1->setGeometry(p.rect());

//   // QPushButton button;

//    //QBitmap()
////    button1->resize(50,50);
////    button1->show();

////    QBitmap bitmap(QPixmap(":/images/play.jpg"));
////    button1->setMask(bitmap.mask());
////    button1->setGeometry(bitmap.rect());

//   // button1.setMask(p.createMaskFromColor(Qt::transparent,Qt::MaskInColor));
//   // button1->setMask(p.mask());

//    scene->addItem(doodle);
//    scene->addItem(boardm);
//    scene->addWidget(button1);
