#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 22
using namespace std;
typedef enum{in,out} status;
struct abcd{
	int tim,belong;
	status sta;
	friend bool operator < (const abcd &x,const abcd &y)
	{
		return x.tim < y.tim ;
	}
}a[M<<1];
int n,m,k,ans;
int Count(int x)
{
	int re=0;
	for(;x;x^=x&-x)
		++re;
	return re;
}
int Calculate(int sta)
{
	int i,re=a[1].tim+m-a[n+n].tim;
	for(i=1;i<2*n;i++)
	{
		int temp=a[i+1].tim-a[i].tim;
		if(a[i].sta==out && a[i+1].sta==out)
		{
			if(sta&(1<<a[i].belong-1))
				re+=temp;
		}
		else if(a[i].sta==out && a[i+1].sta==in)
		{
			if(sta&(1<<a[i].belong-1) && sta&(1<<a[i+1].belong-1))
				re+=temp;
		}
		else if(a[i].sta==in && a[i+1].sta==out)
		{
			re+=temp;
		}
		else
		{
			if(sta&(1<<a[i+1].belong-1))
				re+=temp;
		}
	}
	return re;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i+i-1].tim=x;
		a[i+i-1].belong=i;
		a[i+i-1].sta=out;
		a[i<<1 ].tim=y;
		a[i<<1 ].belong=i;
		a[i<<1 ].sta=in;
	}
	sort(a+1,a+n+n+1);
	for(i=0;i<1<<n;i++)
		if(Count(i)==k)
			ans=max(ans,Calculate(i));
	cout<<ans<<endl;
	return 0;
}
