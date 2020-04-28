#include "Menu.h"
#include <QBrush>
#include <QGraphicsTextItem>

Menu::Menu(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2 - text->boundingRect().height()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);
}

void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //qDebug("hover");
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::LinearGradientPattern);
    setBrush(brush);
}

void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setColor(Qt::darkMagenta);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}

