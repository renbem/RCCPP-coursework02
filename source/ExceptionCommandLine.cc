#include "ExceptionCommandLine.h"

ExceptionCommandLine::ExceptionCommandLine(){
    sErrorMessage = "Please type 'conwaysGameOfLife --help' for further help.";
};

ExceptionCommandLine::ExceptionCommandLine(std::string str){

    sErrorMessage = str;
    sErrorMessage += "\n       Please type 'conwaysGameOfLife --help' "
    "for further help.";
}; 

ExceptionCommandLine::~ExceptionCommandLine() throw() {

};

const char* ExceptionCommandLine::what() const throw() { 
    return this->sErrorMessage.c_str(); 
}
