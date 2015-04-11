#ifndef CELL_H_
#define CELL_H_

class Cell{
public:
    Cell(const bool& stat);
    ~Cell();
    bool getStatus();

private:
    const bool status;
};

#endif  /* CELL_H_ */