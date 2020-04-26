#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemy::Enemy(){
    //TODO: make sprites
    //      adjust sizing and speed from testing
    //      adjust spawn rate
    //      add points
    //      destroy on impact
    //github work

    //set random position
    int random_int = rand() % 700;
    setPos(random_int, 0);

    //draw the enemy
    setRect(0, 0, 100, 100);

    //connect to ship
    QTimer * enemy_gun_timer = new QTimer();
    Enemy::connect(enemy_gun_timer, SIGNAL(timeout()), this, SLOT(move()));

    enemy_gun_timer->start(50); //rates to be edited based on play testing and how it looks
}

void Enemy::move(){
    //move easy enemy down
    setPos(x(), y()+5);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet off screen";
    }
}
