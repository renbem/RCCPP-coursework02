#ifdef __linux
    #include <omp.h>
#endif

#include "Game.h"

//***Constructor
Game::Game(std::string infile){
    
    Board board(infile);

    this->boardHistory.push_back(board);
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

    #ifdef __linux
        // #pragma omp parallel for private(neighbourCells)
    #endif
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


void Game::dispCurrentBoard(){
    Board currentBoard = boardHistory.back();

    // std::cout << "\n";
    // std::cout << "Current iteration = " << boardHistory.size() -1;
    // std::cout << " (rows = " << currentBoard.getRows();
    // std::cout << ", columns = " << currentBoard.getColumns() << ")";
    // std::cout << "\n";

    currentBoard.dispBoard();
}

Board Game::getCurrentBoard(){
    return boardHistory.back();
}

void Game::saveGameHistory(std::string outfile){
    unsigned int inumberOfSteps = this->boardHistory.size();

    // std::remove(outfile.c_str()); //delete file

    std::ofstream output(outfile);

    if(!output.is_open()){
        throw MyException("Cannot write file.");
    }

    output << inumberOfSteps << std::endl;

    output.close();

    for (int i = 0; i < inumberOfSteps; ++i){
        Board b = this->boardHistory[i];
        b.saveBoard(outfile);
    }
    
}

std::vector<Board> Game::getBoardHistory(){ 
    return this->boardHistory;
}

void Game::pushBoard(Board board){
    this->boardHistory.push_back(board);
}
