#include <QFont>

#include "Health.h"
#include "Player.h"
#include "Game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3;

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3 TODO
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    //TODO  setPixmap(QPixmap(":/images/Spaceship.png"));
    //setScale(0.05);
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    if (health == 0){
        game->GameOver();
    }
}

int Health::getHealth(){
    return health;
}

