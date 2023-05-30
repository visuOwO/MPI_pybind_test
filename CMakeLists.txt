cmake_minimum_required(VERSION 3.25)
project(MPI_pybind_test)

find_package(PythonLibs)
include_directories(${PYTHON_INCLUDE_DIRS})
message(STATUS ${PYTHON_EXECUTABLE})

find_package(OpenMP)
find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})

include_directories(${MPI_INCLUDE_PATH})

add_subdirectory(pybind11)
pybind11_add_module(hello Hello.cpp)
target_link_libraries(hello PRIVATE mpi)

if (OpenMP_CXX_FOUND)
    target_link_libraries(hello PUBLIC OpenMP::OpenMP_CXX)
else ()
    message(FATAL_ERROR "OpenMP Not Found")
endif ()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.py
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)


