#include <iostream>
#include <time.h>

#include "ac.h"

struct Point{
  UINT16 x, y;
};

inline UINT17 manhattan(const Point& a, const Point& b){
  UINT16 x_abs, y_abs;

  ac_math::ac_abs(a.x - b.x, x_abs);
  ac_math::ac_abs(a.y - b.y, y_abs);
  
  return x_abs + y_abs;
}

template <int N, int M>
bool kmeans(Point points[N], int ID[N], Point center[M]){
  POINTS: for(int i=0; i<N; i++){
      Point p = points[i];
      
      int closest_center_id = 0;
      UINT17 min_Md, temp_Md;
      DIST: for(int j=0; j<M; j++){
        if(j==0) min_Md = manhattan(p, center[j]);
        else{
            temp_Md = manhattan(p, center[j]);
            min_Md = (temp_Md < min_Md) ? temp_Md : min_Md;
            closest_center_id = (temp_Md < min_Md) ? j : closest_center_id;
        }// if
      }// DIST
      
      ID[N] = closest_center_id;
  }// POINTS
  
  bool is_same = false;
  CENTERS:  for(int c_id=0; c_id<M; c_id++){
        UINT32 x_acc, y_acc;
        IDS:  for(int pt=-1; pt<N+1; pt++){
            if(pt < 0){
              x_acc = 0, y_acc = 0;
            }else if(pt == N){
              Point temp_center;

              ac_math::ac_div(x_acc, (UINT32)M, temp_center.x);
              ac_math::ac_div(y_acc, (UINT32)M, temp_center.y);

              is_same += manhattan(center[c_id], temp_center);
            }
            else{
              x_acc = (ID[pt] == c_id) ? (UINT32)(x_acc + points[pt].x) : x_acc;
              y_acc = (ID[pt] == c_id) ? (UINT32)(y_acc + points[pt].y) : y_acc;
            }// if
        }// IDS
  }// CENTERS

  //std::cout << "Im here\n";

  return !is_same;
}

template <int N, int M>
void init(Point points[N], int ID[N], Point centers[M], int max_val){
  srand(time(NULL));

  for(int i=0; i<N; i++){
    if(i < M) centers[i] = {rand() % max_val, rand() % max_val};
    
    points[i] = {rand() % max_val, rand() % max_val};
    
    ID[i] = -(1<<31);
    //std::cout << ID[i] << std::endl;
  }
}

int main(){
  const int N = 10000;
  const int M = 50;
  const int MAX_VAL = 100;

  Point points[N], center[M];
  int ID[N];

  init<N, M>(points, ID, center, MAX_VAL);
  
  while(kmeans<N, M>(points, ID, center));
  
  std::cout << "The centers are: " << std::endl;
  for(int i=0; i<M; i++)
  std::cout << center[i].x << ", " << center[i].y << std::endl;
  
  return 0;
}
