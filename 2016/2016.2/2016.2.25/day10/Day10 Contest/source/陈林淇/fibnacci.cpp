#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 1010
#define Mod 1000000009
using namespace std;
int n,m,fi[nMax],v[nMax];
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	fi[1]=1;
	for(int i=2;i<nMax;i++) fi[i]=(fi[i-1]+fi[i-2])%Mod;
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=m;i++)
	{
		int k,l,r;
		scanf("%d%d%d",&k,&l,&r);
		if(k==1)
		{
			for(int i=1;i<=r-l+1;i++)
			{
				v[l+i-1]+=fi[i];
				v[l+i-1]%=Mod;
			}
		} else
		{
			int ls=0;
			for(int i=l;i<=r;i++) {ls+=v[i]; ls%=Mod;}
			printf("%d\n",ls);
		}
	}
	return 0;
}
