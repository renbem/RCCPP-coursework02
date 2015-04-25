/**
 * \brief Implementation of the game class.
 *
 * Game represents the grid of the game, incorporating all the boards.
 *
 * \author Michael Ebner
 * \date April 2015
 */

#ifndef GAME_H_
#define GAME_H_

// #include <stack>
#include "Board.h"

class Game{
public:
    Game(std::string infile);
    ~Game();
    void computeNextStep();
    void dispCurrentBoard();
    Board getCurrentBoard();
    void saveGameHistory(std::string outfile);
    std::vector<Board> getBoardHistory();

private:
    void pushBoard(Board board);
    std::vector<Board> boardHistory;
};

#endif  /* GAME_H_ */