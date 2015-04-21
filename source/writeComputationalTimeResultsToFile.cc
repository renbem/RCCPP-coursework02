#include <iostream>
#include <fstream>

#include "writeComputationalTimeResultsToFile.h"
#include "MyException.h"

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