#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int to,next;
}edge[1000005];
int head[1000005];
int cc;
void add(int f,int t)
{
	edge[cc].to=t;
	edge[cc].next=head[f];
	head[f]=cc++;
}
int n;
int b[1000005];
bool flag;
int in[1000005];
bool tuobu1()
{
	queue<int>Q;
	for(int i=0;i<n;i++)
	{
		if(in[i]==0)
		{
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			in[v]--;
			if(in[v]==0)
			{
				Q.push(v);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(in[i]!=0)return false;
	}
	return true;
}
int a[1000005];
void init()
{
	memset(in,0,sizeof(in));
	memset(head,-1,sizeof(head));
	cc=0;
}
int f[500];
int met[500][500];
int differ[500];
int vis[500];
void dfs(int dep)
{
	if(dep==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=1;
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]>a[j]&&f[i]<f[j]+1)
				{
					f[i]=f[j]+1;
				}
			}
		}
		int k=1;
		int dif=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==b[k])k++;
			else
			{
				dif++;
				differ[dif]=i;
			}
		}
		if(dif==1)
		{
			met[differ[1]][f[differ[1]]]=1;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]>i)flag=1;
		if(b[i]>i+1)
		{
			printf("0\n");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	if(flag)
	{
		init();
		b[0]=1;
		for(int i=1;i<n;i++)
		{
			if(b[i]>b[i-1])
			{
				add(i-1,i);
				in[i]++;
			}else
			{
				add(i,i-1);
				in[i-1]++;
			}
		}
		if(tuobu1())
		{
			printf("1\n");
		}else
		{
			printf("0\n");
		}
	}else
	{
		dfs(1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(met[i][j])
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
