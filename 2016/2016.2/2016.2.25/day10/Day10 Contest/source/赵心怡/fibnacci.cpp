#include<iostream>
#include<cstdio>
#define MOD 1000000001
#define maxn 100005
using namespace std;
int n,m;
long long fib[maxn];
struct node
{
	long long sum;
	long long lazya,lazyb;
}a[maxn*4];
long long b[maxn];
long long he[maxn];
void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x].sum=b[l]%MOD;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	a[x].sum=(a[x*2].sum+a[x*2+1].sum)%MOD;
}
long long getnum(long long a,long long b,int  len)
{
	if(len==1)return a;
	if(len==2)return b;
	long long ret=((long long)a*fib[len-2]%MOD+(long long)b*fib[len-1]%MOD)%MOD;
	return ret;
}
long long getsum(long long a,long long b,int len)
{
	if(len==1)return a;
	if(len==2)return a+b;
	long long ret=(getnum(a,b,len+2)-b+MOD)%MOD;
//	cout<<ret<<endl;
	return ret;
}
void down(int x,int l,int r)
{
	int mid=(l+r)/2;
	if(a[x].lazya==0 && a[x].lazyb==0)return;
	//cout<<"find";
	a[x*2].sum=(a[x*2].sum+getsum(a[x].lazya,a[x].lazyb,mid-l+1))%MOD;
	a[x*2+1].sum=(a[x*2+1].sum+getsum(getnum(a[x].lazya,a[x].lazyb,mid-l+2),getnum(a[x].lazya,a[x].lazyb,mid-l+3),r-mid)%MOD)%MOD;
	a[x*2].lazya=(a[x*2].lazya+a[x].lazya)%MOD;a[x*2].lazyb=(a[x*2].lazyb+a[x].lazyb)%MOD;
	a[x*2+1].lazya=(a[x*2+1].lazya+getnum(a[x].lazya,a[x].lazyb,mid-l+2))%MOD;
	a[x*2+1].lazyb=(a[x*2+1].lazyb+getnum(a[x].lazya,a[x].lazyb,mid-l+3))%MOD;
	a[x].lazya=0;a[x].lazyb=0;
}
void modify(int x,int l,int r,int tx,int ty)
{
	//cout<<x<<" "<<l<<" "<<r<<" "<<tx<<" "<<ty<<endl;
	if(l>=tx && r<=ty)
	{
		a[x].sum=(a[x].sum+getsum(fib[l-tx+1],fib[l-tx+2],r-l+1))%MOD;
		a[x].lazya=(a[x].lazya+fib[l-tx+1])%MOD;
		a[x].lazyb=(a[x].lazyb+fib[l-tx+2])%MOD;
		return;
	}
	down(x,l,r);
	int mid=(l+r)/2;
	if(mid>=tx)modify(x*2,l,mid,tx,ty);
	if(mid<ty)modify(x*2+1,mid+1,r,tx,ty);
	a[x].sum=(a[x*2].sum+a[x*2+1].sum)%MOD;
}
long long query(int  x,int l,int r,int tx,int ty)
{
	if(l>=tx && r<=ty)
	{
		return a[x].sum;
	}
	int mid=(l+r)/2;
	down(x,l,r);
	long long ret=0;
	if(mid>=tx)
	{
		ret=(ret+query(x*2,l,mid,tx,ty))%MOD;
	}
	if(mid<ty)
	{
		ret=(ret+query(x*2+1,mid+1,r,tx,ty))%MOD;
	}
	return ret;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	fib[1]=1;
	he[1]=1;
	for(int i=2;i<=n+2;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
		he[i]=(he[i-1]+fib[i])%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i]);
	}
	build(1,1,n);
	while(m--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			modify(1,1,n,l,r);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%I64d\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
