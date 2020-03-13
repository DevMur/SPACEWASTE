#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "MyRect.h"
#include "PewGun.h"
#include "Enemy.h"

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

void MyRect::spawn()
{
    Enemy *crug = new Enemy();
    scene()->addItem(crug);
}
