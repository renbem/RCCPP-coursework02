/**
 * \brief Implementation of the board class.
 *
 * Board represents the grid of the game.
 *
 * \author Michael Ebner
 * \date April 2015
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
// #include <cstdio>
#include <sstream>
#include <vector>
// #include <iterator>

#include "Cell.h"
#include "MyException.h"
#include "ExceptionBoardAccess.h"


class Board{
public:
    Board(std::string infile);
    // Board(unsigned int rows, unsigned int cols);
    ~Board();
    void dispBoard(); //display on screen
    void saveBoard(std::string outfile); // write into file
    unsigned int getRows(); //return number of rows (i.e. row-dimension)
    unsigned int getColumns(); //return number of columns
    bool getStatusOfBoardCell(unsigned int, 
        unsigned int);
    std::vector<Cell> determineNeighbourCells(unsigned int, unsigned int);
    void applyTransitionRules(unsigned int, unsigned int, std::vector<Cell>);

private:
    unsigned int irows;
    unsigned int icolumns;
    std::vector<std::vector<Cell> > board;
    void readBoardFromFile(std::string infile);
};

#endif  /* BOARD_H_ */