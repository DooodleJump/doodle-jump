#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",10));
}

void Score::increase(int s)
{
    score += s;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}
