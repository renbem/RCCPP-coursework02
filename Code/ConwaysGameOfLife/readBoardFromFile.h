#ifndef READBOARDFROMFILE_H_
#define READBOARDFROMFILE_H_

#include <stdlib.h>
#include <string>
#include <iostream>

#include "MyException.h"
#include <iterator>
#include <fstream>

Eigen::MatrixXd readFileIntoMatrix(std::string infile);
 
#endif /* READBOARDFROMFILE_H_ */