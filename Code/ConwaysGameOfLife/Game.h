#ifndef GAME_H_
#define GAME_H_

#include <stack>
#include "Board.h"
#include "Cell.h"

class Game{
public:
    Game(std::string infile);
    ~Game();
    void computeNextStep();
    void dispStateOfGame();
    void saveGameHistory();

private:
    void pushBoard(Board board);
    std::stack<Board> boardHistory;
    Cell applyRules(unsigned int numberOfNeighboursAlive);
};

#endif  /* GAME_H_ */