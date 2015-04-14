/*============================================================================

  research-computing-with-cpp-demo: CMake based demo code.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

============================================================================*/

#include <cstdlib>
#include <iostream>
#include <string>


// #include <Eigen/Dense>
// #include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>

#include "Game.h"
#include "MyException.h"
// #include <itkImage.h>

namespace po = boost::program_options;

std::vector<std::string> readCommandLine(int argc, char** argv){

    std::vector<std::string> input;

    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("i", po::value< std::vector<std::string> >(), 
        "specify input txt-file for initilizing the game, \n"
        "e.g. --i \"InitialBoard.txt\"")
    ("o", po::value< std::vector<std::string> >(), 
        "specify output txt-file for the game history, \n"
        "e.g. --o \"GameHistory.txt\"")
    ("s", po::value<int>(), 
        "specify number of maximal steps.\n"
        "e.g. --s 20")
    ;

    po::variables_map vm;        
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    std::string sfileInitialBoard;
    std::string sfileGameHistory;
    int imaximumNumberOfSteps;

    bool errorflag = false;

    std::cout << "------------------------------------------------------" 
    << "----------------------------" << std::endl;

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return input; //return empty vector
    }

    if (vm.count("i")) {
        std::cout << "Input file given (" 
            << vm["i"].as< std::vector<std::string> >()[0] << ").\n";
        sfileInitialBoard = vm["i"].as< std::vector<std::string> >()[0];
    } 
    else {
        std::cout << "Input file for NOT given.\n";
        errorflag = true;
    }

    if (vm.count("o")) {
        std::cout << "Output file for game history given (" 
            << vm["o"].as< std::vector<std::string> >()[0] << ").\n";

    sfileGameHistory = vm["o"].as< std::vector<std::string> >()[0];
    } 
    else {
        std::cout << "Output file for game history NOT given.\n";
        errorflag = true;
    }

    if (vm.count("s")) {
        std::cout << "Number of steps of game given (" 
            << vm["s"].as<int>() << ").\n";

        imaximumNumberOfSteps = vm["s"].as<int>();
    } 
    else {
        std::cout << "Number of steps of game NOT given.\n";
        errorflag = true;
    }

    std::cout << "------------------------------------------------------" 
    << "----------------------------" << std::endl;

    if(errorflag){
        throw MyException("Input data not complete. " 
            "Please type 'conwaysGameOfLife --help'");
    }

    input.push_back(sfileInitialBoard);
    input.push_back(sfileGameHistory);
    input.push_back(std::to_string(imaximumNumberOfSteps));

    return input;
}
  



int main(int argc, char** argv){
	try{
        const bool flagDisplayGame = false;
        std::string sdir = "../../Source/Testing/ConwaysGameOfLifeData/";
        
        //***Parse input of command line
        std::vector<std::string> input = readCommandLine(argc, argv);

        //***It was given: --help in command line
        if(input.size() == 0)
            return 0;

        //***Read input data of command line
        std::string sfileInitialBoard = input[0];
        std::string sfileGameHistory = input[1];
        unsigned int imaximumNumberOfSteps = stoi(input[2]);

        sfileInitialBoard = sdir+sfileInitialBoard;
        sfileGameHistory = sdir+sfileGameHistory;

        //***Create game
		Game *game = new Game(sfileInitialBoard);

        if(flagDisplayGame){
            system("clear");            //Clear display
            printf("Iteartion %d of %d:\n",0,imaximumNumberOfSteps);       
            game->dispStateOfGame();
        }
    
        //***Compute propagation of cells:
        unsigned int itr = 1;
        while(itr <= imaximumNumberOfSteps){
            game->computeNextStep();

            if(flagDisplayGame){
                sleep(1);
                system("clear");            //Clear display
                printf("Iteartion %d of %d:\n",itr,imaximumNumberOfSteps);       
                game->dispStateOfGame();
            }
            itr++;
        }       

        //***Save history of game:
        game->saveGameHistory(sfileGameHistory);

	}
	catch(std::exception& e) {
		std::cerr << "error: " << e.what() << "\n";
		return 1;
	}
    
	return EXIT_SUCCESS;
}

