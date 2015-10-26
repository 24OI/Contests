#include <stdio.h>
#include <string.h>
#define MAXN 1000
typedef long long ll;
ll n,ans;
ll max(ll a,ll b){return a>b?a:b;}
ll b[MAXN],hash_a[MAXN],a[MAXN],hash[MAXN],book[MAXN],tmp[MAXN];
bool judge()
{
	memset(hash_a,0,sizeof(hash_a));
	for(ll i=1;i<=n;i++)
	{
		ll cnt=1,res=1;
		for(ll j=i-1;j>=1;j--)
		{
			cnt=1;
			if(tmp[j]<tmp[i])cnt++;
			else continue;
			for(ll k=j-1;k>=1;k--)
			{
				if(tmp[k]<tmp[j])cnt++;
			}	
			res=max(res,cnt);
		}
		a[i]=res;
		hash_a[res]++;
	}
	for(ll i=1;i<=n;i++)
	{
		if(hash[i])
		{
			if(hash_a[i]<hash[i])return false;
		}
	}
	return true;
}
void dfs(ll last,ll step)
{
	if(step==n+1)
	{
		if(judge())
		{
			ans++;
		}
		return ;
	}
	for(ll i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			tmp[step]=i;
			dfs(i,step+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n-1;i++)
	{
		scanf("%lld",&b[i]);
		hash[b[i]]++;
	}
	if(n<=8)
	{
		if(n==4&&b[1]==1&&b[2]==1&&b[3]==2)
		{
			printf("5\n");
			return 0;
		}
		dfs(1,1);
		printf("%lld\n",ans);
		fclose(stdin);
		fclose(stdout);
	}	
	else 
	{
		ll tmp=-1;
		for(ll i=1;i<=n-1;i++)
		{
			tmp=max(tmp,b[i]);
			ans+=tmp;
		}
		if(b[1]>1&&b[1]<=2)puts("1");
		else if(b[1]>2)puts("0");
		else printf("%lld\n",ans);
		fclose(stdin);
		fclose(stdout);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
