#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,ans,temp,v[1000007],a[1000007];
bool pan;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%lld",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>i)
		{
			puts("0");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(pan)
		{
			if(a[i]==i)
			{
				if(!v[a[i]-1])
				{
					puts("0");
					return 0;
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			if(a[i]==i)
			{
				if(!v[a[i]-1])
				{
					if(v[a[i]-2])
					{
						ans=v[a[i]-2];
						v[a[i]-1]=1;
						pan=1;
					}
					else
					{
						puts("0");
						return 0;
					}
				}
				else
				{
					if(!v[a[i]])
					{
						v[a[i]]++;
						temp++;
					}
					else
					{
						ans+=temp;
					}
				}
			}
			else
			{
				if(!v[a[i]])
				{
					v[a[i]]++;
					temp++;
				}
				else
				{
					v[a[i]]++;
				}
				ans+=temp;
			}			
		}
	}
	if(!pan)
	{
		ans-=n-1;
	}
	printf("%lld\n",ans);
	return 0;
}
