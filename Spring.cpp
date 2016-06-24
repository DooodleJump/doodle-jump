#include "Spring.h"



Spring::Spring(QGraphicsItem *parent)
{
     setPixmap(QPixmap(":/images/p-green-s0.png"));
     btype = 1;
}

void Spring::move()
{
    v_0 = 80.0;
    g = 14;
}


