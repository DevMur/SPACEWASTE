#include "Game.h"
#include "Menu.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
//create screen
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,1000); // make the scene 800x600... no this is not a fun size
    setBackgroundBrush(QBrush(QImage(":/images/bg.png"))); //this should be atmosphere/planet

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,1000);
}

void Game::DisplayMenu()
{
//start game
    QGraphicsTextItem* title = new QGraphicsTextItem("It Gets A Name When Others Can Play");
    QFont titleFont("Times", 50);
    title->setFont(titleFont);
    int title_xPos = this->width()/2 - title->boundingRect().width()/2;
    int title_yPos = 250;
    title->setPos(title_xPos, title_yPos);
    scene->addItem(title);

    Menu *play = new Menu(QString("PLAY")); //play button / pb
    int pb_xPos = this->width()/2 - play->boundingRect().width()/2;
    int pb_yPos = 350; //tbd location
    play->setPos(pb_xPos, pb_yPos);
    connect(play, SIGNAL(clicked()), this, SLOT(Level1()));
    scene->addItem(play);

    //exit and eventually settings, such as ship slider speed and maybe difficulty for bosses.
    Menu *quit = new Menu(QString("QUIT"));
    int qb_xPos = this->width()/2 - quit->boundingRect().width()/2;
    int qb_yPos = 450; //uhhh maybe but location tbd
    quit->setPos(qb_xPos, qb_yPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);
}


/*
 * the level check is very important. It determines the type of enemy and item spawning that will happen.
 * these functions determine spawn count, the timer in their connections determine rate
 *
 */
void Game::spawn()
{
    if (this->level == 1)
    {
        Enemy * enemy = new Enemy();
        scene->addItem(enemy);
    }
}
void Game::spawn2()
{
    if (this->level == 2)
    {
        Medium_Enemy * e1 = new Medium_Enemy();
        Medium_Enemy * e2 = new Medium_Enemy();
        scene->addItem(e1);
        scene->addItem(e2);
    }
}
void Game::spawn3()
{
    if (this->level == 1)
    {
        Hard_Enemy * e1 = new Hard_Enemy();
        Hard_Enemy * e2 = new Hard_Enemy();
        Hard_Enemy * e3 = new Hard_Enemy();
        scene->addItem(e1);
        scene->addItem(e2);
        scene->addItem(e3);
    }
}

/*
 * first delete the menu
 * then set the stage for the game. Level one spawns a single player. Any other calls are to an implicitly
 * deleted copy constructor
 * the levels will determine what things can spawn
 */
void Game::Level1()
{
    //level 1 delete menu;
    scene->clear();

    player = new Player(); //there is only a single call.
    player->setPos(400,700); // Always be in the middle bottom of screen
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    //create a ship for the player

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25); //not where this will go, good for testing
    scene->addItem(health);

    connect(player, SIGNAL(next_level()), this, SLOT(Level2()));

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn3()));
    //QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
    //catalyst = new Bullet();


    show();

}
//New enemies will move slightly faster with more of them.
//towards the end there will be an item drop
void Game::Level2()
{
    qDebug("ahahahha level2 baby");
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn3()));
    timer->start(2000);

    show();
}
//enemies movements must be non-linear
//an extra life should drop
void Game::Level3()
{
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn3()));
    timer->start(2000);

    show();
}

/*
 * The boss fight goes below. It is almost entirely movement based.
 * The boss should have 3-6 movement patterns.
 * The boss should have 3-6 attack patterns.
 * Defeating the boss should send the player to a final scene.
 */










