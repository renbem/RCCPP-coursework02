/**
 * \brief Implementation of the ExceptionBoardAccess class.
 *
 * ExceptionBoardClass deals with an attemped access to not allocated indices 
 * within the grid.
 *
 * \author Michael Ebner
 * \date April 2015
 */

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