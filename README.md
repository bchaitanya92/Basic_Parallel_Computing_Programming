#  Parallel Computing Programming in C

<p align="center">
  <img src="https://img.shields.io/badge/C-Programming-blue?logo=c" alt="C">
  <img src="https://img.shields.io/badge/MPI-Parallel%20Computing-9cf" alt="MPI">
  <img src="https://img.shields.io/badge/Ubuntu-Windows-ff69b4" alt="Multi-Platform">
</p>

<p align="center">
  <b>Comprehensive collection of parallel computing programs using MPI in C</b><br>
  <i>Learn and practice parallel programming concepts with practical examples</i>
</p>

---

##  Project Overview

This repository contains a curated set of C programs demonstrating parallel computing concepts using MPI (Message Passing Interface). The programs are organized by operating system (Ubuntu and Windows) and cover fundamental parallel programming techniques.

---

##  Repository Structure

```
Basic_Parallel_Computing_Programming/
│
├── Ubuntu OS/                  # Programs for Ubuntu/Linux environment
│   ├── Fibonacci_Number.c
│   ├── Iteration_Scheduling_Static_Chunking.c
│   ├── MPI_Broadcast_Op.c
│   ├── MPI_Deadlock.c
│   ├── MPI_Reduce_AllReduce.c
│   ├── MPI_Scatter_Gather.c
│   ├── MPI_Send_and_Recev.c
│   ├── Parallel_Prime_No_Finder.c
│   └── SP_Merge_Sort.c
│
└── Window OS/                  # Programs for Windows environment
    ├── Fibonacci_Number.c
    ├── Iteration_Scheduling_Static_Chunking.c
    ├── MPI_Broadcast_Op.c
    ├── MPI_Deadlock.c
    ├── MPI_Reduce_AllReduce.c
    ├── MPI_Scatter_Gather.c
    ├── MPI_Send_and_Recev.c
    ├── Parallel_Prime_No_Finder.c
    └── SP_Merge_Sort.c
```

---

## 📋 Program List

| Program | Description |
|---------|-------------|
| **🔢 Fibonacci_Number** | Parallel implementation of Fibonacci number calculation |
| **⏱️ Iteration_Scheduling_Static_Chunking** | Demonstrates static iteration scheduling in parallel loops |
| **📡 MPI_Broadcast_Op** | Implementation of MPI broadcast operation |
| **⚠️ MPI_Deadlock** | Example demonstrating and resolving MPI deadlocks |
| **🔄 MPI_Reduce_AllReduce** | Implementation of reduce and all-reduce operations |
| **📊 MPI_Scatter_Gather** | Demonstrates scatter and gather operations |
| **📨 MPI_Send_and_Recev** | Basic point-to-point communication example |
| **🔢 Parallel_Prime_No_Finder** | Parallel prime number finder implementation |
| **🔀 SP_Merge_Sort** | Parallel implementation of merge sort algorithm |

---

## 🚀 Getting Started

### 📋 Prerequisites
- C compiler (GCC for Ubuntu, MSVC or MinGW for Windows)
- MPI implementation (OpenMPI, MPICH, or MS-MPI for Windows)

### 🐧 Compilation (Ubuntu/Linux)
```bash
mpicc program_name.c -o program_name
mpirun -np 4 ./program_name
```

🪟 Compilation (Windows)
```cmd
mpicc program_name.c -o program_name.exe
mpiexec -n 4 program_name.exe
```

---

## 📚 Learning Resources

1. **MPI Documentation**: [mpi-forum.org](https://www.mpi-forum.org/docs/)
2. **OpenMPI**: [open-mpi.org](https://www.open-mpi.org/)
3. **MPI Tutorial**: [MPI Tutorial](https://mpitutorial.com/)

---

## 👨‍💻 Author

<p>
  <b>B. Chaitanya</b> <br>
  <i>Parallel Computing Enthusiast</i> <br>
  <br>
  <b>GitHub:</b> <a href="https://github.com/bchaitanya92">bchaitanya92</a> <br>
  <b>LinkedIn:</b> <a href="https://www.linkedin.com/in/b-chaitanya">BOURISETTI CHAITANYA</a>
</p>

---

## 📜 License

This repository is intended for educational purposes. Feel free to use, modify, and distribute the code as needed.

---

<p align="center">
  <i>Happy Parallel Programming! </i>
</p>