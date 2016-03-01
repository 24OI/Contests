#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b){
  //cout <<a <<" " <<b <<endl;
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

const double EPS = 1e-8;
#define maxn 1005
int n;
struct Segment{
  int a, b, c;
  int kA, kB, bA, bB;
  Segment(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
  void get(){
    if (a == 0 || b == 0)
      return ;
    kA = -a, kB = b;
    if (kA > 0)
      kA = -kA, kB = -kB;
    int temp = gcd(abs(kA), abs(kB));
    //cout <<kA <<" " <<kB <<" " <<temp <<endl;
	kA /= temp, kB /= temp;
    bA = -c, bB = b;
    if (bA > 0)
      bA = -bA, bB = -bB;
    temp = gcd(abs(bA), abs(bB));
    //cout <<bA <<" " <<bB <<" " <<temp <<endl;
    bA /= temp, bB /= temp;
  }
}a[maxn];
struct Point{
  int xA, xB, yA, yB;
  Point(int xA = 0, int xB = 0, int yA = 0, int yB = 0): xA(xA), xB(xB), yA(yA), yB(yB) {}
  void out(){
    cout <<xA <<" " <<xB <<" " <<yA <<" " <<yB <<endl;
  }
  void get(){
  	if (xA != 0 && xB != 0){
      if (xA > 0)
        xA = -xA, xB = -xB;
      int temp = gcd(abs(xA), abs(xB));
      //cout <<xA <<" " <<xB <<" " <<temp <<endl;  
	  //cout <<"ok" <<endl;
  	  xA /= temp, xB /= temp;
    }
    if (yA != 0 && yB != 0){
      if (yA > 0)
        yA = -yA, yB = -yB;
      int temp = gcd(abs(yA), abs(yB));
      yA /= temp, yB /= temp;
      //cout <<yA <<" " <<yB <<" " <<temp <<endl;
    }
  }
}q[maxn];
int t;
int sum[maxn], cnt[maxn];

void prepare(){
  t = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j){
      Segment A = a[i], B = a[j];
	  if (A.a == 0 || B.a == 0){
        if (A.a == 0 && B.a == 0)
          continue ;//cout <<i <<" " <<j <<endl;
		if (A.a != 0)
      	  swap(A, B);
      	Point newP;
      	if (B.b == 0){
      	  newP.yA = -A.c, newP.yB = A.b;
      	  newP.xA = -B.c, newP.xB = B.a;
      	  newP.get();
      	  q[++t] = newP;
      	  continue ;
      	}
      	newP.yA = -A.c, newP.yB = A.b;
      	//cout <<newP.yA <<" " <<newP.yB <<endl;
      	newP.xA = (newP.yA*B.bB-B.bA*newP.yB)*B.kB;
      	newP.xB = (newP.yB*B.bB*B.kA);//cout <<"ok" <<endl;
      	newP.get();
      	//newP.out();
      	q[++t] = newP;
        continue ;
	  }
      if (A.b == 0 || B.b == 0){
        if (A.b == 0 && B.b == 0)
          continue ;
        if (A.b != 0)
          swap(A, B);
        Point newP;
        if (B.a == 0){
      	  newP.yA = -B.c, newP.yB = B.b;
      	  newP.xA = -A.c, newP.xB = A.a;
      	  newP.get();
      	  q[++t] = newP;
      	  continue ;
      	}
        newP.xA = -A.c, newP.xB = A.a;
        newP.yA = newP.xA*B.kA+B.bA*newP.xB*B.kB;
        newP.yB = newP.xB*B.kB*B.bB;
        newP.get();
        q[++t] = newP;
		continue ; 
      }
      Point newP;
      newP.xA = (B.bA*A.bB-A.bA*B.bB)*A.kB*B.kB;
      newP.xB = (A.kA*B.kB-B.kA*A.kB)*B.bB*A.bB;
      newP.get();
      q[++t] = newP;
      //cout <<"ok" <<endl;
    }
/*  for (int i = 1; i <= t; ++i)
    q[i].out();*/
}

int fcmp(long double x){
  if (x < EPS && x > -EPS)
    return 0;
  if (x > 0)
    return 1;
  return -1;
}

bool same(Point ai, Point bi){
  long double ai_x = (long double)(ai.xA)/(long double)(ai.xB);
  long double ai_y = (long double)(ai.yA)/(long double)(ai.yB);
  long double bi_x = (long double)(bi.xA)/(long double)(bi.xB);
  long double bi_y = (long double)(bi.yA)/(long double)(bi.yB);
  if (fcmp(ai_x-bi_x) == 0 && fcmp(ai_y-bi_y) == 0)
    return true;
  return false;
}

bool onit(Segment ai, Point bi){
  long double x = (long double)(bi.xA)/(long double)(bi.xB);
  long double y = (long double)(bi.yA)/(long double)(bi.yB);
  if (fcmp(ai.a*x+ai.b*y+(long double)(ai.c)) == 0)
    return true;
  return false;
}

void work(){
  for (int i = 1; i <= t; ++i){
    bool check = true;
	for (int j = i+1; j <= t; ++j)
	  if (same(q[i], q[j])){
	    check = false;
	    break ;
	  }
	if (check == false)
	  continue ;
	for (int j = 1; j <= n; ++j)
	  if (onit(a[j], q[i]) == true)
	    sum[i] ++;
  }
  for (int i = 1; i <= t; ++i)
    cnt[sum[i]] ++;
  for (int i = n; i >= 1; --i)
    if (cnt[i] != 0){
      printf("%d %d\n", i, cnt[i]);
      break ;
    }
}

int main(){
  freopen("star.in", "r", stdin);
  freopen("star.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i){
    scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
    a[i].get();
    //if (i == 3)
    //  cout <<a[i].kA / a[i].kB <<" " <<a[i].bA / a[i].bB <<endl;
  }//cout <<"ok" <<endl;
  prepare();
  work();
  return 0;
}
