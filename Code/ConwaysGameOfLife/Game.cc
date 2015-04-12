#include "Game.h"

//***Constructor
Game::Game(std::string infile){
    Board* board = new Board(infile);

    this->boardHistory.push(*board);
}

//***Destructor
Game::~Game(){

}

void Game::computeNextStep(){
    Board currentBoard = boardHistory.top();

    unsigned int irows = currentBoard.getRows();
    unsigned int icolumns = currentBoard.getColumns();

    Board updatedBoard = Board(irows, icolumns);

    unsigned int numberOfNeighboursAlive = 0;

    // std::cout << "rows = " << updatedBoard.getRows() << std::endl;
    // std::cout << "columns = " << updatedBoard.getColumns() << std::endl;

    for (unsigned int row = 0; row < irows; ++row){
        for (unsigned int col = 0; col < icolumns; ++col){   
            numberOfNeighboursAlive
                = currentBoard.determineNumberOfNeighboursAlive(row,col,irows,icolumns);

            // updatedBoard[row][col] = this->applyRules(numberOfNeighboursAlive);

        }
        // std::cout << "\n";
    }


    pushBoard(updatedBoard);
}

void Game::dispStateOfGame(){
    Board currentBoard = boardHistory.top();

    std::cout << "\n";
    std::cout << "Current iteration = " << boardHistory.size() -1;
    std::cout << " (rows = " << currentBoard.getRows();
    std::cout << ", columns = " << currentBoard.getColumns() << ")";
    std::cout << "\n";

    currentBoard.dispBoard();
}

void Game::saveGameHistory(){

}

void Game::pushBoard(Board board){
    this->boardHistory.push(board);
}

Cell Game::applyRules(unsigned int numberOfNeighboursAlive){
    Cell *c = new Cell;

    return *c;
}