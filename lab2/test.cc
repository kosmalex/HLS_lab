#include <iostream>

template<int N>
void bin_search(int arr[N], int target, bool& found, int& pos){
  int l=0, r=N;
  int m = -1;
  
  while(true){
    m = (l+r)>>1;
    
    if(arr[m] == target) {
      target = arr[m];
      pos = m;
      found = 1;
      return; 
    }

    if(target > arr[m]){
      l = m;
    }else{
      r = m;
    }

    if(l == r-1) break;
  }
}

int main(int argc, char* argv[]){
  int arr[8] = {0, 1, 4, 33, 412, 7321, 42312, 241432};
  int target = 42312;
  
  bool found = 0;
  int pos = -1;
  
  bin_search<8>(arr, target, found, pos);
  
  for(int i : arr) std::cout << i << " ";
  std::cout << "\n";

  if(found)
    std::cout << "I found " << target  << " @pos " << pos << "\n";
  else
    std::cout << "Nothing found\n";

 return 0;
}
