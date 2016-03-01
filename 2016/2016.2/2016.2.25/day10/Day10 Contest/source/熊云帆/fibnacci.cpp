#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int N=101000,mod=1000000001;

int n,m,a[N],f[N];
int op,l,r;
void solve1();
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1]=1;
	for (int i=2;i<=n;i++)	
		f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);		
	solve1();
	return 0;
}
void solve1()
{	
	int tot;		
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&l,&r);
		if (op==1)
			for (int i=0;i+l<=r;i++)
				a[l+i]=(a[l+i]+f[i+1])%mod;
		if (op==2)
		{
			tot=0;
			for (int i=l;i<=r;i++)
				tot=(tot+a[i])%mod;
			printf("%d\n",tot);
		}
	}
}

