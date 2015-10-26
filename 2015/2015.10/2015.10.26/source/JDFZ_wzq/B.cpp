#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2010
using namespace std;
struct node
{
	int x;
	int no,flag;
	friend bool operator < (node a,node b)
	{
		return a.x<b.x;
	}
}pt[N<<1];
int map[N][N];
int p[N];
int belong[N];
int n,m,k,tot;
int ans;
int v[N];
void dfs(int now,int sum,int cnt)
{
	if(cnt+n-now+1<k)return;
	if(cnt>k)return;
	if(now==n+1)
	{
		if(cnt==k)
			ans=max(ans,sum);
		return;
	}
	v[now]=1;
	if(belong[now]!=0&&v[belong[now]]==1)
		dfs(now+1,sum+map[belong[now]][now]+p[now],cnt+1);
	else dfs(now+1,sum+p[now],cnt+1);
	v[now]=0;
	dfs(now+1,sum,cnt);
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		pt[++tot].x=x,pt[tot].no=i,pt[tot].flag=1;
		pt[++tot].x=y,pt[tot].no=i,pt[tot].flag=-1;
	}
	sort(pt+1,pt+tot+1);
	int tmp=0;
	for(int i=2;i<=tot;i++)
	{
		if(pt[i].flag==1&&pt[i-1].flag==1)
			p[pt[i-1].no]+=pt[i].x-pt[i-1].x;
		else if(pt[i].flag==1&&pt[i-1].flag==-1)
			tmp+=pt[i].x-pt[i-1].x;
		else if(pt[i].flag==-1&&pt[i-1].flag==1)
		{
			if(pt[i].no==pt[i-1].no)p[pt[i].no]+=pt[i].x-pt[i-1].x;
			else 
			{
				map[pt[i].no][pt[i-1].no]=pt[i].x-pt[i-1].x;
				belong[pt[i-1].no]=pt[i].no;
			}
		}else p[pt[i].no]+=pt[i].x-pt[i-1].x;
	}
	tmp+=pt[1].x+m-pt[tot].x;
	dfs(1,0,0);
	printf("%d\n",ans+tmp);
}