#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define MOD 593119681
#define maxn 1050
int n, t;
struct Matrix{
  int n, m;
  long long ma[maxn][maxn];
  Matrix() {}
  void out(){
    for (int i = 1; i <= n; ++i, printf("\n"))
      for (int j = 1; j <= m; ++j){
        if (j == m)
          printf("%I64d", ma[i][j]);
        else
          printf("%I64d ", ma[i][j]);
      }
//    printf("\n");
  }
}f0, f1, sMst, C;

void Mat(Matrix &A, Matrix &B){
  C.n = A.n, C.m = A.m;
  for (int i = 1; i <= C.n; ++i)
    for (int j = 1; j <= C.m; ++j)
      C.ma[i][j] = A.ma[i][j];
  for (int i = 1; i <= C.n; ++i){
    for (int j = 1; j <= B.m; ++j){
      int sum = 0;
      for (int k = 1; k <= B.n; ++k)
        sum = (sum+C.ma[i][k]*B.ma[k][j])%MOD;
      A.ma[i][j] = sum;
    }
  }
}

void prepare(){
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      f0.ma[i][j] = 0;
  for (int i = 1; i <= n; ++i)
    f0.ma[i][i] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j){
      int i_ = i-1, j_ = j-1;
	  int temp = i_^j_;
      //cout <<i <<" " <<j <<" " <<temp <<" ";
	  int cnt = 0;
      while (temp > 0){
        cnt += (temp%2);
        temp /= 2;
      }//cout <<cnt <<endl;
      if (cnt == 1)
        f0.ma[i][j] = f0.ma[j][i] = 1;
    }//cout <<"ok" <<endl;
  memcpy(f1.ma, f0.ma, sizeof(f0.ma));
  f0.n = f0.m = f1.n = f1.m = n;
}

void power(Matrix &A, int num){
  if (num == 1){
    return ;
  }
  power(A, num/2);
  Mat(A, A);
  if (num%2 == 1)
    Mat(A, f0);
}

int main(){
  freopen("monster.in", "r", stdin);
  freopen("monster.out", "w", stdout);
  scanf("%d %d", &n, &t);
  n = 1<<n;//cout <<"ok" <<endl;
  sMst.n = 1, sMst.m = n;
  for (int i = 1; i <= n; ++i)
    scanf("%I64d", &sMst.ma[1][i]);
  prepare();//cout <<"ok" <<endl;
  //f1.out();
  power(f1, t);
  Mat(sMst, f1);
  sMst.out();/*
  for (int i = 1; i < n; ++i)
    printf("%d ", sMst.ma[1][i]);
  printf("%d\n", sMst.ma[1][n]);*/
  return 0;
}
