#ifndef STATS_H_
#define STATS_H_

class Stats {
private:
    int Moves*;
public:
    Stats();
    ~Stats();
    void addMovePlayed();
    void getAllMovesPlayed();
    void getLastMovePlayed();
};

#endif // STATS_H_