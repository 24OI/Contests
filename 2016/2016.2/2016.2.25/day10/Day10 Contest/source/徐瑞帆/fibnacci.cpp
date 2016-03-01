#include<cstdio>
#include<algorithm>
#define N 100010
#define mod (int)(1e9+1)
using namespace std;
int f[N]={0,1},n,m,a[N];
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	f[i]=(f[i-1]+f[i-2])%mod;
	int x,y,z;
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
		{
			for(int i=y;i<=z;i++)
			a[i]=(a[i]+f[i-y+1])%mod;
		}
		else
		{
			int sum=0;
			for(int i=y;i<=z;i++)
			sum=(sum+a[i])%mod;
			printf("%d\n",sum);
		}
	}
}