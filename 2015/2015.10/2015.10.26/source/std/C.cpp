#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 500500
using namespace std;

struct abcd{
	int to,f,next;
}table[M<<1];
int head[M],tot;
void Add(int x,int y,int z)
{
	table[++tot].to=y;
	table[tot].f=z;
	table[tot].next=head[x];
	head[x]=tot;
}

int n,A,B,C,D,E;
int p[4];
long long dis[4][4];
long long f[M];

namespace Heap{
	int heap[M],pos[M],top;
	void Push_Up(int t)
	{
		while(t>1)
		{
			if( f[heap[t]] < f[heap[t>>1]] )
				swap(heap[t],heap[t>>1]),swap(pos[heap[t]],pos[heap[t>>1]]),t>>=1;
			else
				break;
		}
	}
	void Insert(int x)
	{
		heap[pos[x]=++top]=x;
		Push_Up(top);
	}
	void Pop()
	{
		heap[1]=heap[top--];
		pos[heap[1]]=1;
		int t=2;
		while(t<=top)
		{
			if( t<top && f[heap[t+1]]<f[heap[t]] )
				++t;
			if( f[heap[t]] < f[heap[t>>1]] )
				swap(heap[t],heap[t>>1]),swap(pos[heap[t]],pos[heap[t>>1]]),t<<=1;
			else
				break;
		}
	}
}

void Dijkstra(int _)
{
	using namespace Heap;
	int i;
	memset(f,0x3f,sizeof f);
	f[p[_]]=0;
	for(i=0;i<=A+B+C+D+E;i++)
		Insert(i);
	while(top)
	{
		int x=heap[1];Pop();
		for(i=head[x];i;i=table[i].next)
			if(f[table[i].to]>f[x]+table[i].f)
			{
				f[table[i].to]=f[x]+table[i].f;
				Push_Up(pos[table[i].to]);
			}
	}
	for(i=0;i<4;i++)
		dis[_][i]=f[p[i]];
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,x,y,z;
	cin>>A>>B>>C>>D>>E>>n;
	p[0]=A;
	p[1]=A+B;
	p[2]=A+B+C;
	p[3]=A+B+C+D;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		--x;z=y-x;
		Add(x,y,z);
		Add(y,x,z);
	}
	for(i=0;i<4;i++)
		Dijkstra(i);
	long long ans=min(min(dis[0][1]+dis[2][3],dis[0][2]+dis[1][3]),dis[0][3]+dis[1][2]);
	if(ans>=0x3f3f3f3f3f3f3f3fll)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
