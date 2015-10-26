#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int n,m,k,ans,v[1007],map[1007][1007];
struct ser
{
	int s,t,w,pos;
}a[2007];
struct sev
{
	int w,s,t,pos;
}b[4007];
priority_queue<ser> q;

bool cmp(sev x,sev y)
{
	return x.w<y.w;
}

bool operator < (ser x,ser y)
{
	return x.w<y.w;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].s,&a[i].t);
		a[i].pos=i;
		b[(i<<1)-1].w=a[i].s,b[(i<<1)-1].s=1,b[(i<<1)-1].pos=i;
		b[i<<1].w=a[i].t,b[i<<1].t=1,b[i<<1].pos=i;
	}
	sort(b+1,b+n+n+1,cmp);
	for(int i=1;i<=2*n;i++)
	{
		if(b[i].s)
		{
			if(b[i-1].s)
			{
				a[b[i-1].pos].w+=b[i].w-b[i-1].w;
			}
			else
			{
				ans+=b[i].w-b[i-1].w;
			}
		}
		else
		{
			if(b[i-1].s)
			{
				if(b[i-1].pos==b[i].pos)
				{
					a[b[i].pos].w+=b[i].w-b[i-1].w;
				}
				else
				{
					map[b[i].pos][b[i-1].pos]+=b[i].w-b[i-1].w;
					map[b[i-1].pos][b[i].pos]+=b[i].w-b[i-1].w;
				}
			}
			else
			{
				a[b[i].pos].w+=b[i].w-b[i-1].w;
			}
		}
	}
	ans+=m-b[2*n].w;
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
	}
	v[0]=1;
	for(int i=1;i<=k;i++)
	{
		ser now;
		now.pos=0;
		while(v[now.pos])
		{
			now=q.top();
			q.pop();
		}
		v[now.pos]=1;
		ans+=now.w;
		for(int i=1;i<=n;i++)
		{
			if(map[now.pos][i]&&i!=now.pos)
			{
				a[i].w+=map[now.pos][i];
				q.push(a[i]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
