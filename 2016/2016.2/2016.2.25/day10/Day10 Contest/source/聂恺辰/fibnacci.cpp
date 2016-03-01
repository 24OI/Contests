#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
long long f[N],a[N],pre[N];
long long mod=1e9+1;
long long l[N<<2],r[N<<2],w[N<<2],t1[N<<2],t2[N<<2];
struct ppp {long long a[2][2];
/*void prlong long()
{
	long long i,j;
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		cout<<a[i][j]<<' ';
		cout<<endl;
	}
}*/};
ppp cf[N];
ppp ans,st;
ppp operator *(ppp x,ppp y)
{
	memset(ans.a,0,sizeof(ans.a));
	long long i,j,k;
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	{
		for(k=0;k<2;k++)
		ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
	}
	return ans;
}
ppp yb;
ppp alone_wolf;
void getget(long long fy,long long li,long long x,long long &a1,long long &a2)
{
	alone_wolf=cf[x];
	a1=(fy*alone_wolf.a[0][0]+li*alone_wolf.a[1][0])%mod;
	a2=(fy*alone_wolf.a[0][1]+li*alone_wolf.a[1][1])%mod;
}
void pup(long long x) {w[x]=(w[x<<1]+w[x<<1|1])%mod;}
void pud(long long x)
{
	if(!t1[x]&&!t2[x]) return;
	long long mid=(l[x]+r[x])>>1;
	long long le=mid-l[x]+1;
	long long xx,yy;
	getget(t1[x],t2[x],le,xx,yy);
	t1[x<<1]+=t1[x];t2[x<<1]+=t2[x];w[x<<1]+=(pre[le+1]-1)*t2[x]+pre[le]*t1[x];
	t1[x<<1]%=mod;t2[x<<1]%=mod;w[x<<1]%=mod;
	t1[x<<1|1]+=xx;t2[x<<1|1]+=yy;w[x<<1|1]+=(pre[r[x]-mid+1]-1)*yy+pre[r[x]-mid]*xx;
	t1[x<<1|1]%=mod;t2[x<<1|1]%=mod;w[x<<1|1]%=mod;
	t1[x]=0;t2[x]=0;
}
void build(long long now,long long ll,long long rr)
{
	l[now]=ll;r[now]=rr;
	if(ll==rr)
	{
		w[now]=a[ll];
		return;
	}
	long long mid=(ll+rr)>>1;
	build(now<<1,ll,mid);
	build(now<<1|1,mid+1,rr);
	pup(now);
}
void change(long long now,long long ll,long long rr,long long v)
{
	long long mid=(l[now]+r[now])>>1;
	if(l[now]==ll&&r[now]==rr)
	{
		long long xx,yy;
		if(ll-v==1) xx=1;
		else xx=f[ll-v-2];
		yy=f[ll-v-1];
		t1[now]+=xx;t2[now]+=yy;
		w[now]+=(pre[r[now]-l[now]+2]-1)*yy+pre[r[now]-l[now]+1]*xx;
		t1[now]%=mod;t2[now]%=mod;w[now]%=mod;
	//	cout<<xx<<' '<<yy<<' '<<ll<<' '<<rr<<w[now]<<endl;
		return;
	}
	if(ll>mid) change(now<<1|1,ll,rr,v);
	else if(rr<=mid) change(now<<1,ll,rr,v);
	else
	{
		change(now<<1,ll,mid,v);
		change(now<<1|1,mid+1,rr,v);
	}
	pup(now);
}
long long check(long long now,long long ll,long long rr)
{
	if(ll==l[now]&&rr==r[now]) return w[now];
	long long mid=(l[now]+r[now])>>1;
	pud(now);
	if(ll>mid) return check(now<<1|1,ll,rr);
	else if(rr<=mid) return check(now<<1,ll,rr);
	else return (check(now<<1,ll,mid)+check(now<<1|1,mid+1,rr))%mod;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long i,j;
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	f[1]=1;pre[1]=1;
	st.a[0][0]=1;st.a[1][1]=1;
	yb.a[0][1]=1;yb.a[1][0]=1;yb.a[1][1]=1;
	cf[1]=yb;
	for(i=2;i<=n;i++) cf[i]=cf[i-1]*yb;
	for(i=2;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
		pre[i]=(pre[i-1]+f[i])%mod;
	}
	long long o,x,y;
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&o,&x,&y);
		if(o==1) change(1,x,y,x-1);
		else printf("%lld\n",check(1,x,y));
	}
}
