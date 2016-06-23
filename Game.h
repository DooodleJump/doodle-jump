#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include "Doodle.h"
#include "Board.h"
#include "Score.h"
#include "Button.h"
#include "Enemy.h"
#include "Spring.h"
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
    Spring *spring;
    bool activeEnemy;



////    Board *boardm;
    Button *bplay;
//    QPushButton *button2;
////    Health * health;

};


