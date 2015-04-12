#include "Board.h"

//***Constructor
// Board::Board(std::string infile) : rows(5),columns(5){}
Board::Board(std::string infile){
    readBoardFromFile(infile);
}

// Board::Board(const Board& board) : rows(5),columns(5){}
Board::Board(unsigned int rows, unsigned int cols){
    Cell *c = new Cell;
    std::vector<Cell> tmp(cols,*c);
    std::vector<std::vector<Cell> >  bboard(rows,tmp);

    this->board = bboard;
    this->irows = rows;
    this->icolumns = cols;
}

//***Destructor
Board::~Board(){

}

void Board::dispBoard(){
    for (int row = 0; row < this->irows; ++row){
        std::cout << "|";

        for (int col = 0; col < this->icolumns; ++col){        
            board[row][col].dispCell();
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

void Board::saveBoard(){

}

unsigned int Board::getRows(){
    return this->irows;
}

unsigned int Board::getColumns(){
    return this->icolumns;
}

void Board::readBoardFromFile(std::string infile){
    std::string sdir = "../../Source/Testing/ConwaysGameOfLifeData/";

    std::ifstream input(sdir+infile);

    if (!input.is_open()) {
        throw MyException("Cannot open the file to read.");
    }
    
    std::string line;
    std::string sfoo;

    std::vector<std::vector<Cell> > bBoard; 
    std::vector<Cell> tmp;
    Cell *c = new Cell;
        
    //***Fill board:   
    try{
        while (!input.eof()) {
            getline(input, line);
            std::istringstream iss(line);

            std::cout << line << std::endl;

            while (iss >> sfoo){
                c->setStatus(stoi(sfoo));
                tmp.push_back(*c);
            }

            bBoard.push_back(tmp);
            tmp.clear();
        }
    }
    catch(MyException &e){
        std::cerr << e.what() << std::endl;
    }
    
    this->irows = bBoard.size();
    this->icolumns = bBoard[0].size();

    // std::cout << "rows = " << irows << std::endl;
    // std::cout << "columns = " << icolumns << std::endl;

    this->board = bBoard;
}

unsigned int Board::determineNumberOfNeighboursAlive(unsigned int irow, unsigned int icol, unsigned int irows, unsigned int icolumns){

    unsigned int numberOfNeighboursAlive = 0;

    return numberOfNeighboursAlive;
}