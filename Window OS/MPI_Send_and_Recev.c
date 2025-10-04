'''
How to run Program ?

Click Build on codeblocks only → Build or press Ctrl+F9
This will create an .exe file inside your project bin\Debug folder.
Go to your project folder (e.g. OneDrive\Desktop\Parallel-programs\Program5\bin\Debug) based on where you saved your program.
You’ll find something like: main.exe or FileName.exe for example (Program5.exe)
Open Command Prompt.
Navigate to Your .exe Location (eg: cd OneDrive\Desktop\Parallel-programs\Program5\bin\Debug) based on where you saved your program.
Type command to run the program: mpiexec -n 2 FileName.exe for example (Program5.exe).
'''

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            printf("Please run with at least 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        number = 100;
        printf("Process %d sending number %d to process 1\n", rank, number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received number %d from process 0\n", rank, number);
    }

    MPI_Finalize();
    return 0;
}