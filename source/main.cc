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
#include <chrono>

#include "Game.h"
#include "MyException.h"
#include "writeComputationalTimeResultsToFile.h"
#include "readCommandLine.h"
  

int main(int argc, char** argv){
	try{
        const bool flagDisplayGame = false;
        const bool flagDisplayComputationalTime = false;
        
        //***Parse input of command line
        std::vector<std::string> input = readCommandLine(argc, argv);

        //***Check for empty vector ==> It was given "--help" in command line
        if( input[0] == "help request" ){
            return EXIT_SUCCESS;
        }

        //***Read input data of command line
        std::string sfileInitialBoard = input[0];
        std::string sfileGameHistory = input[1];
        unsigned int imaximumNumberOfSteps = stoi(input[2]);

        sfileInitialBoard = sfileInitialBoard;
        sfileGameHistory = sfileGameHistory;

        //***Create game
		Game *game = new Game(sfileInitialBoard);

        if(flagDisplayGame){
            system("clear");            //Clear display
            printf("Iteration %d of %d:\n",0,imaximumNumberOfSteps);       
            game->dispCurrentBoard();
        }
    

        //***Compute propagation of cells:
        unsigned int itr = 1;
    	std::vector<double> elapsedSeconds(imaximumNumberOfSteps+1);
        elapsedSeconds[0] = 0.;

        while(itr <= imaximumNumberOfSteps){
            //***Measure time: Start
            auto start = std::chrono::system_clock::now();

            //***Compute subsequent board of Conways Game of Life
            game->computeNextStep();
	
            //***Measure time: Stop
            auto end = std::chrono::system_clock::now();
	        std::chrono::duration<double> diff = end-start;
            elapsedSeconds[itr] = elapsedSeconds[itr-1] + diff.count();

            //***Display computational time on screen if desired:
            if(flagDisplayComputationalTime){
                printf("Iteration %d of %d: Computational time = %f s\n", 
                    itr, imaximumNumberOfSteps, elapsedSeconds[itr]);
            }

            //***Display results on screen if desired:
            if(flagDisplayGame){
                sleep(1);
                system("clear");            //Clear display
                printf("Iteration %d of %d:\n",itr,imaximumNumberOfSteps);       
                game->dispCurrentBoard();
            }
	   
            itr++;
        }
	
        printf("Total time = %f s\n", elapsedSeconds[imaximumNumberOfSteps]); 
        std::string str = sfileGameHistory;
        str.resize(str.size()-4);
        writeComputationalTimeResultsToFile(elapsedSeconds, 
            str+"_ComputationalTime.txt");
        // writeComputationalTimeResultsToFile(elapsedSeconds,"computationalTime.txt"); 

        //***Save history of game:
        game->saveGameHistory(sfileGameHistory);

	}
	catch(std::exception& e) {
		std::cerr << "error: " << e.what() << "\n";
        // std::cout << "EXIT_FAILURE = " << EXIT_FAILURE << std::endl;
		return EXIT_FAILURE;
	}
    
    // std::cout << "EXIT_SUCCESS = " << EXIT_SUCCESS << std::endl;
	return EXIT_SUCCESS;
}

