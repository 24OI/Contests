#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 100010
using namespace std;
typedef long long ll;
const ll mod=1000000001;
int n,m;
ll fib[maxn],num[maxn];
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d%lld",&n,&m,&num[1]);fib[1]=1;
	for(int i=2;i<=n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		scanf("%lld",&num[i]);
		if(fib[i]>=mod)fib[i]-=mod;
	}
	for(int i=1,op,l,r;i<=m;i++)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		for(int j=l;j<=r;j++)
		{
			num[j]+=fib[j-l+1];
			if(num[j]>=mod)num[j]-=mod;
		}else
		{
			ll res=0;
			for(int j=l;j<=r;j++)
			{
				res+=num[j];
				if(res>=mod)res-=mod;
			}
			printf("%lld\n",res);
		}
	}fclose(stdin);fclose(stdout);
	return 0;
}
