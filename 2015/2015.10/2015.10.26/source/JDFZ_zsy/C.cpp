#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <map>
using namespace std;
int n;
int a,b,c,d,e;
int v[1000000];
int ans=999999999;
struct node
{
	int l;
	int r;
}x[100001];
int cmp(node a,node b)
{
	if(a.l!=b.l)
	{
		return a.l<b.l;
	}
	return a.r<b.r;
}
int check()
{
	int tmp=0;
	for(int i=1;i<=a;i++)
	{
		tmp+=v[i];
		if(v[i]&1)
		{
			return 0;
		}
	}
	for(int i=a+1;i<=b;i++)
	{
		tmp+=v[i];
		if(v[i]%2==0)
		{
			return 0;
		}
	}
	for(int i=b+1;i<=c;i++)
	{
		tmp+=v[i];
		if(v[i]&1)
		{
			return 0;
		}
	}
	for(int i=c+1;i<=d;i++)
	{
		tmp+=v[i];
		if(v[i]%2==0)
		{
			return 0;
		}
	}
	for(int i=d+1;i<=e;i++)
	{
		tmp+=v[i];
		if(v[i]&1)
		{
			return 0;
		}
	}
	return tmp;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		return ;
	}
	for(int i=x[dep].l;i<=x[dep].r;i++)
	{
		v[i]++;
	}
	int g;
	g=check();
	if(g)
	{
		ans=min(ans,g);
	}
	dfs(dep+1);
	for(int i=x[dep].l;i<=x[dep].r;i++)
	{
		v[i]--;
	}
	g=check();
	if(g)
	{
		ans=min(ans,g);
	}
	dfs(dep+1);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	b+=a;
	c+=b;
	d+=c;
	e+=d;
	scanf("%d",&n);
	int mi=99999999;
	int ma=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i].l,&x[i].r);
		mi=min(mi,x[i].l);
		ma=max(ma,x[i].r);
	}
	dfs(1);
	if(ans==999999999)
	{
		puts("-1");
		return 0;
	} 
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
}