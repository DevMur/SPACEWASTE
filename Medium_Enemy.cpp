#include "Medium_Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Medium_Enemy::Medium_Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 700; //size of display
    setPos(random_number,0);

    // drew the rect
    setPixmap(QPixmap(":/images/e2.jpeg")); //now it's a crug
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_medium()));

    // start the timer
    timer->start(50);
}

void Medium_Enemy::move_medium(){
    // move enemy down
    setPos(x(),y()+10);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
