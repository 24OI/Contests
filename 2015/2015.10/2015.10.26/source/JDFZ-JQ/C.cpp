#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[10];
int n;
int st[100005],en[100005],tim[100005];
int num[400005];
int cnt;
int he=0;
int yuan[400005];
int ans=0x3f3f3f3f;
void dfs(int dep,int sum,int last,int tot)
{
	if(dep>n)return ;
	if(sum==he)
	{
		ans=min(ans,tot);
		return ;
	}
	for(int i=1;i<=cnt;i++)
	{
		yuan[i]=num[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i==last)continue;
		int cha=0;
		for(int j=st[i];j<=en[i];j++)
		{
			cha+=(num[j]==1?-1:1);
			num[j]=1-num[j];
		}
		dfs(dep+1,sum+cha,i,tot+tim[i]);
		for(int j=st[i];j<=en[i];j++)
		{
			num[j]=1-num[j];
		}
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int nn=0;
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&a[i]);
		he+=a[i];
		nn+=(i%2==1?a[i]:0);
		for(int j=1;j<=a[i];j++)
		{
			num[++cnt]=i%2;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&st[i],&en[i]);
		tim[i]=en[i]-st[i]+1;
	}
	dfs(0,nn,0,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
