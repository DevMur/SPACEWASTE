#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set bullet sound
//    bulletsound = new QMediaPlayer();
//    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    //TODO just get the laser synth samples from desktop

    setPixmap(QPixmap(":/images/Spaceship.png"));
    setScale(0.1);
}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    //HOW CAN THIS BE FASTER WITHOUT MOVING TOO MANY PIXELS PER CLICK
    //TODO spacing

    else if (event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y());
        scene()->addItem(bullet);

//        // play bulletsound
//        if (bulletsound->state() == QMediaPlayer::PlayingState)
//        {
//            bulletsound->setPosition(0);
//        }
//        else if (bulletsound->state() == QMediaPlayer::StoppedState)
//        {
//            bulletsound->play();
//        }
//create lazer.
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
