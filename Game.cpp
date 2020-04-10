#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600
    setBackgroundBrush(QBrush(QImage(":/images/bg.png"))); //background, this will be changed with levels


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //should this all be called from the level creator or just the first part.
    //this is where levels are called. Level completion key (potentially save states lol)


    player = new Player();
    player->setPos(350,500); // Always be in the middle bottom of screen
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    //create a ship for the player

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25); //not where this will go, good for testing
    scene->addItem(health);
    //add health TODO set 3 = 3 ships on the scene, 2 = 2 ships, etc.
    //must be called for each level

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl(""));
//    music->play();
//New music for each level? Just bosses? End music? TODO ask for more songs from Jordan
    show();
}
