#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 2020
using namespace std;

struct abcd{
	int tim,belong,in_or_out;//in-0 out-1
	abcd() {}
	abcd(int _,int __,int ___):
		tim(_),belong(__),in_or_out(___) {}
	friend bool operator < (const abcd &x,const abcd &y)
	{
		return x.tim < y.tim ;
	}
}a[M<<1];

struct edge{
	int to,f,next;
}table[M<<1];
int head[M],tot;

int n,m,k,ans;
int b[M],degree[M];
bool v[M];
int stack[M],dis[M],top;
int f[M][M][2];

void Add(int x,int y,int z)
{
	++degree[x];
	table[++tot].to=y;
	table[tot].f=z;
	table[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x)
{
	int i,temp=0;
	v[x]=true;
	for(i=head[x];i;i=table[i].next)
		if(!v[table[i].to])
			temp=table[i].f,DFS(table[i].to);
	stack[++top]=b[x];
	dis[top]=temp;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		new (&a[i+i-1])abcd(x,i,1);
		new (&a[i<<1 ])abcd(y,i,0);
	}
	sort(a+1,a+n+n+1);
	ans+=a[1].tim;
	ans+=m-a[n+n].tim;
	for(i=1;i<n+n;i++)
	{
		int temp=a[i+1].tim-a[i].tim;
		if(a[i].in_or_out==1 && a[i+1].in_or_out==1)
			b[a[i].belong]+=temp;
		else if(a[i].in_or_out==1 && a[i+1].in_or_out==0)
		{
			x=a[i].belong;
			y=a[i+1].belong;
			if(x==y)
				b[x]+=temp;
			else
				Add(x,y,temp),Add(y,x,temp);
		}
		else if(a[i].in_or_out==0 && a[i+1].in_or_out==1)
			ans+=temp;
		else
			b[a[i+1].belong]+=temp;
	}
	for(i=1;i<=n;i++)
		if(!v[i]&&degree[i]<=1)
			DFS(i);
	memset(f,0xef,sizeof f);f[0][0][0]=0;
	for(i=1;i<=n;i++)
		for(j=0;j<=k;j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			if(j)
				f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j-1][1]+dis[i])+stack[i];
		}
	cout<<ans+max(f[n][k][0],f[n][k][1])<<endl;
	return 0;
}
