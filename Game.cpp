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
#include <string>
#include <QDebug>
#include <QFile>
#include <iostream>
#include "Score.h"
#include "Missile.h"
#include "Spring.h"
#include <fstream>
#include <cstdio>
#include <QTextStream>
#include "Springboard.h"
#include "Spider.h"
#include "BossMon.h"
#include "Fly.h"

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

    Board *b = new Board();
    b->setPos(243, 645);
    board.push_back(b);
    scene->addItem(b);
    board.push_back(b);

    Enemy *e = new Enemy();

           QString name;
           int fx,fy;
           char type;
           int line_count=0;
           QString line[500];

            QFile file("C:/Users/ahmad/Documents/GitHub/doodle-jump/readme.txt");
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
                type = name.split(" ")[0].toInt();
                if (type == 0){
                    b->btype = name.split(" ")[1].toInt();
                    fx =  name.split(" ")[2].toInt();
                    fy = name.split(" ")[3].toInt();

                    if (b->btype == 0)
                    {
                        Board *b = new Board();
                        b->setX (fx);
                        b->setY(fy);
                        qDebug() << "fx  " << fx << "    " <<"fy  " << fy << endl;

                        b->setPos(b->x(),b->y());
                        b->setFlag(QGraphicsItem::ItemIsFocusable);
                        scene->addItem(b);
                        board.push_back(b);
                    }
                    if (b->btype == 1)
                    {
                        qDebug() << "fanar";
                        spring = new Spring();
                        spring->setPos(fx,fy);
                        spring->setFlag(QGraphicsItem::ItemIsFocusable);
                        board.push_back(spring);
                        scene->addItem(spring);
                    }
                    else if(b->btype == 2)
                    {
                        missile = new Missile();
                        missile->setPos(fx,fy);
                        missile->setFlag(QGraphicsItem::ItemIsFocusable);
                        board.push_back(missile);
                        scene->addItem(missile);

                    }
                    else if (b->btype == 3){
                        springboard = new Springboard();
                        springboard->setPos(fx,fy);
                        springboard->setFlag(QGraphicsItem::ItemIsFocusable);
                        board.push_back(springboard);
                        scene->addItem(springboard);
                    }

                }
                else if (type == 1)
                {
                    e->etype = name.split(" ")[1].toInt();
                    fx =  name.split(" ")[2].toInt();
                    fy = name.split(" ")[3].toInt();

                    if (e->etype == 1){
                        fly = new Fly();
                        fly->setPos(fx,fy);
                        fly->setFlag(QGraphicsItem::ItemIsFocusable);
                        enemy.push_back(fly);
                        scene->addItem(fly);
                    }
                    else if (e->etype == 2){
                        bossmon = new BossMon();
                        bossmon->setPos(fx,fy);
                        bossmon->setFlag(QGraphicsItem::ItemIsFocusable);
                        enemy.push_back(bossmon);
                        scene->addItem(bossmon);
                    }
                    else if (e->etype == 3){
                        spider = new Spider();
                        spider->setPos(fx,fy);
                        spider->setFlag(QGraphicsItem::ItemIsFocusable);
                        enemy.push_back(spider);
                        scene->addItem(spider);
                    }
                    else if (e->etype == 4){
                        bluemon = new Bluemon();
                        bluemon->setPos(fx,fy);
                        bluemon->setFlag(QGraphicsItem::ItemIsFocusable);
                        enemy.push_back(bluemon);
                        scene->addItem(bluemon);
                    }
                }

            }


           score = new Score();
           scene->addItem(score);
}



















//////////////////


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

