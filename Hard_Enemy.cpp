#include "Hard_Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;


//this needs a timer check.
Hard_Enemy::Hard_Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int random_number = rand() % 700; //size of display
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/e3.png")); //now it's a crug
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_hard()));

    timer->start(50);
}

void Hard_Enemy::move_hard(){
    setPos(x(),y()+10); //add switcher for different movement types

    //TODO: Different non linear movement, use as basis for boss attacks

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
