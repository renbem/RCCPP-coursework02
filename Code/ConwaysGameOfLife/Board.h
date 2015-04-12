#ifndef BOARD_H_
#define BOARD_H_

#include <stdlib.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
// #include <iterator>

#include "Cell.h"
#include "MyException.h"


class Board{
public:
    Board(std::string infile);
    Board(unsigned int rows, unsigned int cols);
    ~Board();
    void dispBoard();
    void saveBoard();
    unsigned int getRows();
    unsigned int getColumns();
    unsigned int determineNumberOfNeighboursAlive(unsigned int, unsigned int, unsigned int, unsigned int);

private:
    unsigned int irows;
    unsigned int icolumns;
    std::vector<std::vector<Cell> > board;
    void readBoardFromFile(std::string infile);
};

#endif  /* BOARD_H_ */