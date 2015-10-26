#include<bitset>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 500100
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
typedef long long ll;
bitset<N>op[15],now;
int n,cost[15];
ll ans;
void dfs(int deep,ll c)
{
	if(deep==n)
	{
		if(now.count()==0)
			ans=min(ans,c);
		return ;
	}
	now^=op[deep+1];
	dfs(deep+1,c+cost[deep+1]);
	now^=op[deep+1];
	dfs(deep+1,c);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int m,i,j,k,l,r;
	int A,B,C,D,E;
	scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&n);
	if(n<=10)
	{
		m=A+B+C+D+E;
		for(i=1,k=1;i<=A;i++)
			now[k++]=0;
		for(i=1;i<=B;i++)
			now[k++]=1;
		for(i=1;i<=C;i++)
			now[k++]=0;
		for(i=1;i<=D;i++)
			now[k++]=1;
		for(i=1;i<=E;i++)
			now[k++]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			cost[i]=r-l+1;
			op[i]=0;
			for(j=l;j<=r;j++)
			{
				op[i][j]=1;
			}
		}
		ans=INF;
		dfs(0,0);
		if(ans!=INF)
			printf("%lld\n",ans);
		else
			puts("-1");
	}
	else
	{
		puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

