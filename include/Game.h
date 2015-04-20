#ifndef GAME_H_
#define GAME_H_

#include <stack>
#include "Board.h"
#include <omp.h>

class Game{
public:
    Game(std::string infile);
    ~Game();
    void computeNextStep();
    void dispStateOfGame();
    void saveGameHistory(std::string outfile);

private:
    void pushBoard(Board board);
    std::vector<Board> boardHistory;
};

#endif  /* GAME_H_ */