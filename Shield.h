#ifndef SHIELD_H
#define SHIELD_H

class Shield :public QObject,public QGraphicsPixmapItem , public Award{
    Q_OBJECT
public:
   Award(QGraphicsItem * parent=0);
public slots:
   void move();
   void ability();
};

#endif // SHIELD_H
