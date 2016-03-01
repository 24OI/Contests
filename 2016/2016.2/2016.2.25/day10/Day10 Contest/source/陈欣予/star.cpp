#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
const int M = 1001;
struct node
{
	double x,y;
}s[M*M];
int n,w[M*M],lenw;
int len,a[M],b[M],c[M],h[M];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x)
		return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]*b[j]==a[j]*b[i])
				continue;
			if(a[i]==0&&b[j]==0)
			{
				s[++len].x=-(double)c[j]*1.000/a[j]*1.000;
				s[len].y=-(double)c[i]*1.000/b[i]*1.000;
				continue;
			}
			if(a[j]==0&&b[i]==0)
			{
				s[++len].x=-(double)c[i]*1.000/a[i]*1.000;
				s[len].y=-(double)c[j]*1.000/b[j]*1.000;
				continue;
			}
			s[++len].x=(double)(c[i]*a[j]-a[i]*c[j])*1.000/(b[j]*a[i]-b[i]*a[j])*1.000;
			s[len].y=-(double)(c[i]*b[j]-c[j]*b[i])*1.000/(b[j]*a[i]-b[i]*a[j])*1.000;
		}
	sort(s+1,s+1+len,cmp);
	node sss;
	sss.x=-10000000000;
	sss.y=-10000000000;
	for(int i=1;i<=len;i++)
	{
		if(sss.x!=s[i].x||sss.y!=s[i].y)
		{
			sss.x=s[i].x;
			sss.y=s[i].y;
			w[++lenw]=1;
		}
		else
			w[lenw]++;
	}
	sort(w+1,w+1+lenw);
	int ans=0;
	for(int i=lenw;i;i--)
		if(w[i]==w[lenw])
			ans++;
		else
			break;
	int hh=0;
	for(int i=1;i<=1000;i++)
		if(w[lenw]<i*(i+1)/2)
		{
			hh=i;
			break;
		}
	printf("%d %d",hh,ans);
	return 0;
}

