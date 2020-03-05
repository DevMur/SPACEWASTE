
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>

//qgraphicsscene, map of the world
//qgraphicsitem, only items and subclasses can be used in scenes
//qgraphicsrectitem
//qgraphicsview, widget to visualize the scene and background
//qkeyevent what key was pressed
//qdebug, console printing
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create scene
    QGraphicsScene * scene = new QGraphicsScene();
    //create an item for the scene.
    QGraphicsRectItem * rect = new QGraphicsRectItem(); //length and width of 0 (default)
    rect->setRect(0,0,100,100); // top left , bottom right

    scene->addItem(rect); //item added to scene.

    //add view
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();



    return a.exec();
}
