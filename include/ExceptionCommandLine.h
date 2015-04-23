#ifndef EXCEPTIONCOMMANDLINE_H_
#define EXCEPTIONCOMMANDLINE_H_

#include <iostream>
#include <exception>

class ExceptionCommandLine : public std::exception{
public:
    ExceptionCommandLine();
    ExceptionCommandLine(std::string str); 
    ~ExceptionCommandLine() throw();
    const char* what() const throw();

private:
    std::string sErrorMessage;
}; 

#endif /* EXCEPTIONCOMMANDLINE_H_ */