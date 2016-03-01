#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
const double eps=1e-8;
const int N=1010,M=1001000;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point vect;
bool operator == (const Point &a,const Point &b)
	{return (fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);}
bool operator < (const Point &a,const Point &b)
	{return (a.x-b.x<-eps || (fabs(a.x-b.x)<eps && a.y-b.y<-eps));}
Point operator + (const Point &a,const vect &b){return Point(a.x+b.x,a.y+b.y);}
vect operator -(const Point &a,const Point &b){return vect(b.x-a.x,b.y-a.y);}
vect operator * (const vect &a,const double &b){return vect(a.x*b,a.y*b);}

double dot(const vect &a,const vect &b){return a.x*b.x+a.y*b.y;}
double cross(const vect &a,const vect &b){return a.x*b.y-a.y*b.x;}

struct line{
	Point p;vect v;
	line(){}
	line(Point p,vect v):p(p),v(v){}
};
Point getjiao(const line &l1,const line &l2)
{
	double t=cross(l2.v,l2.p-l1.p)/cross(l1.v,l2.v);
	return l1.p+l1.v*t;
}

line l[N];
Point p[M];
int a,b,c,siz,n;
int ans,sum,tot;
int main()
{	
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		double x=a,y=b,z=c;
		Point p;vect v;
		if (b==0) 
		{
			p=Point(-z/x,0);
			v=vect(0,1);
			l[i]=line(p,v);
		}
		else
		{
			p=Point(0,-z/y);
			v=vect(1,-x/y);
			l[i]=line(p,v);
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (fabs(cross(l[i].v,l[j].v))>eps)
				p[++siz]=getjiao(l[i],l[j]);
	sort(p+1,p+1+siz);
	ans=1;sum=1;tot=1;
	for (int i=2;i<=siz;i++)
	{
		if (p[i]==p[i-1]) tot++;else tot=1;
		if (tot==ans) sum++;
		if (tot>ans) {ans=tot;sum=1;}
	}	
	int an=sqrt(ans*2)+1;
	printf("%d %d\n",an,sum);
	return 0;
}
