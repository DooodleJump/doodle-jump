#include "Score.h"
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <fstream>

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

int Score::setHightScore(){
//    int hscore;
//    hscore = readScore();
//    hightScore = hScore;
    hightScore = readScore();
    return hightScore;
}
int Score::readScore(){
    QString numScore;
    QFile file("C:/Users/pc/Documents/GitHub/doodle-jump/score.txt");

    if (!file.open(QIODevice::ReadOnly))
           qDebug() << "fail";
    QTextStream on(&file);
    //if (!on.atEnd())
    numScore = on.readLine(); //in.readLine();
    fScore = numScore.split(" ")[0].toInt();
    //setHightScore();
    qDebug() << "fScore" << fScore << endl;
    return fScore;

}

void Score::writeScore(){
   // QString numScore;
    QFile file("C:/Users/pc/Documents/GitHub/doodle-jump/score.txt");

    if (file.open(QIODevice::WriteOnly ))
           qDebug() << "fail";
    QTextStream out(&file);
    if (readScore() < score)
        out << score ;

}

