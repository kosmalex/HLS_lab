#include <iostream>
#include "ac_int.h"

#include "cs_smverify.h"

template<int N>
void CCS_BLOCK(bin_search)(ac_int<4, false> arr[N], int target, bool& found, int& pos){
  int l=0, r=N;
  int m = -1;
  
  while(true){
    m = (l+r)>>1;
    
    if(l - r == 1) break;
    
    if(arr[m] == target) {
      target = arr[m];
      pos = m;
      found = true;
      return; 
    }

    if(target > arr[m]){
      l = m;
    }else{
      r = m;
    }
  }
}

CCS_MAIN(int argc, char* argv[]){
  ac_int<4, false> arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  bool found;
  int pos;
 
  bin_search<10>(arr, 8, found, pos);

  std::cout << "Found " << target << " @pos " << pos << "\n";
  
  CCS_RETURN(0);
}
