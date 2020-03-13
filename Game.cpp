#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
//#include <QGraphicsItem>
#include "MyRect.h"
#include "PewGun.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create scene
    QGraphicsScene * scene = new QGraphicsScene();
    //create an item for the scene.

    MyRect * player = new MyRect(); //length and width of 0 (default)
    player->setRect(0,0,50,50); // top left , bottom right

    scene->addItem(player); //item added to scene.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->grabKeyboard();


    //add view
    QGraphicsView * view = new QGraphicsView(scene);
    //select the size of the window and the scene.
    view->setFixedSize(800, 800);
    scene->setSceneRect(0,0, 800, 800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//player was moved to the center to better understand how the view vs scene works
    //this method is used as a more conventional way to restart lives/the game.

    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height());


    QTimer * enemy_timer = new QTimer;
    QObject::connect(enemy_timer, SIGNAL(timeout()), player, SLOT(spawn()));
    enemy_timer->start(2000);

    view->show();
    return a.exec();
}
