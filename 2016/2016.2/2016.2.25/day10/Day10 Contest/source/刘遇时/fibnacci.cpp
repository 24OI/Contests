#include<iostream>
#include<cstdio>
#define maxn 800005
#define maxm 100005
#define mod 1000000001
using namespace std;
struct seg_tree
{
	long long left,right;
	long long value;
}node[maxn];
long long father[maxn],n,m,f[maxm];
void build(long long i,long long left,long long right)
{
	node[i].left=left;
	node[i].right=right;
	node[i].value=0;
	if (left==right)
	{
		father[left]=i;
		return;
	}
	else
	{
		long long mid=(left+right)/2;
		i=i<<1;
		build(i,left,mid);
		build(i+1,mid+1,right);
	}
}
void single_modify(long long x)
{
	if (x==0) return;
	long long fath=x>>1;
	long long ls=node[fath<<1].value,rs=node[(fath<<1)+1].value;
	node[fath].value=(ls+rs)%mod;
	single_modify(fath);
}
void fib(long long x)
{
	f[1]=1;f[2]=1;
	for (long long i=3;i<=x;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
}
long long query(long long i,long long l,long long r)
{
	long long left=node[i].left,right=node[i].right;
	if ((left==l) && (right==r)) return node[i].value;
	long long mid=(left+right)/2;
	if (r<=mid) return query(i<<1,l,r);
	else if (l>=mid+1) return query((i<<1)+1,l,r);
	else return query(i<<1,l,mid)+query((i<<1)+1,mid+1,r);
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%I64d%I64d",&n,&m);
	fib(n);
	build(1,1,n);
	long long x,l,r;
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		node[father[i]].value=x;
		single_modify(father[i]);
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&l,&r);
		if (x==1)
		{
			for (long long j=l;j<=r;j++)
			{
				node[father[j]].value=node[father[j]].value+f[j-l+1];
				single_modify(father[j]);
			}
		}
		else
			printf("%I64d\n",query(1,l,r));
	}
	return 0;
}
