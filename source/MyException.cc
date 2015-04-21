#include "MyException.h"

MyException::MyException(const char *msg) : sErrorMessage(msg) {

}; 

MyException::~MyException() throw() {

};

const char* MyException::what() const throw() { 
    return this->sErrorMessage.c_str(); 
}
