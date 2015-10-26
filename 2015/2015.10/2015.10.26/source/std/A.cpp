#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 1001001
using namespace std;
int n,a[M];
long long ans;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,temp=0;
	cin>>n;n--;
	int max_val=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]-max_val>2)
			return puts("0"),0;
		if(a[i]-max_val==2)
		{
			if(temp)
				return puts("0"),0;
			temp=a[i];
		}
		max_val=max(max_val,a[i]);
	}
	max_val=0;
	for(i=1;i<=n+1;i++)
	{
		if(temp)
		{
			if(max_val==temp-2)
				++ans;
		}
		else
		{
			ans+=max_val+1;
			if(a[i]>0 && a[i]<=max_val+1)
				--ans;
		}
		max_val=max(max_val,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
