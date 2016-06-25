 #include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include "Doodle.h"
#include "Board.h"
#include "Score.h"
#include "Button.h"
#include "Enemy.h"
#include "Bluemon.h"
#include "Fly.h"
#include "BossMon.h"
#include "Spider.h"
#include "Spring.h"
#include "Brownboard.h"
#include <QPushButton>
//#include <QMediaPlayer>
#include "Missile.h"
#include "Springboard.h"
#include "Safineh.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    QVector<Board*> board;
    QVector<Enemy*> enemy;
    Doodle *doodle;
    Brownboard *brownboard;
    Enemy *enemy1;
    Spider *spider;
    Score *score;
    Spring *spring;
    Fly *fly;
    BossMon *bossmon;
    Bluemon *bluemon;
    Missile *missile;
    Springboard * springboard;
    Safineh * safineh;
    bool activeEnemy;
};

