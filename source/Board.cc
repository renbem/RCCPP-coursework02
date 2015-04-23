#include "Board.h"
#include "ExceptionBoardAccess.h"

//***Constructor
// Board::Board(std::string infile) : rows(5));columns(5){}
Board::Board(std::string infile){
    readBoardFromFile(infile);
}

// Board::Board(const Board& board) : rows(5));columns(5){}
// Board::Board(unsigned int rows, unsigned int cols){
//     Cell *c = new Cell;
//     std::vector<Cell> tmp(cols,*c);
//     std::vector<std::vector<Cell> >  bboard(rows,tmp);

//     this->board = bboard;
//     this->irows = rows;
//     this->icolumns = cols;
// }

//***Destructor
Board::~Board(){

}

void Board::dispBoard(){
    for (int row = 0; row < this->irows; ++row){
        // std::cout << "|";

        for (int col = 0; col < this->icolumns; ++col){        
            board[row][col].dispCell();
            // std::cout << "|";
        }
        std::cout << "\n";
    }
}

void Board::saveBoard(std::string outfile){
    std::ofstream output(outfile, 
        std::ofstream::out | std::ofstream::app);

    if(!output.is_open()){
        throw MyException("Cannot write file.");
    }

    for (int ir = 0; ir < this->irows; ir++){
        for (int ic = 0; ic < this->icolumns; ic++){
            output << this->board[ir][ic].saveCell();
            if(ic < this->icolumns-1){
                output << "\t";
            }
        }
     
        output << "\n";
    }
}

unsigned int Board::getRows(){
    return this->irows;
}

unsigned int Board::getColumns(){
    return this->icolumns;
}

bool Board::getStatusOfBoardCell(unsigned int irow, 
    unsigned int icol){

    if( irow > this->irows-1 || icol > this->icolumns-1 ){
        throw ExceptionBoardAccess(irow, icol, irows, icolumns);
    }

    return this->board[irow][icol].getStatus();
}

void Board::readBoardFromFile(std::string infile){
    std::ifstream input(infile);

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

            // std::cout << line << std::endl;

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

std::vector<Cell> Board::determineNeighbourCells(unsigned int irow, 
    unsigned int icol){

    std::vector<Cell> neighbourCells;

    unsigned int iR = this->irows;
    unsigned int iC = this->icolumns;

    //***Fetch neighbour cells by regarding periodic boundary conditions
    unsigned int irowTop = (irow-1+iR)%iR;
    unsigned int irowBottom = (irow+1)%iR;
    unsigned int icolLeft = (icol-1+iC)%iC;
    unsigned int icolRight = (icol+1)%iC;

    neighbourCells.push_back(this->board[irow][icolRight]);
    neighbourCells.push_back(this->board[irowTop][icolRight]);
    neighbourCells.push_back(this->board[irowTop][icol]);
    neighbourCells.push_back(this->board[irowTop][icolLeft]);
    neighbourCells.push_back(this->board[irow][icolLeft]);
    neighbourCells.push_back(this->board[irowBottom][icolLeft]);
    neighbourCells.push_back(this->board[irowBottom][icol]);
    neighbourCells.push_back(this->board[irowBottom][icolRight]);

    return neighbourCells;
}

void Board::applyTransitionRules(unsigned int irow, unsigned int icol, 
    std::vector<Cell> neighbourCells){

    unsigned int numberOfNeighboursAlive = 0;

    for (int i = 0; i < 8; ++i){
        if(neighbourCells[i].getStatus()){
            numberOfNeighboursAlive++;
        }
    }

    // printf("Cell (%i,%i): numberOfNeighboursAlive = %i\n", 
    //     irow,icol,numberOfNeighboursAlive);

    //***Live cell:
    if( this->board[irow][icol].getStatus() ){
        if( 
            numberOfNeighboursAlive < 2 ||
            numberOfNeighboursAlive > 3
            )
        {
            this->board[irow][icol].setStatus(0);
        }
    }
    else{
        if (numberOfNeighboursAlive == 3){
            this->board[irow][icol].setStatus(1);
        }
    }
}