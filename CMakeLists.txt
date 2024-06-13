cmake_minimum_required(VERSION 3.10)

# Set the project name and languages
project(Raytracing LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify the C++ compiler explicitly
set(CMAKE_CXX_COMPILER C:/msys64/ucrt64/bin/gcc.exe)

# Add the executable target
add_executable(Raytracing main.cc)

# Link against the standard C++ library
target_link_libraries(Raytracing stdc++)
