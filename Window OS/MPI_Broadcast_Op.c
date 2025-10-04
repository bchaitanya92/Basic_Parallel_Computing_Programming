'''
How to run Program ?

Click Build on codeblocks only → Build or press Ctrl+F9
This will create an .exe file inside your project bin\Debug folder.
Go to your project folder (e.g. OneDrive\Desktop\Parallel-programs\Program7\bin\Debug) based on where you saved your program.
You’ll find something like: main.exe or FileName.exe for example (Program7.exe)
Open Command Prompt.
Navigate to Your .exe Location (eg: cd OneDrive\Desktop\Parallel-programs\Program7\bin\Debug) based on where you saved your program.
Type command to run the program: mpiexec -n 4 FileName.exe for example (Program7.exe).
'''

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        number = 50;
        printf("Process %d broadcasting number %d to all other processes.\n", rank, number);
    }

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, number);

    MPI_Finalize();
    return 0;
}