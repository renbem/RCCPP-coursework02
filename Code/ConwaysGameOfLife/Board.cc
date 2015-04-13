#include "Board.h"

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

unsigned int Board::getElementFrom2D(unsigned int irow, unsigned int icol){
    return icol*(this->irows) + irow;
}

unsigned int Board::determineNumberOfNeighboursAlive(unsigned int irow, 
    unsigned int icol){

    unsigned int numberOfNeighboursAlive = 0;

    unsigned int M = this->irows;
    unsigned int N = this->icolumns;
    std::vector<unsigned int> neighbours;


    //***Find neighbour cells:
    //******First outer left column:
    if(icol == 0){
        if(irow == 0){
            //Standard:
            neighbours.push_back(getElementFrom2D(irow+1, icol));
            neighbours.push_back(getElementFrom2D(irow+1, icol+1));
            neighbours.push_back(getElementFrom2D(irow, icol+1));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(M-1, 1));
            neighbours.push_back(getElementFrom2D(M-1, 0));
            neighbours.push_back(getElementFrom2D(M-1, N-1));
            neighbours.push_back(getElementFrom2D(0, N-1));
            neighbours.push_back(getElementFrom2D(1, N-1));
        }
        else if(irow == M-1){
            //Standard:
            neighbours.push_back(getElementFrom2D(irow, icol+1));
            neighbours.push_back(getElementFrom2D(irow-1, icol+1));
            neighbours.push_back(getElementFrom2D(irow-1, icol));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(M-2, N-1));
            neighbours.push_back(getElementFrom2D(M-1, N-1));
            neighbours.push_back(getElementFrom2D(0, N-1));
            neighbours.push_back(getElementFrom2D(0, 0));
            neighbours.push_back(getElementFrom2D(0, 1));
        }
        else{
            //Standard:
            neighbours.push_back(getElementFrom2D(irow+1, icol));
            neighbours.push_back(getElementFrom2D(irow+1, icol+1));
            neighbours.push_back(getElementFrom2D(irow, icol+1));
            neighbours.push_back(getElementFrom2D(irow-1, icol+1));
            neighbours.push_back(getElementFrom2D(irow-1, icol));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(irow-1, N-1));
            neighbours.push_back(getElementFrom2D(irow, N-1));
            neighbours.push_back(getElementFrom2D(irow+1, N-1));
        }
    }
    //******Last outer right column:
    else if(icol == N-1){
        if(irow == 0){
            //Standard:
            neighbours.push_back(getElementFrom2D(irow, icol-1));
            neighbours.push_back(getElementFrom2D(irow+1, icol-1));
            neighbours.push_back(getElementFrom2D(irow+1, icol));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(1, 0));
            neighbours.push_back(getElementFrom2D(0, 0));
            neighbours.push_back(getElementFrom2D(M-1, 0));
            neighbours.push_back(getElementFrom2D(M-1, N-1));
            neighbours.push_back(getElementFrom2D(M-1, N-2));
        }
        else if(irow == M-1){
            //Standard:
            neighbours.push_back(getElementFrom2D(irow-1, icol));
            neighbours.push_back(getElementFrom2D(irow-1, icol-1));
            neighbours.push_back(getElementFrom2D(irow, icol-1));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(0, N-2));
            neighbours.push_back(getElementFrom2D(0, N-1));
            neighbours.push_back(getElementFrom2D(0, 0));
            neighbours.push_back(getElementFrom2D(M-1, 0));
            neighbours.push_back(getElementFrom2D(M-2, 0));
        }
        else{
            //Standard:
            neighbours.push_back(getElementFrom2D(irow-1, icol));
            neighbours.push_back(getElementFrom2D(irow-1, icol-1));
            neighbours.push_back(getElementFrom2D(irow, icol-1));
            neighbours.push_back(getElementFrom2D(irow, icol+1));
            neighbours.push_back(getElementFrom2D(irow+1, icol-1));

            //Periodic Boundary:
            neighbours.push_back(getElementFrom2D(irow-1, 0));
            neighbours.push_back(getElementFrom2D(irow, 0));
            neighbours.push_back(getElementFrom2D(irow+1, 0));
        }
    }
    //******Top row: (Corners are already covered above)
    else if(irow == 0){       
        //Standard:
        neighbours.push_back(getElementFrom2D(irow, icol-1));
        neighbours.push_back(getElementFrom2D(irow+1, icol-1));
        neighbours.push_back(getElementFrom2D(irow+1, icol));
        neighbours.push_back(getElementFrom2D(irow+1, icol+1));
        neighbours.push_back(getElementFrom2D(irow, icol+1));

            //Periodic Boundary:
        neighbours.push_back(getElementFrom2D(M-1, icol+1));
        neighbours.push_back(getElementFrom2D(M-1, icol));
        neighbours.push_back(getElementFrom2D(M-1, icol-1));
    }
    //******Bottom row: (Corners are already covered above)
    else if(irow == M-1){       
        //Standard:
        neighbours.push_back(getElementFrom2D(irow, icol+1));
        neighbours.push_back(getElementFrom2D(irow-1, icol+1));
        neighbours.push_back(getElementFrom2D(irow-1, icol));
        neighbours.push_back(getElementFrom2D(irow-1, icol-1));
        neighbours.push_back(getElementFrom2D(irow, icol-1));

        //Periodic Boundary:
        neighbours.push_back(getElementFrom2D(0, icol-1));
        neighbours.push_back(getElementFrom2D(0, icol));
        neighbours.push_back(getElementFrom2D(0, icol+1));
    }
    //******Inner board:
    else{
        //Standard:
        neighbours.push_back(getElementFrom2D(irow, icol+1));
        neighbours.push_back(getElementFrom2D(irow-1, icol+1));
        neighbours.push_back(getElementFrom2D(irow-1, icol));
        neighbours.push_back(getElementFrom2D(irow-1, icol-1));
        neighbours.push_back(getElementFrom2D(irow, icol-1));
        neighbours.push_back(getElementFrom2D(irow+1, icol-1));
        neighbours.push_back(getElementFrom2D(irow+1, icol));
        neighbours.push_back(getElementFrom2D(irow+1, icol+1));
    }

    // printf("neighbours(%i, %i):\n", irow, icol);
    // for (int i = 0; i < 8; ++i)
    // {
    //     printf("   (%i)\n", neighbours[i]);
    // }

    // printf("Cell (%i, %i):\n", irow, icol);

    //***Compute number of alive neighbours cells:
    for (int i = 0; i < 8; ++i){
        //***Complete bullshit to do it like that:
        unsigned int r = neighbours[i]%M;
        unsigned int c = (neighbours[i]-r)/M;

        // printf("   (r, c) = (%i, %i)\n", r,c);

        if(this->board[r][c].getStatus()){
            numberOfNeighboursAlive++;
        }
    }

return numberOfNeighboursAlive;
}

void Board::applyTransitions(unsigned int irow, unsigned int icol, unsigned numberOfNeighboursAlive){

    // printf("Cell (%i,%i): numberOfNeighboursAlive = %i\n", 
    //     irow,icol,numberOfNeighboursAlive);

    //***Live cell:
    if( this->board[irow][icol].getStatus() ){
        if( 
            numberOfNeighboursAlive == 0 ||
            numberOfNeighboursAlive == 1 ||
            numberOfNeighboursAlive > 3
            ){

            this->board[irow][icol].setStatus(0);
        }
    }
    else{
        if (numberOfNeighboursAlive == 3){
            this->board[irow][icol].setStatus(1);
        }
    }
}