#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 1030
#define Mod 593119681
using namespace std;
int ln,n,t,v[nMax],no[nMax];
struct jz
{
	int v[100][100];
}c1,c2,cans,ans,yu,dw;
void cf()
{
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
		cans.v[i][j]=0;
		for(int k=0;k<=n;k++)
		{
			cans.v[i][j]+=((long long)c1.v[i][k]*c2.v[k][j])%Mod;
			cans.v[i][j]%=Mod;
		}
	}
}
void power(int a)
{
// 	if(a==0) {ans=dw; return ;}
if(a==1) {ans=yu; return;}
	power(a>>1);
	c1=ans; c2=ans;
	cf();
	if(a&1) {c1=cans; c2=yu; cf();}
	ans=cans;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&ln,&t);
	n=1<<ln; n--;
	for(int i=0;i<=n;i++) scanf("%d",&v[i]);
	if(ln<=6&&0)
	{
		for(int i=0;i<=n;i++) yu.v[i][i]=dw.v[i][i]=1;
		for(int i=0;i<=n;i++)
		for(int j=0;j<ln;j++)
		{
			int now=i^(1<<j);
			yu.v[now][i]=1;
		}
		power(t);
		for(int i=0;i<=n;i++)
		{
			int ls=0;
			for(int j=0;j<=n;j++)
			{
				ls+=((long long)ans.v[j][i]*v[j])%Mod;
				ls%=Mod;
			}
			printf("%d ",ls);
		}
	} else
	{
		int *x=v,*y=no;
		if(t>10000&&n>10000) {printf("wobukaping\n"); return 0;}
		for(int i=1;i<=t;i++)
		{
			for(int j=0;j<=n;j++) y[j]=x[j];
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<ln;k++)
				{
					int now=j^(1<<k);
					y[j]+=x[now];
					y[j]%=Mod;
				}
			}
			swap(x,y);
		}
		for(int i=0;i<=n;i++) printf("%d ",x[i]);
	}
	return 0;
}
