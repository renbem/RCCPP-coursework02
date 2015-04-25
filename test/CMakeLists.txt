#author: Michael Ebner
#date: April 2015

set( EXEC_NAME "conwaysGameOfLife_UnitTests" )

#***automatically fill the PROJ_SOURCES with the sources available in the source-folder
# FILE( GLOB_RECURSE PROJ_SOURCES *.cc ) 
#***alternatively every single file:
set( PROJ_SOURCES
    "main_UnitTests.cc"
    "../source/Cell.cc"
    "../source/Board.cc"
    "../source/Game.cc"
    "../source/MyException.cc"
    "../source/ExceptionCommandLine.cc"
    "../source/ExceptionBoardAccess.cc"
    )

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin) 

add_executable( ${EXEC_NAME} ${PROJ_SOURCES} )
target_link_libraries( ${EXEC_NAME} ${Boost_LIBRARIES} )