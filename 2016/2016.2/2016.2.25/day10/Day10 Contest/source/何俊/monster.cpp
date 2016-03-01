#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define N 3050
#define Mod 593119681

int n,t;
int A[N],now[N];
struct Edge{
	int to,next;
}edge[N*N];
int head[N],tot;

struct Matrix{
	int m[70][70];
};
Matrix Unit,qwer,Ans;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void Addedge(int u,int v)
{
	tot++;edge[tot].next=head[u];edge[tot].to=v;head[u]=tot;
}

Matrix Mulmatrix(Matrix a,Matrix b)
{
	Matrix c;int qqq=(1<<n);
	for(int i=0;i<qqq;i++)
	{
		for(int j=0;j<qqq;j++)
		{
			c.m[i][j]=0;
			for(int k=0;k<qqq;k++)
			{
				c.m[i][j]=(c.m[i][j]+(a.m[i][k]*b.m[k][j]%Mod))%Mod;
			}
		}
	}
	return c;
}

Matrix Quickmatrix(Matrix a,int exp)
{
	Matrix base=a,r=Unit;
	while(exp)
	{
		if(exp&1)
			r=Mulmatrix(r,base);
		base=Mulmatrix(base,base);
		exp>>=1;
	}
	return r;
}

int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	n=read();t=read();
	if(t<=1000)
	{
		int qqq=(1<<n);
		for(int i=0;i<qqq;i++)
		{
			int tmp=i,pos=0;
			while(pos<=n)
			{
				if(tmp&1)
				{
					Addedge(i,i-(1<<pos));
				}
				else if(i+(1<<pos)<qqq) 
					Addedge(i,i+(1<<pos));
				tmp>>=1;
				pos++;
			}
		}
		for(int i=0;i<qqq;i++)
		{
			A[i]=now[i]=read();
		}
		for(int i=1;i<=t;i++)
		{
			for(int j=0;j<qqq;j++)
			{
				for(int k=head[j];k;k=edge[k].next)
				{
					int v=edge[k].to;
					now[j]=(now[j]+A[v])%Mod;
				}
			}
			for(int j=0;j<qqq;j++)
			{
				A[j]=now[j];
			}
		}
		for(int i=0;i<qqq-1;i++)
			printf("%d ",now[i]);
		printf("%d\n",now[qqq-1]);
		return 0;
	}
	int qqq=(1<<n);
	for(int i=0;i<qqq;i++)
	{
		int tmp=i,pos=0;
		while(pos<=n)
		{
			if(tmp&1)
			{
				qwer.m[i][i-(1<<pos)]=1;
			}
			else if(i+(1<<pos)<qqq)
				qwer.m[i][i+(1<<pos)]=1;
			tmp>>=1;
			pos++;
		}
	}
	for(int i=0;i<qqq;i++)
	{
		Unit.m[i][i]=1;
		qwer.m[i][i]=1;
		Ans.m[i][0]=read();
	}
	Matrix qq=Quickmatrix(qwer,t);
	Ans=Mulmatrix(qq,Ans);
	for(int i=0;i<qqq-1;i++)
		printf("%d ",Ans.m[i][0]);
	printf("%d\n",Ans.m[qqq-1][0]);
	return 0;
}
