#include "Doodle.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <Windows.h>
#include <qmath.h>
#include <iostream>

//pair<int, int> makan;

QSet<Qt::Key> pressedKeys;
float degrees = 90.0f;
float radians = qDegreesToRadians(degrees);


Doodle::Doodle(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/doodleR.png"));

    this->installEventFilter(this);
    g = 10;

    v_0 = 40.0;
    v_1 = 0.0;

    y_0 = y();
    x_0 = x();

    t = 0.0;

    //***************************************************************

    QTimer * timer1 = new QTimer(this);
    connect(timer1, SIGNAL( timeout()), this, SLOT(set_pos()));

    timer1->start(100);

    //****************************************************************
}

void Doodle::keyPressEvent(QKeyEvent *event)
{
    //flag = 1;
    pressedKeys.insert((Qt::Key)event->key());

    if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Left) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y()-10);
        scene()->addItem(bullet);

        if (pos().x() > 0)
        {
            t = 0.0;
            degrees = 95.0f;
            radians = qDegreesToRadians(degrees);
        }
        pressedKeys.remove(Qt::Key_Space);
    }


    else if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Right) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y()-10);
        scene()->addItem(bullet);

        if (pos().x() + 100 < 800)
        {
            t = 0.0;
            degrees = 95.0f;
            radians = qDegreesToRadians(degrees);
        }

        pressedKeys.remove(Qt::Key_Space);
    }

    else if (pressedKeys.contains(Qt::Key_Left))
    {
        if (pos().x() > 0)
        {
            t = 0.0;
            degrees = 95.0f;
            radians = qDegreesToRadians(degrees);
        }

        setPixmap(QPixmap(":/images/doodleL.png"));
    }

    else if (pressedKeys.contains(Qt::Key_Right))
    {
        if (pos().x() + 100 < 800)
        {
             t = 0.0;
             degrees = 85.0f;
             radians = qDegreesToRadians(degrees);
        }

        setPixmap(QPixmap(":/images/doodleR.png"));
    }

    else if (event->key() == Qt::Key_Space)
    {
         setPixmap(QPixmap(":/images/doodleS.png"));
         Bullet * bullet = new Bullet();
         bullet->setPos(x()+15,y()-10);
         scene()->addItem(bullet);
         pressedKeys.remove(Qt::Key_Space);
    }
    else{
        t = 0.0;
        degrees = 90.0f;
        radians = qDegreesToRadians(degrees);
    }
}

void Doodle::keyReleaseEvent(QKeyEvent *event)
{
     pressedKeys.remove((Qt::Key)event->key());
}

void Doodle::move_up()
{
//    QList<QGraphicsItem *> colliding_items = collidingItemsD();


//    for (int i = 0, n = colliding_items.size(); i < n; ++i){
//        if (typeid(*(colliding_items[i])) == typeid(Board)){
//            t = 0.0;
//            degrees = 90.0f;
//            radians = qDegreesToRadians(degrees);
//            setPos(x() , y());
//            //game->score->increase();

////            scene()->removeItem(colliding_items[i]);
////            scene()->removeItem(this);

////            delete colliding_items[i];
////            delete this;

//            return;
//        }
//    }
}

void Doodle::move_down(int YY)
{
    setPos(x(),y() + YY );
}

void Doodle::set_pos()
{
   // int flag = 0;
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Board)){
            t = 0.0;
            degrees = 90.0f;
            radians = qDegreesToRadians(degrees);
            //flag = 1;

        }
    }
   // if(flag){
        ++t;
        ComputeY(t);
        setPos(x() + dx, y() - Y );
//    }
//    else{
//        t = 2;
//        ComputeY(t);
//        setPos(x() + dx, y() + Y );
//    }

}

int Doodle::ComputeY(long double t1)
{

    int flag = 0;
    float Max_t = v_0*qSin(radians)/g;
    float yoj = (v_0 * qSin(radians) * v_0 * qSin(radians)) / (2 * g);

    v_1 = (-1*g*t) + v_0*qSin(radians);

    if (t > 3)
        flag = 1;

    dy = ( (v_1*v_1) - (v_0*qSin(radians)*v_0*qSin(radians)) ) / (-2*g);
    dx = v_0*qCos(radians)*t;

    if (!flag)
        Y = yoj - dy;
    else
        Y = -1*(yoj - dy);

    qDebug() << " t " <<  t  << endl;

    if (t <= 2*Max_t+1 && t > 2*Max_t-1)
    {
        t = -1;
    }

    return Y;
}


