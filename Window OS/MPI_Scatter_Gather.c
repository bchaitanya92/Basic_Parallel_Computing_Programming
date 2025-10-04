'''
How to run Program ?

Click Build on codeblocks only → Build or press Ctrl+F9
This will create an .exe file inside your project bin\Debug folder.
Go to your project folder (e.g. OneDrive\Desktop\Parallel-programs\Program8\bin\Debug) based on where you saved your program.
You’ll find something like: main.exe or FileName.exe for example (Program8.exe)
Open Command Prompt.
Navigate to Your .exe Location (eg: cd OneDrive\Desktop\Parallel-programs\Program8\bin\Debug) based on where you saved your program.
Type command to run the program: mpiexec -n 4 FileName.exe for example (Program8.exe).
'''

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int send_data[100], recv_data, gathered_data[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            send_data[i] = i * 10;
        }
    }

    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    recv_data = recv_data + rank;
    MPI_Gather(&recv_data, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Gathered data in root process:\n");
        for (int i = 0; i < size; i++) {
            printf("gathered_data[%d] = %d\n", i, gathered_data[i]);
        }
    }

    MPI_Finalize();
    return 0;
}