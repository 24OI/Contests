#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mod 1000000001LL
typedef unsigned long long ll;
const int maxn=100005;
ll F[maxn];int n,m;ll sum[2*maxn];
ll add[2*maxn];int start[2*maxn];ll ans;int end[2*maxn];
int y1,y2,q1,q2;
void init()
{F[0]=0;F[1]=1;
for(int i=2;i<=n+5;i++)F[i]=(F[i-1]+F[i-2])%mod;
}
void build(int o,int l,int r)
{if(l==r)
{scanf("%lld",&sum[o]);return;}
int mid=(l+r)>>1;
build(2*o,l,mid);
build(2*o+1,mid+1,r);
sum[o]=sum[2*o]+sum[2*o+1];
}
inline void maintain(int o,int l,int r)
{int lc=2*o,rc=2*o+1;
if(r>l)
{sum[o]=sum[lc]+sum[rc];}
sum[o]+=add[o];
}
inline void update(int o,int l,int r)
{int lc=2*o,rc=2*o+1;
if(y1<=l && y2>=r){add[o]+=F[r-y1+3]-F[l-y1+2];
start[o]=l-y1+1;}
if(r>l)
{int mid=l+(r-l)/2;
if(y1<=mid)update(lc,l,mid);
if(y2>mid)update(rc,mid+1,r);
}
maintain(o,l,r);
add[o]=0;
}
inline void query(int o,int l,int r)
{if(l>=q1 && r<=q2){ans+=sum[o];}
else{
	int mid=l+(r-l)/2;
	if(q1<=mid)query(2*o,l,mid);
	if(q2>mid)query(2*o+1,mid+1,r);
}
}
int main()
{freopen("fibnacci.in","r",stdin);
freopen("fibnacci.out","w",stdout);
scanf("%d%d",&n,&m);
init();
build(1,1,n);
int op,x,y;
for(int i=1;i<=m;i++)
{scanf("%d%d%d",&op,&x,&y);
if(op==1){y1=x;y2=y;update(1,1,n);
}
if(op==2){ans=0;
q1=x;q2=y;query(1,1,n);
printf("%lld\n",ans);
}
}
return 0;
}
