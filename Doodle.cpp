#include "Doodle.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <qmath.h>
#include <time.h>
#include <QDebug>
#include "Bullet.h"
#include "Game.h"
#include "Board.h"

extern Game * game;

float tp;
float tmushak;
float tfanar;
int r = 10;
QSet<Qt::Key> pressedKeys;
float degrees = 90.0f;
float radians = qDegreesToRadians(degrees);

QTimer * timer1;
QTimer * timer2;
QTimer * timer3;
QTimer * timer4;



Doodle::Doodle(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/doodleR.png"));
//    jump = new QMediaPlayer();
//    jump->setMedia(QUrl(":/sounds/jump.mp3"));

    this->installEventFilter(this);

    g = 10;

    v_0 = 40.0;
    v_1 = 0.0;

    y_0 = 490;
    x_0 = x();

    t = 0.0;

    y_board_ghabli = 645;
    isSpring = false;
    isMissile = false;

    //***************************************************************

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(set_pos()));
    timer1->start(100);

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(collide()));


    //****************************************************************
}

void Doodle::keyPressEvent(QKeyEvent *event)
{
    pressedKeys.insert((Qt::Key)event->key());

    if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Left) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 15, y() - 10);
        scene()->addItem(bullet);

        if (pos().x() > 0)
        {
            if (degrees < 94.0f || degrees > 98.0f)
            {
                degrees = 97.0f;
                radians = qDegreesToRadians(degrees);
            }
        }
    }


    else if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Right) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 15,y() - 10);
        scene()->addItem(bullet);

        if (pos().x() + 100 < 800)
        {
            if (degrees > 86.0f || degrees < 82.0f)
            {
                degrees = 83.0f;
                radians = qDegreesToRadians(degrees);
            }
        }
    }

    else if (pressedKeys.contains(Qt::Key_Left))
    {
        //jump->play();
        if (pos().x() > 0)
        {
            if (degrees < 94.0f || degrees > 98.0f)
            {
                degrees = 97.0f;
                radians = qDegreesToRadians(degrees);
            }
        }
        setPixmap(QPixmap(":/images/doodleL.png"));
    }

    else if (pressedKeys.contains(Qt::Key_Right))
    {
        //qDebug() << " jump ";
        //jump->play();
        if (pos().x() + 100 < 800)
        {
             if (degrees > 86.0f || degrees < 82.0f)
             {
                 degrees = 83.0f;
                 radians = qDegreesToRadians(degrees);
             }
        }
        setPixmap(QPixmap(":/images/doodleR.png"));
    }

    else if (event->key() == Qt::Key_Space)
    {
         setPixmap(QPixmap(":/images/doodleS.png"));
         Bullet * bullet = new Bullet();
         bullet->setPos(x() + 15,y() - 10);
         scene()->addItem(bullet);
    }
}

void Doodle::keyReleaseEvent(QKeyEvent *event)
{
     pressedKeys.remove((Qt::Key)event->key());
}

void Doodle::collide()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

        for (int i = game->board.size() - 1; i > 0; --i)
        {
            if (collidesWithItem(game->board[i]))
            {
                 isCOllide = true;
                 qDebug() << "salam " << game->board[i]->btype<< endl;

                 if (game->board[i]->btype == 1)
                 {
                     game->board[i]->setPixmap(QPixmap(":/images/p-green-s1.png"));
                     //Debug ()<< "Spring"<< endl;
                     isSpring = true;
                     timer1->stop();
                     t = 0.0;
                     tfanar = 0.0;
                     v_0 = 80.0;
                     g = 10;
                     degrees = 90.0f;
                     radians = qDegreesToRadians(degrees);
                     setY(game->board[i]->y() - 55);
                     set_board();
                     timer1->start(100);
//                     set_board();
                     colliding_items.removeOne(game->board[i]);
                     break;
                 }

                 else if (game->board[i]->btype == 2)
                 {
                     setPixmap(QPixmap(":/images/Toad.png"));
                     isMissile = true;
                     timer1->stop();
                     t = 0.0;
                     tmushak = 0.0;
                     v_0 = 80.0;
                     g = 10;
                     degrees = 90.0f;
                     radians = qDegreesToRadians(degrees);
                     setY(game->board[i]->y() - 55);
                     timer1->start(100);
                     set_board();
                     colliding_items.removeOne(game->board[i]);
                     break;
                 }

                 else if (typeid(game->board[i]) == typeid(Brownboard))
                 {

                     isBrownboard = true;
                     setPixmap(QPixmap(":/images/p-brown-1.png.png"));
                     timer1->stop();
                     game->board[i]->setpixmap();
                    // game->brownboard->setpixmap();
                     v_0 = 40.0;
                     g = 10;
                     t = v_0/g;
                     degrees = 90.0f;
                     radians = qDegreesToRadians(degrees);
                     setY(game->board[i]->y() - 55);
                     timer1->start(100);
                     colliding_items.removeOne(game->board[i]);
                     break;
                 }

                 else
                 {
                     y_board_jadid = game->board[i]->y();
                     timer1->stop();
                      t = 0.0;
                      g = 10;
                      degrees = 90.0f;
                      radians = qDegreesToRadians(degrees);
                      setY(game->board[i]->y() - 55);
                      timer1->start(100);

                      set_board();
                      colliding_items.removeOne(game->board[i]);
                      break;
                 }
            }
            else
            {
                isCOllide = false;
            }

        }

        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Safineh))
            {
                timer1->stop();
                for (int i = 0 ; i < game->enemy.size() ; i++)
                {
                    game->scene->removeItem(game->enemy[i]);
                }
                for ( int j = 0 ; j < game->board.size() ; j++)
                {
                    game->scene->removeItem(game->board[j]);
                }
                game->score->setPos(100 , 500);
                game->score->setPlainText(QString("you won and your score: ") + QString::number(game->score->getScore()));


            }
            else if (typeid(*(colliding_items[i])) == typeid(Spider) || typeid(*(colliding_items[i])) == typeid(BossMon) ||
                    typeid(*(colliding_items[i])) == typeid(Fly) || typeid(*(colliding_items[i])) == typeid(Bluemon))
            {
                 //gameover();
                 timer1->stop();
                 timer3 = new QTimer(this);
                 connect(timer3, SIGNAL(timeout()), this, SLOT(fall()));

                 timer3->start(40);
            }

        }
}

void Doodle::set_pos()
{
    if (!isSpring && !isMissile)
    {
     //   qDebug()<<"no spring"<<endl;
        ++t;
        collide();
        ComputeY(t);
    }
    else if (isMissile)
    {
        ++tmushak;
        ComputeY(tmushak);
    }
    else if (isSpring)
    {
    //    qDebug()<<"spring"<<endl;
        ++tfanar;
        ComputeY(tfanar);
    }

    if (!isCOllide)
    {
        t = tp;
    }

    if ( t == -1)
    {
        setY(y_0 + Y);
        degrees = 90.0f;
        radians = qDegreesToRadians(degrees);
    }

    if (x() + dx > 450)
        setPos(10, y() - Y);
    if (x() + dx < 0)
        setPos(470, y() - Y);
    else
        setPos(x() + dx, y() - Y);

    game->safineh->setX(x());

    if(y() > 800)
    {
        timer1->stop();
        //isGameOver = true;
        gameover();
    }
}

void Doodle::fall()
{
    setPos(x(), y() + 40);
    if (y() > 800)
    {
        timer3->stop();
        gameover();
    }

}

void Doodle::ComputeY(int t1)
{
    if (isSpring)
    {
    //    qDebug ()<< "fanar"<< endl;
        if (tfanar > 6)
        {
            v_0 = 40.0;
            isSpring = false;
            tfanar = 0;
            g = 10;
        }
    }
    else if (isMissile)
    {
        if (tmushak > 6)
        {
            v_0 = 40.0;
            isMissile = false;
            tmushak = 0;
            g = 10;
        }
    }

    int flag = 0;
    float Max_t = v_0*qSin(radians)/g;
    float yoj = (v_0 * qSin(radians) * v_0 * qSin(radians)) / (2 * g);

   // qDebug() << "maxt " << Max_t << endl << "t1" << t1<< endl;

    v_1 = (-1*g*t1) + v_0*qSin(radians);

    if (t1 > Max_t-1)
        flag = 1;

    dy = ( (v_1*v_1) - (v_0*qSin(radians)*v_0*qSin(radians)) ) / (-2*g);
    dx = v_0*qCos(radians)*t1;

    if (!flag)
        Y = yoj - dy;
    else
        Y = -1*(yoj - dy);

    if (!isSpring && !isMissile)
        tp = t1;
    if (t1 <= 2*Max_t+1 && t1 > 2*Max_t-1)
    {
       t1 = -1;
    }
    if (!isSpring && !isMissile)
        t = t1;
    else if (isSpring)
        tfanar = t1;
    else if (isMissile)
        tmushak = t1;
}


void Doodle::set_board()
{
    //qDebug() << "setboard "<< endl;
    if (y() < 350)
    {
            int fasele = y_board_ghabli - y_board_jadid;
            if (fasele > 0)
            {
                game->score->increase(10*fasele);
                timer1->stop();
                move_down(fasele);
                timer1->start(100);

               // if (game->activeEnemy)
                    for (int i = 0; i < game->enemy.size(); ++i)
                    {
                        game->enemy[i]->setY(game->enemy[i]->y() + fasele);
                        if (game->enemy[i]->y() > 700)
                            game->scene->removeItem(game->enemy[i]);
                    }

                if (y_board_jadid < 10)
                    y_board_ghabli = -1*y_board_jadid;
                else
                    y_board_ghabli = y_board_jadid;

                for (int i = 0; i < game->board.size(); ++i)
                {
                    game->board[i]->setY(game->board[i]->y() + fasele);
                    if (game->board[i]->y() > 700)
                        game->scene->removeItem(game->board[i]);
                }
            }
    }
}

void Doodle::move_down(int fasele)
{
    setY(y() + fasele);
}


void Doodle::move_GO()
{
    setPos(x(), y() + r);
    r += 10;
    if(isGameOver){
        if(y() > 300){
            timer4->stop();
            game->score->setPos(100 , 500);
            game->score->setPlainText(QString("your score: ") + QString::number(game->score->getScore()));

           // game->score->setPlainText(QString("hight score: ") + QString::number(game->score->setHightScore()));
        }
    }
}


void Doodle::gameover(){
    isGameOver = true;
    if (y() > 800){
        qDebug() << "game over" << endl;
        for (int i = 0 ; i < game->enemy.size() ; i++)
        {


            game->scene->removeItem(game->enemy[i]);
        }
        for ( int j = 0 ; j < game->board.size() ; j++)
        {
            game->scene->removeItem(game->board[j]);
        }

       setX(220);
       setY(0);
       setPos(x() , y());
       timer4 = new QTimer(this);
       connect(timer4, SIGNAL(timeout()), this, SLOT(move_GO()));
       //connect(timer4, SIGNAL(timeout()), this, SLOT(move_down(10)));
       timer4->start(100);
    }
}

