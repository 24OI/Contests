#include<cstdio>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

#define re(i,a,b) for(i=(a);i<=(b);i++)
#define SF scanf
#define PF printf
#define mmst(a,v) memset(a,v,sizeof(a))

const int maxn=100100;
const int MOD=1000000001;

int n,m;
int a[maxn],suma[maxn];
int F[maxn];
int ans[maxn];

struct Tmatrix
  {
  	int n,m,v[3][3];
  	void clear(){n=m=0;mmst(v,0);}
  	friend Tmatrix operator *(Tmatrix a,Tmatrix b)
  	  {
  	  	Tmatrix c;
  	  	c.clear();
  	  	int i,j,k;
  	  	c.n=a.n;c.m=b.m;
  	  	re(i,0,c.n-1)re(j,0,c.m-1)re(k,0,a.m-1)(c.v[i][j]+=1LL*a.v[i][k]*b.v[k][j]%MOD)%=MOD;
  	  	return c;
  	  }
  };

Tmatrix mat[maxn];

struct TQ{int op,l,r;}Q[maxn];

struct Tdata{int pos,idx,val;}data1[3*maxn],data2[2*maxn];
int cnt1,cnt2;

bool cmp(Tdata a,Tdata b){return a.pos<b.pos;}

void CDQ(int l,int r)
  {
  	if(l==r)return;
  	int i,mid=(l+r)>>1;
  	cnt1=cnt2=0;
  	re(i,l,mid)if(Q[i].op==1)
  	  {
  	  	data1[++cnt1]=(Tdata){Q[i].l,0,F[1]};
  	  	data1[++cnt1]=(Tdata){Q[i].r+1,0,-F[Q[i].r-Q[i].l+2]};
  	  	data1[++cnt1]=(Tdata){Q[i].r+2,0,-F[Q[i].r-Q[i].l+1]};
  	  }
  	re(i,mid+1,r)if(Q[i].op==2)
  	  {
  	  	data2[++cnt2]=(Tdata){Q[i].l-1,i,-1};
  	  	data2[++cnt2]=(Tdata){Q[i].r,i,1};
  	  }
  	sort(data1+1,data1+cnt1+1,cmp);
  	sort(data2+1,data2+cnt2+1,cmp);
  	int p=0,last=0;
  	Tmatrix T;T.clear();T.n=3;T.m=1;
  	re(i,1,cnt2)
  	  {
  	  	while(last+1<=cnt1 && data1[last+1].pos<=data2[i].pos)
  	  	  {
  	  	  	last++;
  	  	  	T=mat[data1[last].pos-p]*T;p=data1[last].pos;
  	  	  	(T.v[0][0]+=data1[last].val)%MOD;
  	  	  	(T.v[2][0]+=data1[last].val)%MOD;
  	  	  }
  	  	T=mat[data2[i].pos-p]*T;p=data2[i].pos;
  	  	(ans[data2[i].idx]+=1LL*data2[i].val*T.v[2][0])%=MOD;
  	  }
		CDQ(l,mid);
  	CDQ(mid+1,r);
  }

int main()
  {
  	freopen("fibnacci.in","r",stdin);
  	freopen("fibnacci.out","w",stdout);
  	int i,j,k,l;
  	SF("%d%d\n",&n,&m);
  	re(i,1,n)SF("%d",&a[i]),suma[i]=(suma[i-1]+a[i])%MOD;
		F[1]=1;re(i,2,n+10)F[i]=(F[i-1]+F[i-2])%MOD;
		mat[0].n=mat[0].m=3;mat[0].v[0][0]=mat[0].v[1][1]=1;mat[0].v[2][2]=1;
		mat[1].n=mat[1].m=3;mat[1].v[0][0]=mat[1].v[0][1]=mat[1].v[1][0]=mat[1].v[2][0]=mat[1].v[2][1]=mat[1].v[2][2]=1;
		re(i,2,n+10)mat[i]=mat[i-1]*mat[1];
		re(i,1,m)scanf("%d%d%d\n",&Q[i].op,&Q[i].l,&Q[i].r),(ans[i]+=suma[Q[i].r]-suma[Q[i].l-1])%MOD;
		CDQ(1,m);
		re(i,1,m)if(Q[i].op==2)PF("%d\n",(ans[i]%MOD+MOD)%MOD);
		return 0;
	}
