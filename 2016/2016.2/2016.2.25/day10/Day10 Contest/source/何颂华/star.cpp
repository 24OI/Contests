#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1050
#define M 1000050
#define eps 1e-15
#define ld long double
struct Point
 {ld x,y;} b[M];
struct Line
 {Point x,y;int a,b,c;} a[N];
Point operator+ (const Point &x,const Point &y)
 {return (Point){x.x+y.x,x.y+y.y};}
Point operator- (const Point &x,const Point &y)
 {return (Point){x.x-y.x,x.y-y.y};}
ld operator* (const Point &x,const Point &y)
 {return x.x*y.y-x.y*y.x;}
Point operator* (const Point &x,const ld &y)
 {return (Point){x.x*y,x.y*y};}
bool operator< (const Point &x,const Point &y)
 {return x.x<y.x||(fabs(x.x-y.x)<eps&&x.y<y.y);}
bool operator== (const Point &x,const Point &y)
 {return fabs(x.x-y.x)<eps&&fabs(x.y-y.y)<eps;}
int n,m,ans,Ans,st;
inline int Read()
 {
	 int x=0;char y;bool z=false;
	 do y=getchar(),z|=y=='-'; while (y<'0'||y>'9');
	 do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
	 return z?-x:x;
 }
inline void Get_Line(int x)
 {
	 a[x].a=Read();a[x].b=Read();a[x].c=Read();
	 ld A=a[x].a,B=a[x].b,C=a[x].c;
	 if (!a[x].a) a[x].x=(Point){0,-C/B},a[x].y=a[x].x,a[x].y.x+=1; else
	  if (!a[x].b) a[x].x=(Point){-C/A,0},a[x].y=a[x].x,a[x].y.y+=1; else
	    a[x].x=(Point){0,-C/B},a[x].y=(Point){-C/A,0};
	 return;
 }
inline void Intersect(Line x,Line y)
 {
	 if (1LL*x.a*y.b==1LL*x.b*y.a) return;
	 ld k=(y.y-x.x)*(y.x-x.x),l=(y.x-x.y)*(y.y-x.y);
	 b[++st]=x.x+(x.y-x.x)*(k/(k+l));
 }
int main()
 {
	 freopen("star.in","r",stdin);freopen("star.out","w",stdout);
	 n=Read();
	 for (int i=1;i<=n;i++) Get_Line(i);
	 for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++) Intersect(a[i],a[j]);
	 sort(b+1,b+st+1);
	 for (int i=1;i<=st;i++)
	  {
		  int ri=i;
		  while (ri<=st&&b[ri+1]==b[i]) ri++;
		  if (ri-i+1>ans) ans=ri-i+1,Ans=1; else
		   if (ri-i+1==ans) ans=ri-i+1,Ans++;
		  i=ri;
	  }
	 cout <<ans<<' '<<Ans<<endl;
	 return 0;
 }