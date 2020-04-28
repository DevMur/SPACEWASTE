#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set random x position
    int random_number = rand() % 800; //size of display
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/Crug.png")); //now it's a L1 enemy
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    // make/connect a timer to move the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_easy()));

    // start the timer
    timer->start(50);
}

void Enemy::move_easy(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
