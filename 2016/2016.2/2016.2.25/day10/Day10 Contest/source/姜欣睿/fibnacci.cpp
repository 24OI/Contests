#include<cstdio>
#include<cstdlib>
#define N 100010
#define M 1000000001
#define g(l,r) (l+r|l!=r)
using namespace std;
int n,f[N];
void init(int n)
{
	f[0]=0,f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%M;
	for(int i=1;i<=n;i++) f[i]=(f[i]+f[i-1])%M;
}
struct stree
{
	long long sum[2*N],ad[2*N];
	void update(int l,int r)
	{
		int mid=l+r>>1;
		sum[g(l,r)]=(sum[g(l,mid)]+sum[g(mid+1,r)])%M;
	}
	void build(int l,int r)
	{
		ad[g(l,r)]=0;
		if(l==r)
		{
			scanf("%lld",&sum[g(l,r)]);
			return;
		}
		int mid=l+r>>1;
		build(l,mid),build(mid+1,r);
		update(l,r);
	}
	void lazy(int l,int r,int t)
	{
		sum[g(l,r)]=(sum[g(l,r)]+f[r-t+1]-f[l-t]+M)%M;
		ad[g(l,r)]=t;
	}
	void down(int l,int r)
	{
		if(l==r) return;
		int mid=l+r>>1;
		if(ad[g(l,mid)]) down(l,mid);
		if(ad[g(mid+1,r)]) down(mid+1,r);
		lazy(l,mid,ad[g(l,r)]);
		lazy(mid+1,r,ad[g(l,r)]);
		ad[g(l,r)]=0;
	}
	int cur_x,cur_y;
	void add(int l,int r)
	{
		if(ad[g(l,r)]) down(l,r);
		if(cur_x<=l&&r<=cur_y)
		{
			lazy(l,r,cur_x);
			return;
		}
		int mid=l+r>>1;
		if(cur_x<=mid) add(l,mid);
		if(cur_y>mid) add(mid+1,r);
		update(l,r);
	}
	long long query(int l,int r)
	{
		if(cur_x<=l&&r<=cur_y) return sum[g(l,r)];
		if(ad[g(l,r)]) down(l,r);
		int mid=l+r>>1,ans=0;
		if(cur_x<=mid) ans=(ans+query(l,mid))%M;
		if(cur_y>mid) ans=(ans+query(mid+1,r))%M;
		return ans;
	}
}t;
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	init(n);
	t.build(1,n);
	for(int i=1,p,l,r;i<=m;i++)
	{
		scanf("%d%d%d",&p,&l,&r);
		t.cur_x=l,t.cur_y=r;
		if(p==1) t.add(1,n);
		else printf("%lld\n",t.query(1,n)%M);
	}
	return 0;
}
