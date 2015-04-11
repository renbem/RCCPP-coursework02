#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"
#include <iostream>
#include <vector>

class Board{
public:
    Board(std::string infile);
    Board(const Board& board);
    ~Board();
    void dispBoard();
    void saveBoard();

private:
    const unsigned int rows;
    const unsigned int columns;
    std::vector<Cell> cellsOfBoard;
};

#endif  /* BOARD_H_ */