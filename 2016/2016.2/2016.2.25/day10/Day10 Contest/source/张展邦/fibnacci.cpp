#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define maxn 100005
struct Quest{
  int l, r;
  int op;
  Quest(int op = 0, int l = 0, int r = 0): op(op), l(l), r(r) {}
}p[maxn];
int n, m;
int a[maxn];
int f[maxn], sumF[maxn];

void prepare(){
  f[0] = 0, f[1] = 1;
  sumF[0] = 0, sumF[1] = 1;
  for (int i = 2; i <= maxn; ++i){
    f[i] = f[i-1]+f[i-2];
    sumF[i] = sumF[i-1]+f[i];
  }
}

int main(){
  freopen("fibnacci.in", "r", stdin);
  freopen("fibnacci.out", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  for (int i = 1; i <= m; ++i){
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    p[i] = Quest(op, l, r);
  }
  prepare();
  for (int i = 1; i <= m; ++i){
    if (p[i].op == 1){
      for (int j = p[i].l, k = 1; j <= p[i].r; ++j, ++k)
        a[j] += f[k];
    }
    else{
      int ans = 0;
      for (int j = p[i].l; j <= p[i].r; ++j)
        ans += a[j];
      printf("%d\n", ans);
    }/*
    for (int j = 1; j <= n; ++j)
      printf("%d ", a[j]);
    printf("\n");*/
  }
  return 0;
}
