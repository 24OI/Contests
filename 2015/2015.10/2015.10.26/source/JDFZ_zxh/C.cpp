#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#define MAXN 1500
using namespace std;
typedef long long ll;
struct node
{
	ll num[MAXN];
	ll ti;
};
char str[MAXN];
map<string,int>mp;
ll n,a,b,c,d,e,sum;
ll l[MAXN],r[MAXN];
bool judge(ll a[])
{
	for(ll i=1;i<=sum;i++)
	{
		if(a[i]!=1)return false;
	}
	return true;
}
ll bfs()
{
	node u;
	u.ti=0;
	for(ll i=1;i<=(a+b+c+d+e);i++)
	{
		if(i>=1&&i<=a)u.num[i]=1;
		if(i>a&&i<=b+a)u.num[i]=0;
		if(i>b+a&&i<=c+a+b)u.num[i]=1;
		if(i>c+a+b&&i<=d+a+b+c)u.num[i]=0;
		if(i>d+a+b+c&&i<=e+a+b+c+d)u.num[i]=1;
	}
	queue<node>Q;
	Q.push(u);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		if(judge(u.num))return u.ti;
		for(ll i=1;i<=n;i++)
		{
			node v;
			for(ll j=1;j<=sum;j++)v.num[j]=u.num[j];
			for(ll j=l[i];j<=r[i];j++)
			{
				v.num[j]=v.num[j]^1;
			}
			for(ll j=0;j<sum;j++)str[j]=v.num[j+1]+'0';
			if(mp[str]!=0)continue;
			mp[str]++;
			v.ti=u.ti+(r[i]-l[i]+1);
			Q.push(v);
		}
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	sum=a+b+c+d+e;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
	}
	if(n>=10000)
	{
		puts("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	ll ans=bfs();
	if(ans==0)puts("-1");
	else printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}