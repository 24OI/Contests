#include<cstdio>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define re(i,a,b) for(i=(a);i<=(b);i++)
#define SF scanf
#define PF printf
#define mmst(a,v) memset(a,v,sizeof(a))
#define two(v) (1<<(v))

const int maxn=18;
const LL MOD=593119681;

int n,t;
int a[two(maxn)+100];

struct Tmatrix
  {
  	int n,m;
  	LL v[20][20];
  	void clear(){n=m=0;mmst(v,0);}
  	friend Tmatrix operator *(Tmatrix a,Tmatrix b)
  	  {
  	  	Tmatrix c;int i,j,k;
  	  	c.clear();
  	  	c.n=a.n;c.m=b.m;
  	  	re(i,0,c.n)re(j,0,c.m)re(k,0,a.m)(c.v[i][j]+=a.v[i][k]*b.v[k][j])%=MOD;
  	  	return c;
  	  }
  };

Tmatrix getpow(Tmatrix a,int k)
  {
  	Tmatrix x;int i;
  	x.clear();x.n=x.m=a.n;re(i,0,x.n)x.v[i][i]=1;
  	while(k){if(k&1)x=x*a;a=a*a;k>>=1;}
  	return x;
  }
	  	
Tmatrix A,B,C;
LL ans[two(maxn)+100];
int ge[two(maxn)+100];

int main()
  {
  	freopen("monster.in","r",stdin);
  	freopen("monster.out","w",stdout);
  	int i,j;
  	SF("%d%d\n",&n,&t);
  	re(i,0,two(n)-1)SF("%d",&a[i]);
  	re(i,0,two(n)-1)for(int H=i;H;H>>=1)ge[i]+=(H&1);
  	B.clear();
  	B.n=n;B.m=0;B.v[0][0]=1;
  	A.clear();
  	A.n=A.m=n;
  	re(i,0,n)
  	  {
  	  	(A.v[i][i]+=1)%=MOD;
  	  	if(i-1>=0)(A.v[i][i-1]+=i)%=MOD;
  	  	if(i+1<=n)(A.v[i][i+1]+=(n-i))%=MOD;
			}
		A=getpow(A,t);
		C=A*B;
		re(i,0,two(n)-1)
		  re(j,0,two(n)-1)
		  	(ans[i^j]+=1LL*a[i]*C.v[ge[j]][0]%MOD)%=MOD;
		//集合幂级数 vfk orz 
		re(i,0,two(n)-1)PF("%I64d ",(ans[i]%MOD+MOD)%MOD);PF("\n");
		return 0;
	}
