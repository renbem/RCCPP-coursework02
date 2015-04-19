######################################################################
# Set the minimum CMake version.
######################################################################
if(WIN32)
  cmake_minimum_required(VERSION 3.1)
else()
  cmake_minimum_required(VERSION 2.8.9)
endif()

######################################################################
# Define project.
######################################################################
set( PROJ_NAME "ConwaysGameOfLife" )
project( ${PROJ_NAME} )

######################################################################
# Make sure Git is available.
######################################################################
find_package(Git REQUIRED)
if (WIN32)
  set(GITCOMMAND ${GIT_EXECUTABLE})
endif()

######################################################################
# Find Boost.
######################################################################
set(Boost_NO_SYSTEM_PATHS ON)
if (Boost_NO_SYSTEM_PATHS)
  set(BOOST_ROOT "/opt/local/include/")
endif (Boost_NO_SYSTEM_PATHS)
if(BUILD_SHARED_LIBS)
  set(Boost_USE_STATIC_LIBS OFF)
else()
  set(Boost_USE_STATIC_LIBS ON)
endif()
find_package( Boost COMPONENTS filesystem system date_time regex thread iostreams program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

######################################################################
# Actual project.
######################################################################

include_directories(include)
include_directories(test/catch)

#***Some important CMAKE variables:
#CMAKE_SOURCE_DIR refers to the root source directory containing (this) CMakeLists.txt file
#CMAKE_BINARY_DIR points to the current build directory

#***Specify location for all generated executables:
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 

#***Directories with additional CMakeLists.txt:
add_subdirectory(source)
add_subdirectory(test)
