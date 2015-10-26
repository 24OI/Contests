#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 2200
using namespace std;
typedef long long ll;
int n,m,len,k,ans;
int L[N],R[N];
int dis[N<<1];
int cov[N<<1];
int a[N];
bool cho[N];
int calc()
{
	int ret=0;
	for(int i=1;i<len;i++)
	{
		if((cov[i]&2)&&(cov[i+1]&1))
			ret+=dis[i+1]-dis[i];
	}
	return ret;
}
void dfs(int deep,int cnt)
{
	if(cnt>k)	return ;
	if(deep==n)
	{
		ans=max(ans,calc());
		return ;
	}
	cov[L[deep+1]]=3;
	cov[R[deep+1]]=3;
	dfs(deep+1,cnt+1);
	cov[L[deep+1]]=1;
	cov[R[deep+1]]=2;
	dfs(deep+1,cnt);
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",L+i,R+i);
		dis[i+i-1]=L[i];
		dis[i+i]=R[i];
	}
	dis[n+n+1]=0,dis[n+n+2]=m;
	len=n+n+2;
	sort(dis+1,dis+len+1);
	for(i=1;i<=n;i++)
	{
		L[i]=lower_bound(dis+1,dis+len+1,L[i])-dis;
		R[i]=lower_bound(dis+1,dis+len+1,R[i])-dis;
		cov[L[i]]=1;
		cov[R[i]]=2;
	}
	cov[1]=cov[len]=3;
	if(n<=20)
	{
		dfs(0,0);
	}
	else
	{
		srand(140142);
		for(i=1;i<=n;i++)
			a[i]=i;
		for(i=1;i<=5000;i++)
		{
			random_shuffle(a+1,a+n+1);
			for(j=1;j<=k;j++)
				cov[L[a[j]]]=3,cov[R[a[j]]]=3;
			ans=max(ans,calc());
			for(j=1;j<=k;j++)
				cov[L[a[j]]]=1,cov[R[a[j]]]=2;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

