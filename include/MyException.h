#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_

#include <iostream>
#include <exception>

class MyException : public std::exception{
public:
    MyException(const char *msg); 
    ~MyException() throw();
    const char* what() const throw();

private:
    const std::string sErrorMessage;
}; 

#endif /* MYEXCEPTION_H_ */