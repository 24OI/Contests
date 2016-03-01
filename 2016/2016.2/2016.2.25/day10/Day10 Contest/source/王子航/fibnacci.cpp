#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000001
using namespace std;
int n,m;
long long a[100010],f[100010];
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>=mod)a[i]%=mod;
	}
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=mod)f[i]-=mod;
	}
	for(int i=1;i<=m;i++)
	{
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			for(int j=l;j<=r;j++)
			{
				a[j]+=f[j-l+1];
				if(a[j]>=mod)a[j]-=mod;
			}
		}
		else
		{
			long long sum=0;
			for(int j=l;j<=r;j++)
			{
				sum+=a[j];
				if(sum>=mod)sum-=mod;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
	
