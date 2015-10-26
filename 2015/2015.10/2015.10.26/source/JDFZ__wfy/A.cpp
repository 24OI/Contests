#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 1000100
using namespace std;
typedef long long ll;
int B[N],MI[N],MA[N];
int n,sum[N];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	x++;
	while(x<=n)
	{
		sum[x]++;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ret=0;
	x++;
	while(x)
	{
		ret+=sum[x];
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int m,i,j,k,flag;
	ll ans;
	scanf("%d",&n);
	add(0);
	flag=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",B+i);
		if(query(B[i]-1)==B[i])
		{
			if(query(B[i])-query(B[i]-1)==0)
				add(B[i]);
		}
		else
		{
			if(flag==0&&query(B[i]-2)==B[i]-1)
			{
				flag=1;
				for(j=0;j<i;j++)
					if(B[j]==B[i]-2)
						break;
				ans=i-j;
				add(B[i]-1),add(B[i]);
			}
			else
			{
				flag=-1;
				ans=0;
			}
		}
	}
	if(flag==0)
	{
		ans=0;
		for(i=0,j=0;i<n;i++)
		{
			j=max(B[i],j);
			ans+=j+1;
			if(i!=n-1&&j+1>=B[i+1])
				ans--;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

