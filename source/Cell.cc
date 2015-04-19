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

int Cell::unitTest_getValue(){
    return this->unitTest_value;
}

void Cell::setStatus(int stat){
    this->unitTest_value = stat;

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
std::string Cell::saveCell(){
    if(this->status){
        return "1";
    }
    else{
        return "0";
    }
}