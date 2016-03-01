#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050
#define P 1000000001
#define ll long long
#define fr first
#define sc second
struct Matrix
 {ll a[2][2];} Power[N],C;
pair <int,int> a[N*4];
int n,m,s[N*4];
inline int Read()
 {
	 int x=0;char y;
	 do y=getchar(); while (y<'0'||y>'9');
	 do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
	 return x;
 }
void Set_up(int x,int y,int z)
 {
	 int i=x + y >> 1,j=z << 1;
	 if (x==y) {s[z]=Read();return;}
	 Set_up(x,i,j);Set_up(i+1,y,j+1);
	 s[z]=(s[j]+s[j+1])%P;
	 return;
 }
Matrix operator* (const Matrix &x,const Matrix &y)
 {
	 memset(C.a,0,sizeof(C.a));
	 for (int i=0;i<2;i++)
	  for (int j=0;j<2;j++)
	   for (int k=0;k<2;k++)
		 C.a[i][k]=(C.a[i][k]+x.a[i][j]*y.a[j][k])%P;
     return C;
 }
inline pair <int,int> Get(pair <int,int> x,int y)
 {
	 if (y<=2) return x;y-=2;
	 return make_pair((x.sc*Power[y].a[0][1]+x.fr*Power[y].a[1][1])%P,
	   (x.sc*Power[y].a[0][0]+x.fr*Power[y].a[1][0])%P);
 }
inline void Merge(pair <int,int> &x,pair <int,int> y)
 {x.fr=(x.fr+y.fr)%P;x.sc=(x.sc+y.sc)%P;}
void adj(int x,int y,int z)
 {
	 if (!a[z].fr&&!a[z].sc) return;
	 int j=z << 1,i=x + y >> 1;
	 s[z]=((s[z]+Get(a[z],y-x+3).sc)%P+P-a[z].sc)%P;
	 if (x!=y)
	  {Merge(a[j],a[z]);Merge(a[j+1],Get(a[z],i+3-x));}
	 a[z].fr=a[z].sc=0;
 }
int Query(int x,int y,int z,int o,int p)
 {
	 int i=x + y >> 1,j=z << 1;adj(x,y,z);
	 if (x==o&&y==p) return s[z];
	 if (p<=i) return Query(x,i,j,o,p); else
      if (o>i) return Query(i+1,y,j+1,o,p); else
		return (Query(x,i,j,o,i)+Query(i+1,y,j+1,i+1,p))%P;
 }
void Modify(int x,int y,int z,int o,int p,pair <int,int> u)
 {
	 int i=x + y >> 1,j=z << 1;adj(x,y,z);
	 if (x==o&&y==p) {a[z]=u;adj(x,y,z);return;}
	 if (p<=i) Modify(x,i,j,o,p,u),adj(i+1,y,j+1); else
	  if (o>i) Modify(i+1,y,j+1,o,p,u),adj(x,i,j); else
		Modify(x,i,j,o,i,u),Modify(i+1,y,j+1,i+1,p,Get(u,i+3-o));
	 s[z]=(s[j]+s[j+1])%P;
	 return;
 }
inline void Put(Matrix x)
 {
	 for (int i=0;i<2;i++)
	  {
		  for (int j=0;j<2;j++) cout <<x.a[i][j];
		  puts("");
	  }
	 return;
 }
int main()
 {
	 freopen("fibnacci.in","r",stdin);freopen("fibnacci.out","w",stdout);
	 n=Read();m=Read();Set_up(1,n,1);
	 Power[1].a[0][0]=Power[1].a[0][1]=Power[1].a[1][0]=true;
	 Power[0]=Power[1];Power[0].a[1][1]=true;
	 Power[0].a[0][1]=Power[0].a[1][0]=false;
	 for (int i=2;i<N;i++) Power[i]=Power[i-1]*Power[1];
	 while (m--)
	  {
		  int q=Read(),w=Read(),e=Read();
		  if (q==2) printf("%d\n",Query(1,n,1,w,e)); else
			Modify(1,n,1,w,e,make_pair(1,1));
	  }
	 return 0;
 }