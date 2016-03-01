#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define eps 1e-7
using namespace std;
int n,tot,num=-0x7fffffff,mp[1000010];
struct point
{
	double x,y;
}ans[1000010];
struct Line
{
	double A,B,C;
}l[1010];
inline bool operator<(point a,point b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
inline Line operator-(Line l1,Line l2)
{
	return (Line){l1.A-l2.A,l1.B-l2.B,l1.C-l2.C};
}
inline bool notzero(double x)
{
	return (x>eps)||(x<-eps);
}
inline bool judge(Line l1,Line l2)
{
	return notzero(l1.A*l2.B-l2.A*l1.B);
}
inline point intersect(Line l1,Line l2)
{
	point p;
	if(l1.A!=0&&l2.A!=0)
	{
		Line ltmp=l1-l2;
		p.y=-ltmp.C/ltmp.B;
		p.x=-(l1.C+l1.B*p.y);
	}
	else if(l1.A==0)
	{
		p.y=-l1.C/l1.B;
		p.x=-(l2.C+l2.B*p.y);
	}
	else if(l2.A==0)
	{
		p.y=-l2.C/l2.B;
		p.x=-(l1.C+l1.B*p.y);
	}
	return p;
}
inline void pre()
{
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=i;
		mp[tmp]=i+1;
	}
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	pre();
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&l[i].A,&l[i].B,&l[i].C);
		if(l[i].A!=0)l[i].B/=l[i].A,l[i].C/=l[i].A,l[i].A=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		if(!judge(l[i],l[j]))continue;
		ans[++tot]=intersect(l[i],l[j]);
	}
	sort(ans+1,ans+tot+1);
	ans[tot+1]=(point){-2000000000,-2000000000};
	int now=0,tmp=tot;tot=0;
	for(int i=1;i<=tmp;i++)
	{
		if(notzero(ans[i].x-ans[i+1].x)||notzero(ans[i].y-ans[i+1].y))
		{
			now++;
			now=mp[now];
			if(now<num)continue;
			if(now==num)tot++;
			else tot=1,num=now;
			now=0;
		}
		else now++;
	}
	printf("%d %d\n",num,tot);
	return 0;
}
	
