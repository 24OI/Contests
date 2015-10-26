#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 2100
#define ll long long 
int val[N];
int be[N],en[N];
struct node
{
	int pos,zt,bel;
}a[N*2];
int n,m,k;
int cnt;
int ans,poi;
int nex[N],has[N],fin[N],num,te[N],use[N];
int f[N][N][3];
int cmp(node x,node y)
{
	return x.pos<y.pos;
}
int cmp1(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&be[i],&en[i]);
		a[++cnt].pos=be[i];
		a[cnt].zt=1;
		a[cnt].bel=i;
		a[++cnt].pos=en[i];
		a[cnt].zt=2;
		a[cnt].bel=i;
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].zt==1)
		{
			if(a[i+1].zt==1)
			val[a[i].bel]+=a[i+1].pos-a[i].pos;
		}
		else
		{
			if(a[i-1].zt==2||(a[i-1].bel==a[i].bel))
			val[a[i].bel]+=a[i].pos-a[i-1].pos;
		}
	}
	for(int i=1;i<cnt;i++)
	{
		if(a[i].zt==2&&a[i+1].zt==1)
		ans+=a[i+1].pos-a[i].pos;
	}
	ans+=a[1].pos;
	ans+=m-a[cnt].pos;
	for(int i=1;i<cnt;i++)
	{
		if(a[i].zt==1&&a[i+1].zt==2&&a[i+1].bel!=a[i].bel)
		{	
			nex[a[i].bel]=a[i+1].bel;
			te[a[i+1].bel]=a[i+1].pos-a[i].pos;
			use[a[i+1].bel]=1;
		}
	}
	poi=1;
	while(poi<=n)
	{
		for(int i=poi;i;i=nex[i])
		{	
			fin[++num]=i;
			has[i]=1;
		}
		while((has[poi]||use[poi])&&poi<=n)
		poi++;
	}
	f[1][1][1]=val[fin[1]];
	f[1][0][0]=0;
	for(int i=2;i<=n;i++)
	for(int j=0;j<=k&&j<=i;j++)
	{
		f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
		if(j!=0)
		f[i][j][1]=max(f[i-1][j-1][1]+val[fin[i]]+te[fin[i]],f[i-1][j-1][0]+val[fin[i]]);
	}
	ans+=max(f[n][k][0],f[n][k][1]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}




