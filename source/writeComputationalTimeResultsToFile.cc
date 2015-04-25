/**
 * \brief Implementation of the function writeComputationalTimeResultsToFile.
 *
 * writeComputationalTimeResultsToFile writes the measured computational time
 * into a txt-file which can be used for further processing.
 *
 * \author Michael Ebner
 * \date April 2015
 */
 
#include "writeComputationalTimeResultsToFile.h"

void writeComputationalTimeResultsToFile(std::vector<double> elapsedTime,
    std::string outfile){

    const int iterations = elapsedTime.size()-1; //first line contains 0

    std::ofstream output(outfile);

    if(!output.is_open()){
        throw MyException("Cannot open the file to write");
    }

    output << "iteration \t" << "elapsedTime" << std::endl;
    for (int i=0; i<iterations+1; i++){
        output << i << "\t" << elapsedTime[i] << std::endl;
    }
}