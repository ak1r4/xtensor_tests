cmake_minimum_required(VERSION 3.6)

project(xtensor-demo)

find_package(pybind11 REQUIRED)
find_package(xtensor REQUIRED)
find_package(NumPy REQUIRED)
include_directories(${NUMPY_INCLUDE_DIRS})

pybind11_add_module(xtensor_python_test xtensor_python_test.cpp)
target_link_libraries(xtensor_python_test PUBLIC xtensor)

add_executable(xtensor_test xtensor_test.cpp)
target_link_libraries(xtensor_test xtensor)
