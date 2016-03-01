#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1<<7;
const ll mod=593119681;
int n,m,x,y,z,t,B[40];
ll ss[N],s[N][N];
int pd(int x)
{
	for(int i=0;i<=30;i++)
	{
		if(x==B[i]) return 1;
		if(x<B[i]) return 0;
	}
}
void solve()
{
	ll s1[N],i,j,k;
	for(i=1;i<=n;i++)
		s1[i]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s1[j]=(s1[j]+ss[i]*s[i][j])%mod;
	for(i=1;i<=n;i++)
		ss[i]=s1[i];
}
void quick()
{
	ll s1[N][N],i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s1[i][j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				s1[i][j]=(ll)(s1[i][j]+s[i][k]*s[k][j])%mod;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s[i][j]=s1[i][j];
}
void solve1()
{
	int a,b,c,i,j,u,v;
	static int cnt[1<<11],e[1<<11][1<<11];
	static ll s[1<<11],ss[1<<11];
	for(i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(pd((i-1)^(j-1))||i==j) e[i][++cnt[i]]=j;
	while(t--)
	{
		for(i=1;i<=n;i++)
			ss[i]=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=cnt[i];j++)
				ss[e[i][j]]=(ll)(ss[e[i][j]]+s[i])%mod;
		for(i=1;i<=n;i++)
			s[i]=ss[i];
	}
	for(i=1;i<=n;i++)
		if(i<n)printf("%lld ",ss[i]);
		else printf("%lld\n",ss[i]);
}
int main()
{
	int a,b,c,i,j;
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	B[0]=1;
	for(i=1;i<=30;i++)
		B[i]=B[i-1]*2;
	scanf("%d%d",&m,&t);
	n=B[m];
	if(t<=1000)
	{
		solve1();
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(pd((i-1)^(j-1))||i==j) 
				s[i][j]=1;
	for(i=1;i<=n;i++)
		scanf("%lld",&ss[i]);
	while(t>0)
	{
		if(t%2) solve();
		quick();
		t/=2;
	}
	for(i=1;i<=n;i++)
		if(i<n)printf("%lld ",ss[i]);
		else printf("%lld\n",ss[i]);
}
