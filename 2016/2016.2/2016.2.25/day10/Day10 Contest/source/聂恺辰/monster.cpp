#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,t,s;
long long mod=593119681;
struct ppp {long long a[101][101];
void print()
{
	int i,j;
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		cout<<a[i][j]<<' ';
		cout<<endl;
	}
}};
ppp ans,st;
ppp operator *(ppp x,ppp y)
{
	memset(ans.a,0,sizeof(ans.a));
	long long i,j,k;
	for(i=0;i<s;i++)
	for(j=0;j<s;j++)
	{
		for(k=0;k<s;k++)
		ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
	}
	return ans;
}
ppp th;
ppp ksm(ppp d,long long c)
{
	th=st;
	while(c)
	{
		if(c&1) th=th*d;
		d=d*d;c/=2;
	}
	return th;
}
long long a[10001];
long long b[1100][1100];
long long f[1100][1100];
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	long long i,j,k;
	scanf("%lld%lld",&n,&t);
	s=(1<<n);
	for(i=0;i<s;i++)
	scanf("%lld",&a[i]);
	if(n<=6)
	{
		for(i=0;i<s;i++) st.a[i][i]=1;
		ppp di,now;
		memset(di.a,0,sizeof(di.a));
		for(i=0;i<s;i++)
		{
			for(j=0;j<s;j++)
			{
				for(k=0;k<n;k++)
				if((i^j)==(1<<k)||(i==j))
				di.a[i][j]=1;
			}
		}
		now=ksm(di,t);
		for(i=0;i<s;i++)
		{
			long long an=0;
			for(j=0;j<s;j++)
			an=(an+a[j]*now.a[j][i])%mod;
			printf("%lld ",an);						
		}
		return 0;
	}
	for(i=0;i<s;i++) f[0][i]=a[i];
	for(i=1;i<=t;i++)
	for(j=0;j<s;j++)
	{
		f[i][j]=f[i-1][j];
		for(k=0;k<n;k++)
		f[i][j]+=f[i-1][j^(1<<k)];
		f[i][j]%=mod;
	}
	for(i=0;i<s;i++)
	printf("%lld ",f[t][i]);
}
