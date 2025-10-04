'''
How to run Program ?

Click Build on codeblocks only → Build or press Ctrl+F9
This will create an .exe file inside your project bin\Debug folder.
Go to your project folder (e.g. OneDrive\Desktop\Parallel-programs\Program6\bin\Debug) based on where you saved your program.
You’ll find something like: main.exe or FileName.exe for example (Program6.exe)
Open Command Prompt.
Navigate to Your .exe Location (eg: cd OneDrive\Desktop\Parallel-programs\Program6\bin\Debug) based on where you saved your program.
Type command to run the program: mpiexec -n 2 FileName.exe for example (Program6.exe).
'''

#include <mpi.h>
#include <stdio.h>

// Change this to 1 for deadlock, 2 for deadlock avoidance
#define DEADLOCK_PART 2

int main(int argc, char *argv[]) {
    int rank, size, num = 123;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            printf("Run with at least 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

#if DEADLOCK_PART == 1
    // ----------- Part A: Deadlock -----------
    if (rank == 0) {
        printf("Process 0 waiting to receive from Process 1...\n");
        MPI_Recv(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        printf("Process 1 waiting to receive from Process 0...\n");
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

#elif DEADLOCK_PART == 2
    // ----------- Part B: Deadlock Avoidance -----------
    if (rank == 0) {
        MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received back number: %d\n", num);
    } else if (rank == 1) {
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 received and sent back number: %d\n", num);
    }
#endif

    MPI_Finalize();
    return 0;
}