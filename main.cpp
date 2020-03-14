#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
//#include <QGraphicsItem>
#include "MyRect.h"
#include "PewGun.h"

int main(int argc, char *argv[])
{
    // create scene
    QApplication a(argc, argv);

    //create an item for the scene.
    QGraphicsScene * scene = new QGraphicsScene();
    
    //player sprite should be a singleton ship object
    MyRect * player = new MyRect(); //length and width of 0 (default)
    player->setRect(0,0,50,50); // top left , bottom right

    //game start scene / initialization
    //the ship is the focus of the user and their input
    scene->addItem(player); //item added to scene.
    player->setFlag(QGraphicsItem::ItemIsFocusable); //the ship is what 
    player->setFocus();
    player->grabKeyboard();


    //add view, used the scene as the parameter because nothing spawns off 
    //screen at gamestart, bosses and items may spawn at start or in a new 
    //scene (at least bosses may).
    QGraphicsView * view = new QGraphicsView(scene);

    //select the size of the window and the scene.
    view->setFixedSize(800, 800);
    scene->setSceneRect(0,0, 800, 800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //a little redundant? 
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //player was moved to the center to better understand how the view vs scene works
    //this method is used as a more conventional way to restart lives/the game.

    //make the player the center. 
    //Will have to change calls here
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height());

    //
    /*
        this is where testing of enemies and guns will take place
        right now it is obstacles (level 1/3) and gun (level 1/3)
    */
    //
    QTimer * enemy_timer = new QTimer;
    QObject::connect(enemy_timer, SIGNAL(timeout()), player, SLOT(spawn()));
    enemy_timer->start(2000);

    //run the stuff
    view->show();
    return a.exec();
}
