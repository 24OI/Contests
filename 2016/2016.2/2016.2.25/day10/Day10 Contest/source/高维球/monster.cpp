#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=593119681;
int dp[2][2333],a[2333];

int x(int a)
{
	if(!a)return 0;
	return (a&1)+x(a>>1);
}

int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout); 
	int i,j,k,m,n,tot,o,p,ans;
	scanf("%d%d",&n,&m);
	o=0;
	p=1;
	dp[0][0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[p][j]=((ll)dp[o][j]+(ll)dp[o][j-1]*j+(ll)dp[o][j+1]*(n-j))%mod;
			//printf("%d ",dp[p][j]);
		}
		swap(o,p);
		//printf("\n");
	}
	for(i=0;i<(1<<n);i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<(1<<n);i++)
	{
		ans=0;
		for(j=0;j<(1<<n);j++)
		{
			ans=((ll)ans+(ll)a[j]*(ll)dp[o][x(i^j)])%mod;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
