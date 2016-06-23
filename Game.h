#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include "Doodle.h"
#include "Board.h"
#include "Score.h"
#include "Enemy.h"
#include <QPushButton>
//#include <QMediaPlayer>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    QVector<Board*> board;
    Doodle *doodle;
    Enemy *enemy;
    Score *score;
    bool activeEnemy;



////    Board *boardm;
////    QPushButton *button1;
////    QPushButton *button2;
////    Health * health;

};


