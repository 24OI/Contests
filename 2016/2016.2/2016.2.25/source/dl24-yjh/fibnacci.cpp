#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const long long mod=1000000001;
int n,m,l,r,op;
long long ans;
int a[100001];
int f[100001];

int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=mod;
		}

	f[0]=0;
	f[1]=1;
	for (int i=2; i<1001;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=0;i<m;i++)
	{
		scanf("%d %d %d",&op,&l,&r);
		ans=0;
		if (op==1) 
			{
				for (int j=l;j<=r;j++)
				{
					a[j]+=f[j-l+1];
					a[j]%=mod;
					}
				}
		else 
			{
				for (int j=l;j<=r;j++)
				{
					ans+=a[j];
					ans%=mod;
					}
//				for (int j=1;j<=n;j++)
//					cout<<f[j]<<endl;
				printf("%d\n",ans);
				}
		}
	
	return 0;
	}