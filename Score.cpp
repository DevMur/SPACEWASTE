#include <QFont>

#include "Score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    score = 0;

    e_killed = 0;
    m_killed = 0;
    h_killed = 0;
    boss_killed = false;

    // draw the text||REFORMAT
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int amount){
    score += amount;//works for crugs but needs to take an argument.
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
    //TODO format, it ugly
}

int Score::getScore(){
    return score;
}
