#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>


//all comments go up here when finished
Enemy::Enemy(){
    //TODO: make sprites
    //      adjust sizing and speed from testing
    //      adjust spawn rate
    //      add points
    //      destroy on impact

    //set random position, rand is a computers attempt at a random int.
    //700 is based off the view and scene sizes
    int random_int = rand() % 700; 
    //set the position of the enemy object
    setPos(random_int, 0);

    //draw the enemy
    //sprite goes here 
    //setCrugSprite(//filepath + size)
    setRect(0, 0, 100, 100);

    //connect to ship
    //library method which sets a timer upon the SLOT becoming true.
    //reminder, move should be fire_pew_gun or something of the sort
    QTimer * enemy_gun_timer = new QTimer();
    Enemy::connect(enemy_gun_timer, SIGNAL(timeout()), this, SLOT(move()));

    //in this case the enemy gun is itself so its timer is the rate at which it moves vertically 
    //down the screen
    enemy_gun_timer->start(50); //rates to be edited based on play testing and how it looks
}

void Enemy::move(){
    //move easy enemy down
    //for every call move at rate, inverted?
    setPos(x(), y()+5);

    //if the sprite is below the scene kill it
    if (pos().y() + rect().height() < 0) 
    {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet off screen";
    }
}
