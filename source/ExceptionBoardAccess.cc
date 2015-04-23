#include "ExceptionBoardAccess.h"

ExceptionBoardAccess::ExceptionBoardAccess(){
    sErrorMessage = "Board dimensions succeeded.";
};

ExceptionBoardAccess::ExceptionBoardAccess(unsigned int icol, unsigned int irow,
    unsigned int iC, unsigned int iR){

    sErrorMessage = "Board dimensions succeeded.";
    sErrorMessage += " Possible indices are (row,col) in [0,1,...," \
        + std::to_string(iR-1) + "] x [0,1,...," + std::to_string(iC-1) + "]\n";
    sErrorMessage += " but it was tried (row, col) = (" + std::to_string(irow) \
        + ", " + std::to_string(irow) + ").";
}; 

ExceptionBoardAccess::~ExceptionBoardAccess() throw() {

};

const char* ExceptionBoardAccess::what() const throw() { 
    return this->sErrorMessage.c_str(); 
}
