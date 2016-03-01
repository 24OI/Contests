#include<iostream>
#include<cstdio>
#define ll long long
#define mod 593119681
using namespace std;
int n,m,t;
ll a[50000];
struct ma{ll v[70][70];}jz;
ma operator*(ma p,ma q)
{
	ma o;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) o.v[i][j]=0;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) for(int k=0;k<m;k++) (o.v[i][j]+=p.v[i][k]*q.v[k][j])%=mod;
	return o;
}
ma operator^(ma p,int q)
{
	ma o;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) o.v[i][j]=0;
	for(int i=0;i<m;i++) o.v[i][i]=1;
	while(q)
	{
		if(q&1) o=o*p;
		p=p*p;
		q/=2;
	}
	return o;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	cin>>n>>t;
	m=(1<<n);
	for(int i=0;i<m;i++) scanf("%lld",&a[i]);
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
	{
		int s=0;
		for(int p=0;p<n;p++) if((i&(1<<p))^(j&(1<<p))) s++;
		if(s==1) jz.v[i][j]++;
	}
	for(int i=0;i<m;i++) jz.v[i][i]=1;
	ma x=jz^t;
	for(int i=0;i<m;i++)
	{
		ll ans=0;
		for(int j=0;j<m;j++) (ans+=a[j]*x.v[j][i])%=mod;
		printf("%lld ",ans);
	}
}
