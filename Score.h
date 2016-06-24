#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    int hightScore;
    Score(QGraphicsItem * parent=0);
    void increase(int s);
    int getScore();
    void setHightScore(int);
    int readScore();
    void writeScore();
    int fScore;
    int score;

};
//
#endif // SCORE_H
