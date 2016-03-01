#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N=50000;
const int mod=1000000001;

int n,m,l,r,a[N],f[N],tmp;

int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0]=0; f[1]=1;
	for (int i=2; i<=n; i++) f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		a[i]=a[i]%mod;
	}
	while (m--)
	{
		scanf("%d%d%d",&tmp,&l,&r);
		if (tmp==1)
		  for (int i=l; i<=r; i++)
		    a[i]=(a[i]+f[i-l+1])%mod;
		if (tmp==2)
		{
			int sum=0;
			for (int i=l; i<=r; i++) sum=(sum+a[i])%mod;
			printf("%d\n",sum);
		}
	}
	return 0;
}
