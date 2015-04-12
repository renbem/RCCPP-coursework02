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
#include <Eigen/Dense>
// #include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>

#include "Game.h"
#include "MyException.h"
// #include <itkImage.h>

namespace po = boost::program_options;
  
int main(int argc, char** argv){
  // // Check Eigen is correctly included.
  // Eigen::MatrixXd m(2,2);
  // m(0,0) = 3;
  // m(1,0) = 2.5;
  // m(0,1) = -1;
  // m(1,1) = m(1,0) + m(0,1);
  // std::cout << m << std::endl;

  // // Check Boost is correctly included.
  // std::cout << "The number 10.0 converted to string is " << boost::lexical_cast<std::string>(10.0) << std::endl;

  // // Check Boost libraries are correctly included.
  // boost::program_options::options_description desc("Allowed options");
  // desc.add_options()
  //     ("help", "produce help message")
  // ;

	try{
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
			return 0;
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

		Game *game = new Game(sfileInitialBoard);
        game->dispStateOfGame();
        
        game->computeNextStep();
        game->dispStateOfGame();


	}
	catch(std::exception& e) {
		std::cerr << "error: " << e.what() << "\n";
		return 1;
	}
    
	return EXIT_SUCCESS;
}

