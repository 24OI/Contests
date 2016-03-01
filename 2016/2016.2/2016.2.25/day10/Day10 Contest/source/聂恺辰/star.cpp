#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
#define mp(x,y,z) make_pair(make_pair(x,y),z)
using namespace std;
long double a[1001],b[1001],c[1001],w[1001],k[1001];
struct node {long double x,y;int w;}e[1000001];
long double ab(long double x) {return x>0?x:-x;}
bool cmp(node x,node y)
{
	if(ab(y.x-x.x)>1e-6) return x.x<y.x;
	return x.y<y.y;
}
int cnt;
map<pair<pair<int,int>,int>,int>p;
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int GCD(int x,int y,int z) {return gcd(x,gcd(y,z));}
bool near(int i,int j)
{
	if(ab(e[i].x-e[j].x)<1e-6&&ab(e[i].y-e[j].y)<1e-6) return true;
	return false;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	int t,x,y,z;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		t=GCD(x,y,z);
		x/=t;y/=t;z/=t;
		if(p[mp(x,y,z)])
		{
			w[p[mp(x,y,z)]]++;
			i--;n--;
		}
		else
		{
			p[mp(x,y,z)]=i;
			w[i]=1;
			a[i]=x;b[i]=y;c[i]=z;
			if(b[i]==0) k[i]=99999999;
		}
	}
	for(i=2;i<=n;i++)
	for(j=1;j<i;j++)
	{
		if(k[i]&&k[j]||a[i]*b[j]==a[j]*b[i]) continue;
		cnt++;
		if(k[i])
		{
			e[cnt].x=c[i]/a[i];
			e[cnt].y=(-c[j]-a[j]*e[cnt].x)/b[j];
		}
		else if(k[j])
		{
			e[cnt].x=c[j]/a[j];
			e[cnt].y=(-c[i]-a[i]*e[cnt].x)/b[i];
		}
		else
		{
			e[cnt].x=(c[j]-c[i])/(a[i]*b[j]-b[i]*a[j]);
			e[cnt].y=(-c[i]-a[i]*e[cnt].x)/b[i];
		}
		e[cnt].w=w[i]+w[j];
	}
/*	for(i=1;i<=cnt;i++)
	cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].w<<endl;*/
	sort(e+1,e+cnt+1,cmp);
	int ans=0,maxn=0,tot=0;
	int nowmax;
	for(i=1;i<=cnt;i++)
	{
		tot=1;nowmax=e[i].w;
		while(near(i+1,i)&&i!=cnt)
		{
			i++;tot++;
			nowmax+=e[i].w;
		}
		tot=sqrt(2*tot);
	//	cout<<nowmax<<' '<<tot<<' '<<e[i].x<<' '<<e[i].y<<endl;
		nowmax/=tot;
		if(nowmax==maxn) ans++;
		else if(nowmax>maxn)
		{
			maxn=nowmax;
			ans=1;
		}	
	}
	printf("%d %d",maxn,ans);
}
