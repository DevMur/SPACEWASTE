#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "MyRect.h"
#include "PewGun.h"
#include "Enemy.h"
//must include the sprite (rect) 
//      the weapons
//      


void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << event->key(); //add limits to either end of the screen
    if (event->key() == Qt::Key_A)
    {
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_D)
    {
        setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        //find the weapon being used and use the weapon
        //pew gun to start
        PewGun * pew_gun = new PewGun();
        pew_gun->setPos(x(), y());
        scene()->addItem(pew_gun);
    }
}

//this is currently here for immediate use
//it should exist in the gamestate class
//Enemy.h can be switched out for each enemy and boss
//spawn may also be used for weapon / point drops
//would still exist in the gamestate, not the player
void MyRect::spawn()
{
    Enemy *crug = new Enemy();
    scene()->addItem(crug);
}
