#include<cstdio>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<set>

using namespace std;

typedef long long LL;
typedef double DB;

#define re(i,a,b) for(i=(a);i<=(b);i++)
#define SF scanf
#define PF printf
#define mmst(a,v) memset(a,v,sizeof(a))
#define two(v) (1<<(v))

const int maxn=1100;

const DB eps=1e-6;
int sgn(DB x){if(abs(x)<eps)return 0;return x>0?1:-1;}

int n;
struct Ts
  {
  	DB a,b,c;
  	void input(){SF("%lf%lf%lf\n",&a,&b,&c);}
  }s[maxn];

namespace small
{
const int maxn=210;
int cnt;
struct Tpoint{DB x,y;}p[maxn*maxn];
int val[maxn*maxn],maxval;
void add(DB A1,DB B1,DB C1,DB A2,DB B2,DB C2)
  {
  	cnt++;
  	p[cnt].y=(A2*C1-A1*C2)/(A1*B2-A2*B1);
  	p[cnt].x=(C2*B1-C1*B2)/(A1*B2-A2*B1);
  }
void solve()
  {
  	int i,j;
  	re(i,1,n-1)re(j,i+1,n)
  	  {
  	  	DB A1=s[i].a,B1=s[i].b,C1=s[i].c;
  	  	DB A2=s[j].a,B2=s[j].b,C2=s[j].c;
  	  	if(sgn(A1*B2-A2*B1)!=0)add(A1,B1,C1,A2,B2,C2);
  	  }
  	maxval=1;
  	re(i,1,cnt)
  	  {
  	  	DB x=p[cnt].x,y=p[cnt].y;
  	    re(j,1,n)
  	      {
  	    	  DB A=s[j].a,B=s[j].b,C=s[j].c;
  	    	  if(sgn(A*x+B*y+C)==0)val[i]++;
  	    	}
  	    maxval=max(maxval,val[i]);
  	  }
  	int ans=0;
  	re(i,1,cnt)if(val[i]==maxval)ans++;
  	PF("%d %d\n",maxval,ans);
  }
}

namespace RP
{
int cnt;
struct Tpoint
  {
	  DB x,y;
	  Tpoint(DB _x=0.0,DB _y=0.0){x=_x;y=_y;}
	  friend bool operator <(const Tpoint a,const Tpoint b){return sgn(a.x-b.x)!=0?sgn(a.x-b.x)<0:sgn(a.y-b.y)<0;}
	}p[1010];
int val[1010],maxval;

set<Tpoint>M;

void add(DB A1,DB B1,DB C1,DB A2,DB B2,DB C2)
  {
  	DB y=(A2*C1-A1*C2)/(A1*B2-A2*B1);
  	DB x=(C2*B1-C1*B2)/(A1*B2-A2*B1);
  	Tpoint res=Tpoint(x,y);
  	if(M.find(res)==M.end())M.insert(res),p[++cnt]=res;
  }
void solve()
  {
  	int i,j;
  	int T=1000;
  	while(T--)
  	{
  		i=rand()%n+1,j=rand()%n+1;
  	  DB A1=s[i].a,B1=s[i].b,C1=s[i].c;
  	  DB A2=s[j].a,B2=s[j].b,C2=s[j].c;
  	  if(sgn(A1*B2-A2*B1)!=0)
			  add(A1,B1,C1,A2,B2,C2);
  	}
  	maxval=1;
  	re(i,1,cnt)
  	  {
  	  	DB x=p[cnt].x,y=p[cnt].y;
  	    re(j,1,n)
  	      {
  	    	  DB A=s[j].a,B=s[j].b,C=s[j].c;
  	    	  if(sgn(A*x+B*y+C)==0)val[i]++;
  	    	}
  	    maxval=max(maxval,val[i]);
  	  }
  	int ans=0;
  	re(i,1,cnt)if(val[i]==maxval)ans++;
  	PF("%d %d\n",maxval,ans);
  }
}

int main()
  {
  	freopen("star.in","r",stdin);
  	freopen("star.out","w",stdout);
  	int i;
  	SF("%d\n",&n);
  	re(i,1,n)s[i].input();
  	if(n<=200)small::solve();else RP::solve();
  	return 0;
  }
