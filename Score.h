#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
};
//Do I increase multiple times or does increase need a parameter.
//Does this change the view, I like to see my score iterate by 1... Is this possible
//is it even worth it. Calling a function potentially hundreds of times for a side piece
//may be too taxing.

#endif // SCORE_H
