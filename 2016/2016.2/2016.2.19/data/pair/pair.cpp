#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20010;
const int M=400010;
int n,m,i,j,k,l,lose,ans[M],vis[N],Xor[N],save[N],deep[N];
int head[N],list[M],next[M],tot=1;
void add(int a,int b)
{
	tot++;
	list[tot]=b;
	next[tot]=head[a];
	head[a]=tot;
}
int dfs(int x,int fa)
{
	deep[x]=deep[list[fa]]+1;
	vis[x]=1;
	for(int i=head[x];i;i=next[i])
	if(i!=fa)
	{
		if(vis[list[i]])
		{
			if(deep[list[i]]<deep[x])
			{
				Xor[list[i]]^=1;
				ans[i>>1]=i&1;
			}
		}
		else
		{
			Xor[list[i]]^=1;
			ans[i>>1]=i&1;
			int k=dfs(list[i],i^1);
			Xor[x]^=k;
		}
	}
	if(Xor[x])ans[fa>>1]^=1;
	return Xor[x];
}
int main()
{
	freopen("pair9.in","r",stdin);
	freopen("pair9.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&j,&k);
		add(j,k);add(k,j);
	}
	for(i=1;i<=n&&!lose;i++)
	if(!vis[i]&&dfs(i,0)!=0)lose++;
	printf("%d\n",(m-lose)/2);
	for(i=1;i<=m;i++)
	{
		if(save[list[(i<<1)^ans[i]]]==0)save[list[(i<<1)^ans[i]]]=(i<<1)^ans[i];
		else
		{
			printf("%d %d\n",save[list[(i<<1)^ans[i]]]>>1,((i<<1)^ans[i])>>1);
			save[list[(i<<1)^ans[i]]]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
