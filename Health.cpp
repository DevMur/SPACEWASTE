#include "Health.h"
#include "Player.h"
#include <QFont> //not required...

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    //for (int i = 0; i < Player::getLives(); i++)
    {

    }


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
}

int Health::getHealth(){
    return health;
}

