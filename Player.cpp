#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"
#include "Score.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set bullet sound
//    bulletsound = new QMediaPlayer();
//    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    //TODO just get the laser synth samples from desktop

    setPixmap(QPixmap(":/images/Spaceship.png"));
    setScale(0.05);
    lives = 3;
}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
        setPos(x()+20,y());
    }
    //HOW CAN THIS BE FASTER WITHOUT MOVING TOO MANY PIXELS PER CLICK
    //TODO spacing/movement

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

void Player::setScore(Score current){
    total_points = current.getScore();
}

void Player::spawn(){
    // create an enemy
    if (total_points <= 10)
    {
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }
    else if (total_points > 10 && total_points <= 50)
    {
        Medium_Enemy * e2 = new Medium_Enemy();
        scene()->addItem(e2);
    }
    else
    {
        Hard_Enemy * e3 = new Hard_Enemy();
        scene()->addItem(e3);
    }
}
