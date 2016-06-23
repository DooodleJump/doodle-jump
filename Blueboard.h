#ifndef BLUEBOARD_H
#define BLUEBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Blueboard : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Blueboard(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // BLUEBOARD_H
