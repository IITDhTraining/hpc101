#include <mpi.h>
#include <iostream>
#include <cmath>
#include <chrono>

int main(int argc, char * argv[]) {
	//code to measure time
  auto start = std::chrono::high_resolution_clock::now(); // start time

  int N = 1000000000; // iterating for a billion times
  double sum = 0; // variable to store the sum from each process
  double pi = 0; // variable to store the value of computed pi
  double delta_x = (double) 1 / N; // delta_x defined to be 1/N

  //MPI initialization sequence
  int rank, size;
  MPI_Init( & argc, & argv);
  MPI_Comm_rank(MPI_COMM_WORLD, & rank);
  MPI_Comm_size(MPI_COMM_WORLD, & size);

  for (int i = rank; i < N; i += size) {
    sum += delta_x * sqrt(1 - (i * delta_x) * (i * delta_x));
  }

  //TODO: fill-in code here.

  if (rank == 0) {
    
	//code to measure time
    auto end = std::chrono::high_resolution_clock::now(); // end time
    auto duration = std::chrono::duration_cast < std::chrono::microseconds > (end - start).count();
    printf("value of pi: %g\n", 4 * pi); // multiplying by 4 as the value computed in pi is 1/4th of the constant pi
    printf("time: %ld µs", duration); // print duration in microseconds
  }

  //TODO: fill-in code here.

  return 0;
}
