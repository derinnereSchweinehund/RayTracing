cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(RayTracing VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenMP
find_package(OpenMP REQUIRED)

# Add the executable
add_executable(RayTracing main.cpp)

# Include directories
target_include_directories(RayTracing PRIVATE ${CMAKE_SOURCE_DIR})

# Link against OpenMP
target_link_libraries(RayTracing PRIVATE OpenMP::OpenMP_CXX)
