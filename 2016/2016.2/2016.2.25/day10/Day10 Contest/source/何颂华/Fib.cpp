#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1050
#define P 1000000001
int F[N],v[N],n,m;
inline int Read()
 {
	 int x=0;char y;
	 do y=getchar(); while (y<'0'||y>'9');
	 do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
	 return x;
 }

int main()
 {
	 freopen("input.txt","r",stdin);freopen("out.txt","w",stdout);
	 n=Read();m=Read();
	 for (int i=1;i<=n;i++) v[i]=Read();
	 F[1]=1;
	 for (int i=2;i<=n;i++) F[i]=(F[i-1]+F[i-2])%P;
	 while (m--)
	  {
		  int q=Read(),w=Read(),e=Read();
		  if (q==1)
		   for (int i=w;i<=e;i++) v[i]=(v[i]+F[i-w+1])%P; else
		   {
			   int cnt=0;
			   for (int i=w;i<=e;i++) cnt=(cnt+v[i])%P;
			   cout <<cnt<<endl;
		   }
	  }
	 return 0;
 }