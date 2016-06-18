#include "Doodle.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <Windows.h>

QSet<Qt::Key> pressedKeys;

Doodle::Doodle(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/doodleR.png"));

    this->installEventFilter(this);
    g = 10;
    v_0 = 40;
    v_1 = 0;
    y_0 = y();
    t = 0;

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
    ComputeY(t);
    setPos(x(), y() - Y );
    qDebug() << Y << endl;
}

int Doodle::ComputeY(int t1)
{
    int flag = 0;
    int Max_t = v_0/g;
    int yoj = (v_0 * v_0) / (2 * g);

    v_1 = (-1*g*t) + v_0;

    if (t > 3)
        flag = 1;

    dy = ( (v_1*v_1) - (v_0*v_0) ) / (-2*g);

    if (!flag)
        Y = yoj - dy;
    else
        Y = -1*(yoj - dy);

    if (t == 2*Max_t)
    {
        t = -1;
    }
    qDebug() << t << endl;

    return Y;
}






