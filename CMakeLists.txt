# CMakeLists.txt in the root directory
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the path to the header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Add the main program
add_executable(main_program src/main.cpp src/my_header.cpp)

# Add the subdirectory for the tests
add_subdirectory(tests)
