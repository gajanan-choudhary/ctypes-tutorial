cmake_minimum_required(VERSION 2.8.9)
project(binarytree)

#Bring the headers, such as Student.h into the project
#include_directories("${CMAKE_SOURCE_DIR}/include/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "binarytree/*.c")

##########################################################################
# Debug options
# Build options to determine what level of debugging we are using
set(binarytreeDEBUG "OFF")
set(BUILD_DEBUG_LEVEL "0" CACHE STRING "0: None  1: -g  2: -g + _DEBUG")
# Determine if we are using some debugging
if(BUILD_DEBUG_LEVEL LESS 0 OR BUILD_DEBUG_LEVEL GREATER 2)
    message(FATAL_ERROR "BUILD_DEBUG_LEVEL parameter must be an integer value of the range 0 to 2, inclusive.")
elseif(BUILD_DEBUG_LEVEL EQUAL 1)
    add_definitions(-g)
elseif(BUILD_DEBUG_LEVEL EQUAL 2)
    add_definitions(-D_DEBUG -g )
    set(binarytreeDEBUG "ON")
endif(BUILD_DEBUG_LEVEL LESS 0 OR BUILD_DEBUG_LEVEL GREATER 2)

##########################################################################
# Executable
list(FILTER SOURCES EXCLUDE REGEX ".*binarytree/main.c$")
add_library(binarytree_obj OBJECT ${SOURCES})
add_library(binarytree_static STATIC $<TARGET_OBJECTS:binarytree_obj>)
add_executable(${PROJECT_NAME} "binarytree/main.c")
target_link_libraries(${PROJECT_NAME} binarytree_static)

################################################################################################
# These are for creating binarytree shared library for use with Python interface.
# Tested only on gcc for now.
##########################################################################
option(MAKE_SHARED_LIBRARY "Create an binarytree shared library to allow interfacing with python" OFF)
if(MAKE_SHARED_LIBRARY)
  ## Create binarytree library
  #list(APPEND LIBRARY_SOURCES ${SOURCES})
  #list(REMOVE_ITEM LIBRARY_SOURCES "main.c")

  add_definitions(-fPIC) # Position independence required for use with Python
  add_library(binarytree_shared SHARED $<TARGET_OBJECTS:binarytree_obj>)

  set(PROJECT_PYTHON_DIR ${PROJECT_SOURCE_DIR}/pybinarytree/)
  set(pybuildfile "${PROJECT_PYTHON_DIR}/build_options.py")
  file(WRITE ${pybuildfile} "#!/usr/bin/env python\n")

  file(APPEND ${pybuildfile} "\"\"\"\nCMAKE generated critical python file to enforce compatibility\n")
  file(APPEND ${pybuildfile} "between C binarytree library structures and python class definitions.\n\"\"\"\n")

  file(APPEND ${pybuildfile} "\nfrom ctypes import cdll\n")
  file(APPEND ${pybuildfile} "\nfrom define_h import ON, OFF\n")

  file(APPEND ${pybuildfile} "\n__all__ = [\n")
  file(APPEND ${pybuildfile} "          'pybtlib',\n")
  #file(APPEND ${pybuildfile} "          'pybintree_path',\n")
  #file(APPEND ${pybuildfile} "          'libbintree_path',\n")
  file(APPEND ${pybuildfile} "          'BUILD_DEBUG_LEVEL',\n")
  file(APPEND ${pybuildfile} "          '_DEBUG',\n")
  file(APPEND ${pybuildfile} "          'ON',\n")
  file(APPEND ${pybuildfile} "          'OFF',\n")
  file(APPEND ${pybuildfile} "          ]\n")

  file(APPEND ${pybuildfile} "\npybintree_path      = '${PROJECT_SOURCE_DIR}'\n")
  file(APPEND ${pybuildfile}   "libbintree_path     = '${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libbinarytree_shared.so'\n")
  file(APPEND ${pybuildfile} "\nBUILD_DEBUG_LEVEL   = ${BUILD_DEBUG_LEVEL}\n")
  file(APPEND ${pybuildfile}   "_DEBUG              = ${binarytreeDEBUG}\n")

  file(APPEND ${pybuildfile} "\npybtlib = cdll.LoadLibrary(libbintree_path)\n")

  file(APPEND ${pybuildfile} "\n\nif (__name__ == '__main__'):\n")
  file(APPEND ${pybuildfile} "    print '_DEBUG            =', _DEBUG\n")

endif(MAKE_SHARED_LIBRARY)
################################################################################################

