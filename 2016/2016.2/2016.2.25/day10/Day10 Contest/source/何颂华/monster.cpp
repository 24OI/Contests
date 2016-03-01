#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 20
#define M 300050
#define P 593119681
#define ll long long
struct Matrix
 {ll a[N][N];} A,B,C;
int ans,n,m,cnt,s[M],v[M];ll Ans[M];
inline int Read()
 {
	 int x=0;char y;
	 do y=getchar(); while (y<'0'||y>'9');
	 do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
	 return x;
 }
Matrix operator* (const Matrix &x,const Matrix &y)
 {
	 memset(C.a,0,sizeof(C.a));
	 for (int i=0;i<=n;i++)
	  for (int j=0;j<=n;j++)
	   for (int k=0;k<=n;k++)
		 C.a[i][k]=(C.a[i][k]+x.a[i][j]*y.a[j][k])%P;
	 return C;
 }
void Quick_Power()
 {
	 for (int i=0;i<=n;i++) B.a[i][i]=true;
	 while (m)
	  {if (m&1) B=B*A;A=A*A;m >>= 1;}
	 return;
 }
void Pretreat()
 {
	 for (int i=0;i<=n;i++) A.a[i][i]=1;
	 for (int i=0;i<n;i++) A.a[i][i+1]=i+1,A.a[i+1][i]=n-i;
	 for (int i=0;i<cnt;i++)
	  {
		  int Cnt=0,k=i;
		  while (k) Cnt+=k&1,k >>= 1;
		  s[i]=Cnt;
	  }
	 Quick_Power();
	 return;
 }
int main()
 {
	 freopen("monster.in","r",stdin);freopen("monster.out","w",stdout);
	 n=Read();m=Read();cnt = 1 << n;
	 for (int i=0;i<cnt;i++) v[i]=Read();
	 Pretreat();
	 for (int i=0;i<cnt;i++)
	  for (int j=0;j<cnt;j++)
		Ans[j]=(Ans[j]+v[i]*B.a[0][s[i^j]])%P;
	 for (int i=0;i<cnt;i++) printf("%d ",Ans[i]);
	 puts("");
	 return 0;
 }