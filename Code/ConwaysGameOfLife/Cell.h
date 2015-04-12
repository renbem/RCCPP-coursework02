#ifndef CELL_H_
#define CELL_H_

#include <iostream>

class Cell{
public:
    Cell();
    Cell(bool stat);
    ~Cell();
    bool getStatus();
    void setStatus(int );
    void dispCell();

private:
    bool status;
};

#endif  /* CELL_H_ */