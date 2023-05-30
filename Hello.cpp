//
// Created by hld on 5/29/23.
//

#include "Hello.h"

namespace py = pybind11;

void Hello::Test() {
    printf("Hello!");
}

void Hello::OMP_Hello(int world_rank) {
#pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("Hello(%d) from thread %d of %d\n", world_rank, ID, omp_get_num_threads());
    }
}

void Hello::test_MPI() {
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    this->OMP_Hello(world_rank);
    MPI_Finalize();
}


PYBIND11_MODULE(hello, mmod)
{
    constexpr auto MODULE_DESCRIPTION = "Just testing out mpi with python.";
    mmod.doc() = MODULE_DESCRIPTION;
    py::class_<Hello>(mmod, "Hello")
            .def(py::init<>())
            .def("Test", &Hello::Test)
            .def("OMP_Hello", &Hello::OMP_Hello)
            .def("test_MPI", &Hello::test_MPI);
}
