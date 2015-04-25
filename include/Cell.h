/**
 * \brief Implementation of the cell class.
 *
 * Cell represents the status of dead or alive.
 *
 * \author Michael Ebner
 * \date April 2015
 */

#ifndef CELL_H_
#define CELL_H_

#include <iostream>

class Cell{
public:
    Cell();
    Cell(bool status);
    ~Cell();
    bool getStatus();
    void setStatus(int );
    void dispCell();
    std::string saveCell();

    //Just for unit test to check neighbours. One could get around this hack by
    //defining the status not as boolean but using, for example, integers. E.g.
    //define 0 => false and integers>0 => true.
    int unitTest_getValue(); 
private:
    bool status;
    int unitTest_value;
};

#endif  /* CELL_H_ */