#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
//level 1
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600... no this is not a fun size
    setBackgroundBrush(QBrush(QImage(":/images/bg.png"))); //this should be atmosphere/planet

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
    //QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl(""));
//    music->play();
//New music for each level? Just bosses? End music? TODO ask for more songs from Jordan
    show();
//end level 1
//ill probably go back and delete level relateds comments but uhhh... fuck while loops
    //level 2
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,800,600); // make the scene 800x600
        setBackgroundBrush(QBrush(QImage(":/images/bg.png"))); //this one is space


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

        //score = new Score();
        scene->addItem(score); //health and score should carry over... maybe not
        //health = new Health();
        health->setPos(health->x(),health->y()+25); //not where this will go, good for testing
        scene->addItem(health);
        //add health TODO set 3 = 3 ships on the scene, 2 = 2 ships, etc.
        //must be called for each level

        QTimer * timer2 = new QTimer();
        QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn())); //TODO spawn switcher
        //QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer2->start(2000);

    //    QMediaPlayer * music = new QMediaPlayer();
    //    music->setMedia(QUrl(""));
    //    music->play();
    //New music for each level? Just bosses? End music? TODO ask for more songs from Jordan
        show();
        //end level 2
}

void Game::Menu()
{
    QGraphicsTextItem* title = new QGraphicsTextItem("It Gets A Name When Others Can Play");
    QFont titleFont("comic sans", 50);
    title->setFont(titleFont);
    int title_xPos = this->width()/2 - title->boundingRect().width()/2;
    int title_yPos = 150;
    title->setPos(title_xPos, title_yPos);
    scene->addItem(title);


}












