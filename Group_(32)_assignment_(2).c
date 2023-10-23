#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void mybarrier(MPI_Comm comm) {
    int rank, size;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    int mask = 1;

    while (mask < size) {
        int partner = rank ^ mask;
        
        // Determine whether to send or receive
        if (rank & mask) {
            // Receive from partner
            MPI_Recv(NULL, 0, MPI_INT, partner, 0, comm, MPI_STATUS_IGNORE);
        } else {
            // Send to partner
            MPI_Send(NULL, 0, MPI_INT, partner, 0, comm);
        }

        mask <<= 1; // Double the mask for the next iteration
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    MPI_Comm comm = MPI_COMM_WORLD;
    int rank;

    MPI_Comm_rank(comm, &rank);

    // Perform some computation before synchronization
    printf("Process %d is doing some work before barrier.\n", rank);

    // Call the custom barrier function
    mybarrier(comm);

    // Perform some computation after synchronization
    printf("Process %d is doing some work after barrier.\n", rank);

    MPI_Finalize();
    return 0;
}