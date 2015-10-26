#include<stdio.h>
typedef long long ll;
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll n;
ll b[1000005];
ll tmp[1000005];
ll ans;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%lld",&n);
	ll limit=0;
	for(ll i=1;i<n;i++)
	{
		scanf("%lld",&b[i]);
		tmp[i+1]=max(tmp[i],b[i]);
		if(tmp[i]+1<b[i])
		{
			limit=max(limit,b[i]);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		ll l=max(1,limit-1);
		ll r=min(i,tmp[i]+1);
		if(l>r)
		{
			if(b[i]>r)
			{
				break;
			}
			continue;
		}
		ans+=r-l+1;
		if(i>1&&l<=b[i-1]&&b[i-1]<=r)
		{
			ans--;
		}
		if(b[i]>r)
		{
			break;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
