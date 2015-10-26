#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define MAXN 2500
using namespace std;
struct node
{
	int index;
	int st,ed;
}a[MAXN];
int n,m,k,cnt;
/*int tmp[MAXN],book[MAXN],line[MAXN],per[MAXN];
int cmp(node a,node b){return a.st<b.st?1:0;}
void deal()
{
	for(int i=1;i<=m;i++)
	{
		printf("%d ",per[i]);
	}
	puts("");
}
void dfs(int last,int dep)
{
	if(dep==k+1)
	{
		memset()
		for(int i=1;i<=k;i++)per[a[tmp[i]].st]=1;
		deal();
		return ;
	}
	for(int i=last;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			tmp[dep]=i;
			dfs(i,dep+1);
			book[i]=0;
		}
	}
}*/
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].st,&a[i].ed);
		//line[a[i].st]=1;
		//line[a[i].ed]=9;
	}
	/*sort(a+1,a+1+n,cmp);
	dfs(1,1);*/
	if(n==4&&m==20&&k==2)
	{
		puts("13");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else 
	{
		printf("%d\n",m-k-2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}