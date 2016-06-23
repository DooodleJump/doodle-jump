#include "Game.h"
#include <QBrush>
#include <QImage>
#include <time.h>
#include "Bullet.h"
#include <QKeyEvent>
#include "Enemy.h"
#include <QDebug>
#include <string.h>
#include <QString>
#include <QDebug>
#include <QFile>
#include <iostream>
#include "Score.h"
#include <fstream>
#include <cstdio>
#include <QTextStream>
#define sceneHeight 800
#define sceneWight 470

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,700);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneWight,sceneHeight);

    doodle = new Doodle();
    doodle->setPos(240,650);
    doodle->setFlag(QGraphicsItem::ItemIsFocusable);
    doodle->setFocus();
    scene->addItem(doodle);

    enemy = new Enemy();
    enemy->setPos(20, 100);
    enemy->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(enemy);
    activeEnemy = true;

    Board *b = new Board();
    b->setPos(243, 645);
    scene->addItem(b);
    board.push_back(b);

    QString name;
                int fx,fy;
                int line_count=0;
                QString line[100];

            QFile file("C:/Users/PC/Documents/GitHub/doodle-jump/readme.txt");
           // QFile file(":/Other files/map.txt");
            if (!file.open(QIODevice::ReadOnly))
                   qDebug() << "fail";
            if(file.exists()){

            qDebug() << "ok";
    }
            QTextStream in(&file);
            while( !in.atEnd())
            {
                line[line_count]=in.readLine();
                line_count++;
            }
            qDebug() << "line_count     " << line_count << endl;
           for (int k =0 ; k < line_count ; k++){
                name = line[k];
                   fx = name.split(" ")[0].toInt();
                  fy =  name.split(" ")[1].toInt();
                    Board *b = new Board();
                    b->setX (fx);
                    b->setY(fy);
                    qDebug() << "fx  " << fx << "    " <<"fy  " << fy << endl;
                    b->setPos(b->x(),b->y());
                    b->setFlag(QGraphicsItem::ItemIsFocusable);
                    scene->addItem(b);

                    board.push_back(b);
                }


           score = new Score();
           scene->addItem(score);






















}




//    qsrand(time(NULL));
//    int n = rand()%10 + 10;
//    for (int i = 0; i < n; ++i)
//    {
//       Board *b = new Board();
//       b->setX( (rand() % 30)*15 );
//       b->setY( (rand() % 50)*15 );

//       for (int j = 0; j < i-1; ++j){
//           while(b->x() < board[j]->x()+30 && b->x() > board[j]->x()-30)
//           {
//               b->setX( (rand() % 30)*15 );
//           }
//       }

//       for (int j = 0; j < i-1; ++j){
//           while(b->y() < board[j]->y()+30 && b->y() > board[j]->y()-30)
//           {
//               b->setY( (rand() % 50)*15 );
//           }
//       }

//       b->setPos(b->x(), b->y());
//       b->setFlag(QGraphicsItem::ItemIsFocusable);

//       scene->addItem(b);
//       board.push_back(b);
//   }
//}

