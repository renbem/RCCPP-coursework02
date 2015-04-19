
set( EXEC_NAME "conwaysGameOfLife" )

#***automatically fill the PROJ_SOURCES with the sources available in the source-folder
# FILE( GLOB_RECURSE PROJ_SOURCES *.cc ) 
#***alternatively every single file:
set( PROJ_SOURCES
    "main.cc"
    "Cell.cc"
    "Board.cc"
    "Game.cc"
    "MyException.cc"
    )

add_executable( ${EXEC_NAME} ${PROJ_SOURCES} )
target_link_libraries( ${EXEC_NAME} ${Boost_LIBRARIES} )