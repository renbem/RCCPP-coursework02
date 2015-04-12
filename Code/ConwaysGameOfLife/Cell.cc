#include "Cell.h"

//***Constructor

Cell::Cell(){
    this->status = false;
}

// Cell::Cell(const bool& status) : status(status){}
Cell::Cell(bool status){
    this->status = status;
}

//***Destructor
Cell::~Cell(){

}

bool Cell::getStatus(){
    return this->status;
}

void Cell::setStatus(int stat){
    if (stat > 0){
        this->status = true;
        // std::cout<<"true\n";
    }
    else{
        this->status = false;
        // std::cout<<"false\n";
    }
}

void Cell::dispCell(){
    if(this->status){
        std::cout << " x ";
    }
    else{
        std::cout << "   ";
    }
}