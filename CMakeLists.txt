#author: Michael Ebner
#date: April 2015

##############################################################################
# Change compiler to gcc instead of clang on Mac OS X.
##############################################################################
# Comment: Not used since boost clashed with gcc on Mac but clang
#          cannot be used with OpenMP

# if(APPLE)
#   message("Mac OS X: change compiler to gcc")
#   SET(CMAKE_C_COMPILER "/usr/bin/gcc")
#   SET(CMAKE_CXX_COMPILER "/usr/bin/g++")
# endif()

##############################################################################
# Set the minimum CMake version.
##############################################################################
if( WIN32 )
  cmake_minimum_required(VERSION 3.1)
else()
  cmake_minimum_required(VERSION 2.8.9)
endif()

##############################################################################
# Define project.
##############################################################################
set( PROJ_NAME "ConwaysGameOfLife" )
project( ${PROJ_NAME} )

##############################################################################
# Make sure Git is available.
##############################################################################
find_package(Git REQUIRED)
if (WIN32)
  set(GITCOMMAND ${GIT_EXECUTABLE})
endif()


##############################################################################
# Use C++11.
##############################################################################
# Comment:
# Used for measuring the elapsed time by using '#include <chrono>'
# By omitting this line, however, only warnings are thrown but code works

# if(COMPILER_SUPPORTS_CXX11) #does not work
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  message("USING -std=c++11")
# else()
#    message("NOT using -std=c++11")
# endif()

##############################################################################
# Find Boost.
##############################################################################
set(Boost_NO_SYSTEM_PATHS ON)
if (Boost_NO_SYSTEM_PATHS)
  if(APPLE)
    set(BOOST_ROOT "/opt/local/include/")   #Mac
    message("Mac OS X: Set BOOS_ROOT=${BOOST_ROOT}")
  elseif(UNIX)
    set(BOOST_ROOT "/usr/include/")       #Ubuntu
    message("Linux: Set BOOS_ROOT=${BOOST_ROOT}")
  endif()
endif (Boost_NO_SYSTEM_PATHS)
if(BUILD_SHARED_LIBS)
  set(Boost_USE_STATIC_LIBS OFF)
else()
  set(Boost_USE_STATIC_LIBS ON)
endif()
find_package( Boost COMPONENTS filesystem system date_time regex thread 
  iostreams program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

##############################################################################
# Find OpenMP.
##############################################################################
# Comment:
# Only works on Linux (tested on VM guest OS Ubuntu);
# On Mac it clashed with Boost. Therefore OpenMP got disabled for Mac.
# Respective includings in codes are guarded with '#ifdef __linux'

if (APPLE)
  message("OpenMP is not used on Mac OS X.")
else()
  find_package(OpenMP)
  if (OPENMP_FOUND)
    message (STATUS "OpenMP found")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -std=c++11")
  else()
    message (STATUS "OpenMP NOT found")
  endif()
endif()

##############################################################################
# Actual project.
##############################################################################
# Some important CMAKE variables:
# () CMAKE_SOURCE_DIR refers to the root source directory containing (this) 
#    CMakeLists.txt file
# () CMAKE_BINARY_DIR points to the current build directory

include_directories(include)
include_directories(test/catch)

#***Specify location for all generated executables:
# set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 

#***Directories with additional CMakeLists.txt:
add_subdirectory(source)
add_subdirectory(test)

##############################################################################
# Copy files into build folder.
##############################################################################

file(GLOB MY_COPY_FILES
  "test/data/UnitTest*"
  "test/data/InitialBoardRandom*"
)
file(COPY ${MY_COPY_FILES} DESTINATION ${CMAKE_BINARY_DIR}/test/exampleData)
