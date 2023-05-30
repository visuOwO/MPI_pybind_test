import mpi4py
from hello import Hello
from mpi4py import MPI

mpi4py.rc.threaded = True
mpi4py.rc.thread_level = "funneled"

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()
print("[Python] Hello from rank %d of %d" % (rank, size))
a = Hello()
a.test_MPI()
