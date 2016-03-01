#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using  namespace std;
#define P 1000000001
#define MAXN 100010
#define LL long long
int n,m,op,l,r;
LL f[MAXN],a[MAXN],sum[MAXN];
struct node{
	int l,r,adl,adr;
	LL sum;
}tree[MAXN*4];
void pushup(int p)
{
	tree[p].sum=(tree[p<<1].sum+tree[p<<1|1].sum) % P;
}
void build(int p,int l,int r)
{
	tree[p].l=l;tree[p].r=r;
	tree[p].sum=0;
	tree[p].adl=0;
	tree[p].adr=0;
	if (l==r)
	{
		tree[p].sum=a[l];
		return ;
	}
	int mid=(l+r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
    if (tree[p].adl==tree[p].adr && tree[p].adl)
    {
    	tree[p].sum=(tree[p].sum+f[tree[p].adl]) % P;
    	tree[p].adl=tree[p].adr=0;
    	return ; 
    }
	if (tree[p].adl)
	{
		int mid=(tree[p].l+tree[p].r) >> 1;
		tree[p<<1].adl=tree[p].adl;
		tree[p<<1|1].adr=tree[p].adr;
		tree[p<<1].adr=tree[p].adl+mid-tree[p].l;
		tree[p<<1|1].adl=tree[p<<1].adr+1;
		tree[p<<1].sum=(tree[p<<1].sum+sum[tree[p<<1].adr]-sum[tree[p<<1].adl-1]) % P;
		tree[p<<1|1].sum=(tree[p<<1|1].sum+sum[tree[p<<1|1].adr]-sum[tree[p<<1|1].adl-1]) % P;
		tree[p].adr=tree[p].adl=0;
    } 
}
void add(int p,int l,int r,int ll,int rr)
{
	pushdown(p);
	if (tree[p].l==l && tree[p].r==r)
	{
		tree[p].adl=ll;
		tree[p].adr=rr;
		tree[p].sum=(tree[p].sum+sum[rr]-sum[ll-1]) % P;
		return ;
	}
	int mid=(tree[p].l+tree[p].r) >> 1;
	if (r<=mid) add(p<<1,l,r,ll,rr);
	if (l>mid) add(p<<1|1,l,r,ll,rr);
	if (l<=mid && r>mid)
	{
		add(p<<1,l,mid,ll,ll+mid-l);
		add(p<<1|1,mid+1,r,ll+mid,rr);
	}
	pushup(p);
}
LL query(int p,int l,int r)
{
	if (tree[p].l==l && tree[p].r==r)
	{
		return tree[p].sum;
	}
	pushdown(p);
	int mid=(tree[p].l+tree[p].r) >> 1;
	if (r<=mid) return query(p<<1,l,r);
	if (l>mid) return query(p<<1|1,l,r);
	if (l<=mid && r>mid)
	{
		long long s1=query(p<<1,l,mid);
		long long s2=query(p<<1|1,mid+1,r);
		return (s1+s2) % P;
	}
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++)
	    scanf("%d", &a[i]);
	f[0]=0;f[1]=1;
	sum[1]=1;
	for (int i=2;i<=n;i++)
	{
	    f[i]=(f[i-1]+f[i-2]) % P;
	    sum[i]=(sum[i-1]+f[i]) % P;
	}
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d", &op, &l, &r);
		if (op==1)
		{
		    add(1,l,r,1,r-l+1);	
		}
		else
		 {
		 	printf("%lld\n",query(1,l,r));
		 }
	}
}
