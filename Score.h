#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase(int amount);
    int getScore();

    int get_e_killed(){return e_killed; }
    int get_m_killed(){return m_killed; }
    int get_h_killed(){return h_killed; }
    bool get_boss_killed(){return boss_killed; }

    void increase_e_kill(){e_killed++; };
    void increase_m_kill(){m_killed++; };
    void increase_h_kill(){h_killed++; };
    void set_boss_killed(){boss_killed = true; };
private:
    int score;
    int e_killed;
    int m_killed;
    int h_killed;
    bool boss_killed;
};

#endif // SCORE_H
