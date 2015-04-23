/*============================================================================

  research-computing-with-cpp-demo: CMake based demo code.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

============================================================================*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <unistd.h>
// #include <string>
// #include <iostream>
// #include <stdio.h>

#include "Game.h"
#include "Board.h"
#include "Cell.h"
#include "MyException.h"
#include "ExceptionCommandLine.h"
#include "ExceptionBoardAccess.h"

unsigned int getElementFrom2D(unsigned int irow, unsigned int icol, unsigned int iR){
    return icol*iR + irow;
}

//Code from: http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
// std::string exec(char* cmd) {
//     FILE* pipe = popen(cmd, "r");
//     if (!pipe) return "ERROR";
//     char buffer[128];
//     std::string result = "";
//     while(!feof(pipe)) {
//         if(fgets(buffer, 128, pipe) != NULL)
//             result += buffer;
//     }
//     pclose(pipe);
//     return result;
// }

TEST_CASE( "Check whether file for input read is given", 
  "[Not existing txt-file]") {
    std::string sdir = "../exampleData/";

    REQUIRE_THROWS_AS(Game *game = new Game(sdir+"nofile.txt"), MyException);
}

TEST_CASE( "Test 1 of Board::determineNeighbourCells", 
    "[determine Neighbours inner board]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int irow = 5;
    unsigned int icol = 5;

    std::vector<Cell>neighbourCells = board.determineNeighbourCells(irow, icol);

    REQUIRE( neighbourCells[0].unitTest_getValue()
        == getElementFrom2D(irow, icol+1, iR) );
    REQUIRE( neighbourCells[1].unitTest_getValue()
        == getElementFrom2D(irow-1, icol+1, iR) );
    REQUIRE( neighbourCells[2].unitTest_getValue() 
        == getElementFrom2D(irow-1, icol, iR) );
    REQUIRE( neighbourCells[3].unitTest_getValue()
        == getElementFrom2D(irow-1, icol-1, iR) );
    REQUIRE( neighbourCells[4].unitTest_getValue() 
        == getElementFrom2D(irow, icol-1, iR) );
    REQUIRE( neighbourCells[5].unitTest_getValue() 
        == getElementFrom2D(irow+1, icol-1, iR) );
    REQUIRE( neighbourCells[6].unitTest_getValue() 
        == getElementFrom2D(irow+1, icol, iR) );
    REQUIRE( neighbourCells[7].unitTest_getValue()
        == getElementFrom2D(irow+1, icol+1, iR) );
}

TEST_CASE( "Test 2 of Board::determineNeighbourCells", 
    "[determine Neighbours upper left corner]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int iC = board.getColumns();
    unsigned int irow = 0;
    unsigned int icol = 0;

    std::vector<Cell>neighbourCells = board.determineNeighbourCells(irow, icol);

    REQUIRE( neighbourCells[0].unitTest_getValue()
        == getElementFrom2D(irow, icol+1, iR) );
    REQUIRE( neighbourCells[1].unitTest_getValue()
        == getElementFrom2D(iR-1, icol+1, iR) );
    REQUIRE( neighbourCells[2].unitTest_getValue() 
        == getElementFrom2D(iR-1, icol, iR) );
    REQUIRE( neighbourCells[3].unitTest_getValue()
        == getElementFrom2D(iR-1, iC-1, iR) );
    REQUIRE( neighbourCells[4].unitTest_getValue() 
        == getElementFrom2D(irow, iC-1, iR) );
    REQUIRE( neighbourCells[5].unitTest_getValue() 
        == getElementFrom2D(irow+1, iC-1, iR) );
    REQUIRE( neighbourCells[6].unitTest_getValue() 
        == getElementFrom2D(irow+1, icol, iR) );
    REQUIRE( neighbourCells[7].unitTest_getValue()
        == getElementFrom2D(irow+1, icol+1, iR) );
}

TEST_CASE( "Test 3 of Board::determineNeighbourCells", 
    "[determine Neighbours bottom left corner]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int iC = board.getColumns();
    unsigned int irow = iR-1;
    unsigned int icol = 0;

    std::vector<Cell>neighbourCells = board.determineNeighbourCells(irow, icol);

    REQUIRE( neighbourCells[0].unitTest_getValue()
        == getElementFrom2D(irow, icol+1, iR) );
    REQUIRE( neighbourCells[1].unitTest_getValue()
        == getElementFrom2D(irow-1, icol+1, iR) );
    REQUIRE( neighbourCells[2].unitTest_getValue() 
        == getElementFrom2D(irow-1, icol, iR) );
    REQUIRE( neighbourCells[3].unitTest_getValue()
        == getElementFrom2D(irow-1, iC-1, iR) );
    REQUIRE( neighbourCells[4].unitTest_getValue() 
        == getElementFrom2D(irow, iC-1, iR) );
    REQUIRE( neighbourCells[5].unitTest_getValue() 
        == getElementFrom2D(0, iC-1, iR) );
    REQUIRE( neighbourCells[6].unitTest_getValue() 
        == getElementFrom2D(0, icol, iR) );
    REQUIRE( neighbourCells[7].unitTest_getValue()
        == getElementFrom2D(0, icol+1, iR) );
}


TEST_CASE( "Test 4 of Board::determineNeighbourCells", 
    "[determine Neighbours bottom right corner]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int iC = board.getColumns();
    unsigned int irow = iR-1;
    unsigned int icol = iC-1;

    std::vector<Cell>neighbourCells = board.determineNeighbourCells(irow, icol);

    REQUIRE( neighbourCells[0].unitTest_getValue()
        == getElementFrom2D(irow, 0, iR) );
    REQUIRE( neighbourCells[1].unitTest_getValue()
        == getElementFrom2D(irow-1, 0, iR) );
    REQUIRE( neighbourCells[2].unitTest_getValue() 
        == getElementFrom2D(irow-1, icol, iR) );
    REQUIRE( neighbourCells[3].unitTest_getValue()
        == getElementFrom2D(irow-1, icol-1, iR) );
    REQUIRE( neighbourCells[4].unitTest_getValue() 
        == getElementFrom2D(irow, icol-1, iR) );
    REQUIRE( neighbourCells[5].unitTest_getValue() 
        == getElementFrom2D(0, icol-1, iR) );
    REQUIRE( neighbourCells[6].unitTest_getValue() 
        == getElementFrom2D(0, icol, iR) );
    REQUIRE( neighbourCells[7].unitTest_getValue()
        == getElementFrom2D(0, 0, iR) );
}

TEST_CASE( "Test 5 of Board::determineNeighbourCells", 
    "[determine Neighbours upper right corner]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int iC = board.getColumns();
    unsigned int irow = 0;
    unsigned int icol = iC-1;

    std::vector<Cell>neighbourCells = board.determineNeighbourCells(irow, icol);

    REQUIRE( neighbourCells[0].unitTest_getValue()
        == getElementFrom2D(irow, 0, iR) );
    REQUIRE( neighbourCells[1].unitTest_getValue()
        == getElementFrom2D(iR-1, 0, iR) );
    REQUIRE( neighbourCells[2].unitTest_getValue() 
        == getElementFrom2D(iR-1, icol, iR) );
    REQUIRE( neighbourCells[3].unitTest_getValue()
        == getElementFrom2D(iR-1, icol-1, iR) );
    REQUIRE( neighbourCells[4].unitTest_getValue() 
        == getElementFrom2D(irow, icol-1, iR) );
    REQUIRE( neighbourCells[5].unitTest_getValue() 
        == getElementFrom2D(irow+1, icol-1, iR) );
    REQUIRE( neighbourCells[6].unitTest_getValue() 
        == getElementFrom2D(irow+1, icol, iR) );
    REQUIRE( neighbourCells[7].unitTest_getValue()
        == getElementFrom2D(irow+1, 0, iR) );
}

TEST_CASE( "Access of cell beyond board dimensions", 
    "[Board Access]" ) {

    std::string sdir = "../exampleData/";
    Board board = Board(sdir+"UnitTest_NumberedBoard.txt");

    unsigned int iR = board.getRows();
    unsigned int iC = board.getColumns();

    REQUIRE( board.getStatusOfBoardCell(0,0) == false );
    REQUIRE( board.getStatusOfBoardCell(1,0) == true );
    REQUIRE_THROWS_AS( board.getStatusOfBoardCell(iR,1) , ExceptionBoardAccess);
    REQUIRE_THROWS_AS( board.getStatusOfBoardCell(iR,iC) , ExceptionBoardAccess);
    REQUIRE_THROWS_AS( board.getStatusOfBoardCell(1,iC) , ExceptionBoardAccess);
    REQUIRE_THROWS_AS( board.getStatusOfBoardCell(-1,1) , ExceptionBoardAccess);

}

TEST_CASE( "Test one step of Conways Game of Life", 
    "[One step of CGoL]" ) {

    std::string sdir = "../exampleData/";
    
    Game game = Game(sdir+"UnitTest_InitialBoard.txt");
    game.computeNextStep();
    Board updatedBoard = game.getCurrentBoard();

    Board updatedBoard_comparison = Board(sdir+"UnitTest_InitialBoard_Transition.txt");

    unsigned int iR = updatedBoard.getRows();
    unsigned int iC = updatedBoard.getColumns();

    for (int irow = 0; irow < iR; ++irow){
        for (int icol = 0; icol < iC; ++icol){
            REQUIRE( updatedBoard.getStatusOfBoardCell(irow,icol) 
                == updatedBoard_comparison.getStatusOfBoardCell(irow,icol));
        }        
    }
}

TEST_CASE( "Malformed command line", "[Command line]" ) {

    REQUIRE( system("../../bin/conwaysGameOfLife --help") == EXIT_SUCCESS );

    //***Would like to ask for '== EXIT_FAILURE' but return value of
    //***system() in Mac gives 255 back whereas EXIT_FAILURE = 1 (wtf!?)
    REQUIRE( system("../../bin/conwaysGameOfLife") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --i '../exampleData/InitialBoardRandom_10Times10.txt' \
        --o '../exampleData/out.txt' \
        --s 1 \
        ") == EXIT_SUCCESS );

    //***output file now already given and shall not be overwritten:
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --i '../exampleData/InitialBoardRandom_10Times10.txt' \
        --o '../exampleData/out.txt' \
        --s 1 \
        ") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --i '../exampleData/InitialBoardRandom_10Times10.txt' \
        --o '../exampleData/out.txt' \
        --s 10000 \
        ") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --i '../exampleData/InitialBoardRandom_10Times10.txt' \
        --s 10 \
        ") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --o '../exampleData/out.txt' \
        --s 10000 \
        ") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
    REQUIRE( system("../../bin/conwaysGameOfLife \
        --i '../exampleData/InitialBoardRandom_10Times10.txt' \
        --o '../exampleData/out.txt' \
        ") != EXIT_SUCCESS );

    system("rm ../exampleData/out*.txt");
}
