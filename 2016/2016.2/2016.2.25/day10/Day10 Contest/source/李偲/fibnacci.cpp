#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define M 100005
#define MOD 1000000001
using namespace std;
int f[M];
int a[M];
int n,m;
int sum[M];
struct node
{
	int flag;
	int sum;
}tree[M*2];
void getfebo()
{
	f[1]=1;
	sum[1]=f[1];
	for(int i=2;i<M;i++)
	{
		f[i]=(f[i-1]+f[i-2])%MOD;
		sum[i]=f[i]+sum[i-1];
	}
	//printf("%d\n",f[M-1]);
}

/*void build(int st,int l,int r)
{
	if(l==r)
	{
		tree[st].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(st<<1,l,mid);
	build(st<<1|1,mid+1,r);
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum;
}

void query(int st,int l,int r,int ql,int qr,int nowp)
{
	int mid=(l+r)>>1;
	if(tree[st].flag)
	{
		pushdown(st,l,r);
	}
	if(l==ql&&r==qr)
	{
		print
	}
}

void add(int st,int l,int r,int ql,int qr,int nowp)
{
	int mid=(l+r)>>1;
	if(tree[st].flag)
	{
		pushdown(st,l,r);
		return;
	}
	if(l==ql&&r==qr)
	{
		tree[st].sum=(tree[st].sum+sum[qr-ql+1]-sum[qr-ql+1])
	}
	if(r<=ql)
	{
		add(st<<1,l,r,ql,qr,nowp);
	}
	else if(l>qr)
	{
		add(st<<1|1,l,r,ql,qr,nowp);
	}
	else 
	{
		add(st<<1,l,mid,ql,qr,nowp);
		add(st<<1|1,mid+1,r,ql,qr,nowp);
	}
	
}
*/
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			for(int i=l;i<=r;i++)
			{
				a[i]=((a[i]%MOD)+f[i-l+1])%MOD;
			}	
		}
		else
		{
			int sum=0;
			for(int i=l;i<=r;i++)
			{
				sum=(sum+a[i])%MOD;
			}
			printf("%d\n",sum);
		}
	}
}

/*void solve2()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			add(1,1,n,l,r,1);	
		}
		else
		{
			int sum=0;
			for(int i=l;i<=r;i++)
			{
				sum=(sum+a[i])%MOD;
			}
			printf("%d\n",sum);
		}
	} 
}*/
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	getfebo();
	scanf("%d%d",&n,&m);
	if(n<=1000&&m<=1000)
	{
		solve1();
		return 0;
	}
	return 0;
}
