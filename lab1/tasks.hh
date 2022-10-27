//Task 1
unsigned short count_ones(unsigned int a){
  int i = 1;
  unsigned short counter = 0;

  for(int j=0; j<32; j++){
    counter += (a & i) >> j;
    i <<= 1;
  }

  return counter;
}

//Task 2
unsigned int add_digits(unsigned int a){
  unsigned int acum = 0;

  while(true){
    acum += a % 10;
    a /= 10;
    if(a <= 0) break;
  }

  return acum;
}

unsigned int resolve(unsigned int a){
  a *= 2;
  
  if(a > 10)
    return add_digits(a);
  else
    return a;
}

unsigned int checksum(unsigned int number){
  unsigned int checksum = 0;
  bool flag = false;
  unsigned int digit = 0;

  while(true){
    digit = number % 10;
    checksum += flag ? resolve(digit) : digit;
    
    //Loop control
    number /= 10;
    flag = !flag;
    if(number <= 0) break;
  }

  return checksum;
}

//Task 3
template<int N, int M>
void compute_row_sum(short a[N][M], short row_sum[N]){
  for(int i=0; i<N; i++){
    row_sum[i] = 0;
    for(int j=0; j<M; j++)
      row_sum[i] += a[i][j];
  }
}

//Task 4
void swap(int* arr, int idx_1, int idx_2){
  int temp = arr[idx_1];
  arr[idx_1] = arr[idx_2];
  arr[idx_2] = temp;
}

void bubble_sort(int* arr, int N){
  for(int i=0; i<N-1; i++)
    for(int j=0; j<N-i-1; j++){
      if(arr[j] > arr[j+1])
        swap(arr, j, j+1);
    }
}

template<int N>
void wave_sort(int a[N]){
  bubble_sort(a, N);

  for(int i=0; i<N; i+=2)
    swap(a, i, i+1);
}
