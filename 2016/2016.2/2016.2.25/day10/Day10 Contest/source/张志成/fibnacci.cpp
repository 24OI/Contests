#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define l(x) x<<1
#define r(x) x<<1|1
using namespace std;
const int N=1E5+32,MOD=1E9+1;
int n,m,op,l,r,sn;
int f[N],sf[N],A[N];
struct Seg{
	struct tag{
		int s,l;
	}t[N][30];
	int sum[N],cnt[N];
	void PU(int x)
	{
		sum[x]=(sum[x<<1]+sum[x<<1|1])%MOD;
	}
	void PD(int x)
	{
		int L=l(x),R=r(x);
		if(L>2*n||R>2*n)return;
		if(cnt[x]>27)
		{
			for(int i=1;i<=cnt[x];i++)
			{
				t[L][cnt[L]++]=(tag){t[x][i].s,(t[x][i].l)<<1};
				t[R][cnt[R]++]=(tag){t[x][i].l<<1|1,t[x][i].l};
				(sum[x]+=sf[t[x][i].l]-sf[t[x][i].s-1])%=MOD;
			}
			cnt[x]=0;
		}
		PD(L);PD(R);
	}
	void BD(int l,int r,int x)
	{
		if(l==r){
			sum[x]=A[l];
			return;
		}
		int mid=(l+r)>>1;
		BD(l,mid,x<<1);BD(mid+1,r,x<<1|1);
		PU(x);
	}
	void INS(int c,int p,int l,int r,int x)
	{
		if(l==r){
			(sum[x]+=c)%=MOD;
			return;
		}
		PD(x);
		int mid=(l+r)>>1;
		if(p<=mid)INS(c,p,l,mid,x<<1);
		else INS(c,p,mid+1,r,x<<1);
		PU(x);
	}
	void ins(int s,int len,int L,int R,int l,int r,int x)
	{
		if(L<=l&&r<=R){
			t[x][cnt[x]++]=(tag){s,len};
			(sum[x]+=sf[len]-sf[s-1])%=MOD;
			return;
		}
		PD(x);
		int mid=(l+r)>>1;
		if(L<=mid)ins(s,len<<1,L,R,l,mid,x<<1);
		if(mid<R)ins(len<<1|1,len,L,R,mid+1,r,x<<1|1);
		PU(x);
	}
	int Que(int L,int R,int l, int r,int x)
	{
		PD(x);
		if(L<=l&&r<=R)return sum[x];
		int mid=(l+r)>>1,res=0;
		if(L<=mid)res=(res+Que(L,R,l,mid,x<<1)%MOD)%MOD;
		if(mid<R)res=(Que(L,R,mid+1,r,x<<1|1)%MOD)%MOD;
		return (res+MOD)%MOD;
	}
	void ADD(int L,int R)
	{
		if(R-L<sn)for(int i=L;i<=R;i++)INS(f[i-L+1],i,1,n,1);
		else{
			ins(1,R-L+1,L,R,1,n,1);
		}
	}
}T;
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	sn=(int)(sqrt(n)+5)/17;
	f[0]=0;f[1]=1;sf[1]=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%MOD,sf[i]=(sf[i-1]+f[i])%MOD;
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	if(n>1005){
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1){
				T.ADD(l,r);
			}
			else printf("%d\n",T.Que(l,r,1,n,1));
		}
	}
	else {
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1)
			{
				for(int i=l;i<=r;i++)(A[i]+=f[i-l+1])%=MOD;
			}
			if(op==2)
			{	
				int ans=0;
				for(int i=l;i<=r;i++)(ans+=A[i])%=MOD;
				printf("%d\n",(ans+MOD)%MOD);
			}
		}
	}
}
