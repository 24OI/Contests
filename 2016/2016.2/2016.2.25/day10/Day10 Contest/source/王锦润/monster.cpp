#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 1050
#define maxm 1000010
using namespace std;
const int mod=593119681;
int n,N,t,now,last=1;
int g[maxn],v[maxm],next[maxm],eid;
int res[2][maxn];
inline void addedge(int a,int b)
{
	v[eid]=b,next[eid]=g[a],g[a]=eid++;
	v[eid]=a,next[eid]=g[b],g[b]=eid++;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&t);N=1<<n;
	for(int i=0;i<N;i++)
	for(int j=0;j<i;j++)
	{
		int x=i^j;
		if(x&&x==(x&-x))addedge(i,j);
	}
	for(int i=0;i<N;i++)scanf("%d",&res[last][i]);
	for(int T=1;T<=t;T++,swap(now,last))
	{
		memset(res[now],0,sizeof(res[now]));
		for(int u=0;u<N;u++)
		{
			for(int i=g[u];i+1;i=next[i])
			{
				res[now][u]+=res[last][v[i]];
				if(res[now][u]>=mod)res[now][u]-=mod;
			}
			res[now][u]+=res[last][u];
			if(res[now][u]>=mod)res[now][u]-=mod;
		}
	}
	for(int i=0;i<N;i++)printf("%d ",res[last][i]);
	printf("\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
