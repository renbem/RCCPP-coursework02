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
#include "Game.h"
#include "Board.h"
#include "Cell.h"

unsigned int getElementFrom2D(unsigned int irow, unsigned int icol, unsigned int iR){
    return icol*iR + irow;
}

TEST_CASE( "Test 1 of Board::determineNeighbourCells", 
    "[determine Neighbours inner board]" ) {

    Board board = Board("TestBoardNumbered.txt");

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

    Board board = Board("TestBoardNumbered.txt");

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

    Board board = Board("TestBoardNumbered.txt");

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

    Board board = Board("TestBoardNumbered.txt");

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

    Board board = Board("TestBoardNumbered.txt");

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
