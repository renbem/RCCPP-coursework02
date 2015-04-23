#ifndef EXCEPTIONBOARDACCESS_H_
#define EXCEPTIONBOARDACCESS_H_

#include <iostream>
#include <exception>

class ExceptionBoardAccess : public std::exception{
public:
    ExceptionBoardAccess();
    ExceptionBoardAccess(unsigned int, unsigned int, unsigned int, unsigned int); 
    ~ExceptionBoardAccess() throw();
    const char* what() const throw();

private:
    std::string sErrorMessage;
}; 

#endif /* EXCEPTIONBOARDACCESS_H_ */