# RCCPP-coursework02
Implementation of Conways Game of Life being part of the module "Research Computing with C++"

# Tested environment
The CMakeLists.txt file located in the parent directory was tested on two operating systems:

* OS X 10.10.3 (Macbook Pro, 2.5 GHz Intel Core i7): Only serial implementation
* Ubuntu 14.04 (Virtual machine via VirtualBox within OS X 10.10.3): Both serial or parallel implementation possible

# Build Instructions

In order to build the code run the following lines in the main directory:

    mkdir build
    cd build
    cmake ..
    make

Two binary files will be generated:

    build/bin/conwaysGameOfLife
    build/test/bin/conwaysGameOfLife_UnitTests
    
# Running the programme
For running the code several example data sets are provided in 
'build/test/exampleData/'. A possible command of the programme within the 
build-folder reads

    bin/conwaysGameOfLife --i "test/exampleData/InitialBoardRandom_10Times10.txt" --o "GameHistory.txt" --s 100
  
which uses the initial board defined in InitialBoardRandom_10Times10.txt and 
performs 100 steps of Conway's Game of Life. A concatenated history of all 
computed boards is then stored in GameHistory.txt and the information of the 
corresponding computational time per iteration is saved in 
GameHistory_ComputationalTime.txt.

To run the unit tests, execute the command

    ./conwaysGameOfLife_UnitTests
  
in build/test/bin/.

# Further details and results

A more detailed report of the coursework can be found in 
documentation/RCCPP_CW2_MichaelEbner.pdf and a generated Game of Life video 
based on the obtained results is located at 
https://www.youtube.com/watch?v=AeIm2I_9n5g&feature=youtu.be