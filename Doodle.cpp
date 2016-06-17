#include "Doodle.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <Windows.h>

QSet<Qt::Key> pressedKeys;
int Max_t;

Doodle::Doodle(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/doodleR.png"));

    this->installEventFilter(this);
    g = 10;
    v_0 = 30;
    v_1 = v_0;
    y_0 = y();
    t = 0;
    Max_t = v_0/g;

    //***************************************************************

    QTimer * timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(set_pos()));

    timer1->start(100);

    //****************************************************************
}

void Doodle::keyPressEvent(QKeyEvent *event)
{
    pressedKeys.insert((Qt::Key)event->key());

    if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Left) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y()-10);
        scene()->addItem(bullet);

        if (pos().x() > 0)
           setPos(x()-10,y());
        pressedKeys.remove(Qt::Key_Space);
    }


    else if( pressedKeys.contains(Qt::Key_Space) && pressedKeys.contains(Qt::Key_Right) )
    {
        setPixmap(QPixmap(":/images/doodleS.png"));

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y()-10);
        scene()->addItem(bullet);

        if (pos().x() + 100 < 800)
            setPos(x()+10,y());

        pressedKeys.remove(Qt::Key_Space);
    }

    else if (pressedKeys.contains(Qt::Key_Left))
    {
        if (pos().x() > 0)
            setPos(x()-10,y());
        setPixmap(QPixmap(":/images/doodleL.png"));
    }

    else if (pressedKeys.contains(Qt::Key_Right))
    {
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
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
}

void Doodle::keyReleaseEvent(QKeyEvent *event)
{
     pressedKeys.remove((Qt::Key)event->key());
}

void Doodle::move_up()
{   

}

void Doodle::move_down(int YY)
{
    setPos(x(),y() + YY );
}

void Doodle::set_pos()
{
    t++;
    int Y = ComputeY(t);
     qDebug() << Y << endl;
    setPos(x(), Y );
}

int Doodle::ComputeY(int t1)
{
    if(t == 2*Max_t)
    {
      t = 0;
    }

//    if (t1 == Max_t)
//    {
//        v_0 = 0;
//    }

//    v_0 -= g;
//    y_0 -= 10;

//    if (v_0 < -30)
//        qDebug() << "shod" << endl;


  //  v_1 = -1*g*t + v_0;

    y_1 = -1*(1/2)*g*t*t + v_1*t + y_0;

    return y_1;












//    if(t1 <= Max_t)
//    {
//        y_1 = -1/2*g*t1*t1 + v_0*t1 +y_0;

//    }





//        return -1*(g/2*t*t+v_0*t+y());
//    else
//        return g/2*t*t+v_0*t+y();
}






