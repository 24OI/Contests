#include<stdio.h>
#define N 1100000
#define ll long long 
int check[N],a[N],has[N];
int n;
ll flag,ans,tmp,cnt;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d",&a[i]);
	check[0]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<1)
		{
			printf("0\n");
			return 0;
		}
		if(!check[a[i]-1])
		{
			if(!check[a[i]-2]||(flag&&tmp!=a[i]-1))
			{
				printf("0\n");
				return 0;
			}
			flag=1;
			tmp=a[i]-1;
			if(tmp<1)
			{
				printf("0\n");
				return 0;
			}
		}
		check[a[i]]=1;
	}
	if(flag)
	{
		has[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(has[tmp-1]&&a[i-1]!=tmp)
			{
				ans++;
			}
			has[a[i]]=1;
			if(!has[a[i]-1])
			break;
		}
		printf("%lld\n",ans);
		return 0;
	}	
	has[0]=1;
	cnt++;
	for(int i=1;i<n;i++)
	{
		ans+=cnt;
		if(has[a[i]-1])
		ans--;
		if(!has[a[i]])
		{
			has[a[i]]=1;
			cnt++;
		}	
	}
	ans+=cnt;
	printf("%lld\n",ans);
	return 0;
}





