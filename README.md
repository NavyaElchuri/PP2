# PP2
Parallel processing program 2.

The provided code consists of a custom barrier function called mybarrier, which is utilized within an MPI program. The program initializes MPI, performs some computations before and after synchronization, and demonstrates the effectiveness of the custom barrier function. The ‘mybarrier’ function calculates the number of steps required for synchronization based on the logarithm of the total number of processes. It then utilizes a binary tree structure to synchronize processes. In each step, processes exchange dummy messages with their partner processes using MPI's MPI_Send and MPI_Recv functions. This ensures that processes reach the synchronization point in an efficient manner. The main program initializes MPI, obtains process ranks, and performs some computation before calling the custom mybarrier function. After synchronization, it resumes computation and prints progress messages.
