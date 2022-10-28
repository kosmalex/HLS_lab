#include <iostream>

#include "tasks.hh"

static const int dim = 2;

short A[dim][dim];
short rs[dim];

static const int length = 7;
int B[7];

int main(int argc, char** argv){
  srand(time(NULL));

#ifdef TASK1
  char* a = new char[500];
  while(true){
    printf("Enter a number (q --> quit): "); std::cin >> a;
    if(*a == 81 || *a == 113) break;
    try{
      int Ia = std::__cxx11::stoi(a);
      printf("Number %d has %u ones\n\n", Ia, count_ones(Ia));
    }catch(...){
      printf("[ERROR]: Something wrong with the provided input. Mind integer size.\n\n");
    }
  }
  delete a;
#endif

#ifdef TASK2
char* a = new char[500];
  while(true){
    printf("Enter a number (q --> quit): "); std::cin >> a;
    if(*a == 81 || *a == 113) break;
    try{
      unsigned int Ia = std::__cxx11::stoi(a);
      printf("Checksum of %u is %u\n\n", Ia, checksum(Ia));
    }catch(...){
      printf("[ERROR]: Something wrong with the provided input. Mind integer size.\n\n");
    }
  }
  delete a;
#endif

#ifdef TASK3
  printf("\nChange dimension in lab1.cc file\n");
  printf("Matrix:\n");
  for(short* row : A){
    for(int i=0; i<dim; i++){
      row[i] = rand() % 32765; //(2 << 14) - 1
      printf("%d ", row[i]);
    }
    printf("\n");
  }

  compute_row_sum<dim, dim>(A, rs);
  
  printf("\nIf something is negative overflow happend. Not a valid result.\n");
  printf("RowSums:\n");
  for(short i : rs)
    printf("%d\n", i);
#endif

#ifdef TASK4
  printf("\nChange size of array in lab1.cc file\n");
  for(int i=0; i<length; i++)
    B[i] = rand() % 100;

  printf("Before SORT:\n");
  for(int i : B)
    printf("%d\n", i);
  
  wave_sort<length>(B);

  printf("\nAfter SORT:\n");  
  for(int i : B)
    printf("%d\n", i);
#endif

  return 0;
}
