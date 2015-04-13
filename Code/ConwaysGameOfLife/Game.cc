#include "Game.h"

//***Constructor
Game::Game(std::string infile){
    Board* board = new Board(infile);

    this->boardHistory.push_back(*board);
}

//***Destructor
Game::~Game(){

}

void Game::computeNextStep(){
    Board currentBoard = boardHistory.back();
    Board updatedBoard = currentBoard;

    unsigned int irows = currentBoard.getRows();
    unsigned int icolumns = currentBoard.getColumns();
    std::vector<Cell> neighbourCells;

    // std::cout << "rows = " << updatedBoard.getRows() << std::endl;
    // std::cout << "columns = " << updatedBoard.getColumns() << std::endl;

    for (unsigned int row = 0; row < irows; ++row){
        for (unsigned int col = 0; col < icolumns; ++col){   
            neighbourCells
                = currentBoard.determineNeighbourCells(row, col);
            updatedBoard.applyTransitionRules(row,col,neighbourCells);
        }
        // std::cout << "\n";
    }

    this->pushBoard(updatedBoard);
}

void Game::dispStateOfGame(){
    Board currentBoard = boardHistory.back();

    // std::cout << "\n";
    // std::cout << "Current iteration = " << boardHistory.size() -1;
    // std::cout << " (rows = " << currentBoard.getRows();
    // std::cout << ", columns = " << currentBoard.getColumns() << ")";
    // std::cout << "\n";

    currentBoard.dispBoard();
}

void Game::saveGameHistory(){

}

void Game::pushBoard(Board board){
    this->boardHistory.push_back(board);
}