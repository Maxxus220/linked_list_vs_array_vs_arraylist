cmake_minimum_required(VERSION 3.26.4)

project(comparison)

set(CMAKE_CXX_COMPILER g++)

set(COMPARISON_SOURCES 
    ./src/main.cpp 
    ./src/ordered_array.cpp 
    ./src/ordered_array_list.cpp 
    ./src/ordered_linked_list.cpp
)

add_executable("${PROJECT_NAME}" "${COMPARISON_SOURCES}") 
