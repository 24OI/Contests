#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
struct node
{
	int a,b,c;
}a[maxn];
struct dian
{
	double x,y;
}p[1000005];
int res[1000005];
int cnt;
bool cmp(dian a,dian b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int ans1,ans2;
void add(node a,node b)
{
	long long a1=a.a,b1=a.b,c1=a.c;
	long long a2=b.a,b2=b.b,c2=b.c;
	if(a1*b2==a2*b1)return;
	double x=(double)(b1*c2-b2*c1)/(double)(a1*b2-a2*b1);
	double y=(double)(a2*c1-a1*c2)/(double)(a1*b2-a2*b1);
	p[++cnt].x=x;
	p[cnt].y=y;
}
double abss(double x)
{
	if(x<0)return -x;
	return x;
}
bool bijiao(dian a,dian b)
{
//	cout<<a.x<<" "<<a.y<<" "<<abss(a.x-b.x)<<endl;
//	cout<<b.x<<" "<<b.y<<" "<<abss(a.y-b.y)<<endl<<endl;;
	if(abss(a.x-b.x)>0.000000001)return false;
	if(abss(a.y-b.y)>0.000000001)return false;
	return true;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		res[i*(i-1)/2]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			add(a[i],a[j]);
		}
	}
	sort(p+1,p+cnt+1,cmp);
	int now=1;
	for(int i=2;i<=cnt;i++)
	{
	//	cout<<p[i].x<<" "<<p[i].y<<endl;
		if(bijiao(p[i],p[i-1]))now++;
		else
		{
		//	cout<<"Find";
			if(res[now]>ans1)
			{
				ans1=res[now];
				ans2=1;
			}
			else if(res[now]==ans1)
			{
				ans2++;
			}
		}
	}
	if(res[now]>ans1)
	{
		ans1=res[now];
		ans2=1;
	}
	else if(res[now]==ans1)
	{
		ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
