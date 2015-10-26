#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[1000100];
int b[1000100],su[1000100],tt;
int main()
{
	int n;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)scanf("%d",&a[i]);
	a[0]=0;
	for(int i=1;i<=n-1;i++)b[++tt]=a[i];
	int ma=0,ji=-1;
	int cnt=0;
	long long ans=0ll;
	for(int i=1;i<=tt;i++)
	{
		if(b[i]==0)cnt+=10;
		if(b[i]>ma+1)
		{
			if(b[i]==ma+2)
			cnt++;
			else cnt+=10;
			ji=i;
		}
		ma=max(ma,b[i]);
	}
	if(cnt>=2)
	{
		cout<<0<<endl;
		
	}
	else if(cnt==1)
	{
		ma=0;
		for(int i=1;i<=ji;i++)
		{
			if(a[i-1]+1==b[ji]-1)ans++;
		}
		cout<<ans<<endl;
	}
	else
	{
		int tr=0;
		for(int i=1;i<=tt;i++)if(b[i]!=b[i-1])tr++;
		int ma=0;
		for(int i=1;i<=tt+1;i++)
		{
//			cout<<"i "<<i<<" "<<b[i]<<endl;
			ans+=ma+1;
			if(b[i]<=ma+1&&b[i]>=1)ans--;
			if(b[i-1]<=ma+1&&b[i-1]>=1&&b[i-1]!=b[i])ans--;
//			cout<<"compare "<<b[i]<<" "<<b[i-1]<<endl;
//			cout<<ans<<" "<<ma<<endl;
			ma=max(b[i],ma);
		}
		ans+=tr;
		cout<<ans<<endl;
	}
	return 0;
}
