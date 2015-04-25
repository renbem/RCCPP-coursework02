/**
 * \brief Implementation of the function writeComputationalTimeResultsToFile.
 *
 * writeComputationalTimeResultsToFile writes the measured computational time
 * into a txt-file which can be used for further processing.
 *
 * \author Michael Ebner
 * \date April 2015
 */

#ifndef WRITECOMPUTATIONALTIMERESULTSTOFILE_H_
#define WRITECOMPUTATIONALTIMERESULTSTOFILE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>

#include "MyException.h"

void writeComputationalTimeResultsToFile(std::vector<double> elapsedTime, 
    std::string outfile);

#endif  /* WRITECOMPUTATIONALTIMERESULTSTOFILE_H_ */