//
// Created by hld on 5/29/23.
//

#ifndef MPI_PYBIND_TEST_HELLO_H
#define MPI_PYBIND_TEST_HELLO_H

#include <mpi.h>
#include <pybind11/pybind11.h>
#include <stdio.h>
#include <omp.h>

using pymod = pybind11::module;


class Hello {
public:
    Hello() {}
    ~Hello() {}
    void Test();
    void OMP_Hello(int ID);
    void test_MPI();
};

#endif //MPI_PYBIND_TEST_HELLO_H
