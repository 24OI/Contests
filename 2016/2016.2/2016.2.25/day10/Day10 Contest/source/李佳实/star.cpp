#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,cnt,maxn,ans;
double a[1010],b[1010],c[1010];
struct ma
{
	double x,y;
}f[1000010];
bool cmp(ma p,ma q)
{
	return p.x<q.x||fabs(p.x-q.x)<0.01&&p.y<q.y;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		for(int j=1;j<i;j++)
		if(a[i]*b[j]!=a[j]*b[i])
		{
			f[++cnt].y=(c[j]*a[i]-c[i]*a[j])/(b[i]*a[j]-b[j]*a[i]);
			f[cnt].x=-(c[i]+b[i]*f[cnt].y)/a[i];
		}
	}
	sort(f+1,f+cnt+1,cmp);
	//for(int i=1;i<=cnt;i++) cout<<f[i].x<<' '<<f[i].y<<endl;
	int la=1;
	double now;
	for(int i=2;i<=cnt;i++)
	if(fabs(f[i].x-f[i-1].x)>0.0001||fabs(f[i].y-f[i-1].y)>0.0001)
	{
		if(i-la>maxn) now=f[i].x,maxn=i-la,ans=1;
		else if(i-la==maxn) ans++;
		la=i;
	}
	if(cnt+1-la>maxn) maxn=cnt+1-la,ans=1;
	else if(cnt+1-la==maxn) ans++;
	for(int i=1;;i++)
	if(i*(i-1)/2==maxn)
	{
		cout<<i<<' '<<ans;
		return 0;
	}
}
