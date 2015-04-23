#ifndef CELL_H_
#define CELL_H_

#include <iostream>

class Cell{
public:
    Cell();
    Cell(bool stat);
    ~Cell();
    bool getStatus();
    int unitTest_getValue();          //Just for unit test to check neighbours
    void setStatus(int );
    void dispCell();
    std::string saveCell();

private:
    bool status;
    int unitTest_value;
};

#endif  /* CELL_H_ */