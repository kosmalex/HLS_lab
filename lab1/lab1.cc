#include <iostream>

#include "tasks.hh"

short a[2][2]={
  {3, 4},
  {7, 98}
};

short rs[2];

int a1[7] = {3, 2, 9, 6, 4, 3, 1};

int main(int argc, char** argv){
  //printf("%s: %d\n", argv[1], checksum(std::__cxx11::stoi(argv[1])));
  
  //compute_row_sum<2, 2>(a, rs);
  wave_sort<7>(a1);
  for(int i : a1)
    printf("%d\n", i);
  
  return 0;
}
