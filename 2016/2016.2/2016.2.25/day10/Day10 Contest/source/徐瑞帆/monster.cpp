#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2000
#define ll long long
#define mod 593119681
using namespace std;
int a[N],n,m,t,b[N];
struct matrix{int a[100][100];}q;
matrix operator*(const matrix&x,const matrix&y)
{
	matrix z;
	for(int i=0;i<=t;i++)
	for(int j=0;j<=t;j++)
	{
		ll now=0;
		for(int k=0;k<=t;k++)
		now+=(ll)x.a[i][k]*y.a[k][j]%mod;
		z.a[i][j]=now%mod;
	}
	return z;
}
matrix operator^(matrix x,int y)
{
	matrix p=x;y--;
	while(y)
	{
		if(y&1)p=p*x;
		x=x*x;y>>=1;
	}
	return p;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&m);
	t=(1<<n)-1;
	for(int i=0;i<=t;i++)
	scanf("%d",&a[i]);
	if(m>1000)
	{
		for(int i=0;i<=t;i++)
		for(int j=0;j<=t;j++)
		if(i!=j)q.a[i][j]=0;
		else q.a[i][i]=1;
		for(int i=0;i<=t;i++)
		for(int j=0;j<n;j++)
		q.a[i][i^(1<<j)]=1;
		q=q^m;
		for(int i=0;i<=t;i++)
		{
			int ans=0;
			for(int j=0;j<=t;j++)
			ans=(ans+(ll)q.a[i][j]*a[j]%mod)%mod;
			printf("%d ",ans);
		}
		return 0;
	}
	while(m--)
	{
		for(int i=0;i<=t;i++)
		{
			for(int j=0;j<n;j++)
			b[i^(1<<j)]=(b[i^(1<<j)]+a[i])%mod;
		}
		for(int i=0;i<=t;i++)a[i]=(a[i]+b[i])%mod,b[i]=0;
	}
	for(int i=0;i<=t;i++)
	printf("%d ",a[i]);
}