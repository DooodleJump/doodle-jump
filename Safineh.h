#ifndef SAFINEH_H
#define SAFINEH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>


class Safineh : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Safineh(QGraphicsItem * parent=0);
};

#endif // SAFINEH_H
