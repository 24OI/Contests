#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500010
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int a,b,c,d,e;
int val[N];
int sta[15][1100];
int n;
struct node
{
	int l,r;
}seg[N];
int staa[15];
int topp;
int use[15];
int sum[N<<2],col[N<<2];
void pushup(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int l,int r)
{
	if(col[rt])
	{
		int mid=(l+r)>>1;
		sum[rt<<1]=mid-l+1-sum[rt<<1];
		sum[rt<<1|1]=r-mid-sum[rt<<1|1];
		col[rt<<1]^=1;
		col[rt<<1|1]^=1;
		col[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=val[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson),build(rson);
	pushup(rt);
}
void update(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		col[rt]^=1;
		sum[rt]=r-l+1-sum[rt];
		return;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)update(L,R,lson);
	if(R>mid)update(L,R,rson);
	pushup(rt);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=1;i<=a;i++)val[i]=0;
	for(int i=a+1;i<=a+b;i++)val[i]=1;
	for(int i=a+b+1;i<=a+b+c;i++)val[i]=0;
	for(int i=a+b+c+1;i<=a+b+c+d;i++)val[i]=1;
	for(int i=a+b+c+d+1;i<=a+b+c+d+e;i++)val[i]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&seg[i].l,&seg[i].r);
	if(n>10){puts("-1");return 0;} 
	for(int i=1;i<(1<<n);i++)
	{
		int cnt=0;
		int tmp=i;
		while(tmp)
		{
			if(tmp&1)cnt++;
			tmp>>=1;
		}
		sta[cnt][++sta[cnt][0]]=i;
	}
	int ans=0x3f3f3f3f;
	build(1,a+b+c+d+e,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sta[i][0];j++)
		{
			int vvv=sta[i][j];
			topp=0;
			int cost=0;
			for(int k=1;k<=n;k++)
			{
				if(vvv&(1<<(k-1)))
					staa[++topp]=k,cost+=seg[k].r-seg[k].l+1;
			}
			for(int k=1;k<=topp;k++)
			{
				update(seg[staa[k]].l,seg[staa[k]].r,1,a+b+c+d+e,1);
			}
			if(sum[1]==0)ans=min(ans,cost);
			for(int k=1;k<=topp;k++)
			{
				update(seg[staa[k]].l,seg[staa[k]].r,1,a+b+c+d+e,1);
			}
		}
	}
	if(ans==0x3f3f3f3f)puts("-1");
	else printf("%d\n",ans);
}