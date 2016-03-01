#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
using namespace std;

const int N=1005;

struct point
{
	long long a,b,c;
}p;

bool operator < (point o1,point o2) 
{
	return (o1.b*o2.a<o2.b*o1.a)||((o1.b*o2.a==o2.b*o1.a)&&(o1.c*o2.a<o2.c*o1.a));
}

bool operator == (point o1,point o2)
{
	if ((o1.a==o2.a)&&(o1.b==o2.b)&&(o1.c==o2.c)) return 1;
	return 0;
}

struct node
{
	point p;
	bool operator < (const node &o) const
	{
		return p<o.p;
	}
	int cnt;
};

set <node> s;
set <node>::iterator it;
int n;
long long a[N],b[N],c[N];

long long gcd(long long o1,long long o2)
{
	if (o2==0) return o1; else return gcd(o2,o1%o2);
}

int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	//cout << gcd(8,16) << endl;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
		//if ((a[i]==0)||(b[i]==0)||(c[i]==0)) continue;
		long long tmp=gcd(abs(a[i]),gcd(abs(b[i]),abs(c[i])));
		if (tmp==0) continue;
		a[i]/=tmp; b[i]/=tmp; c[i]/=tmp;
	}
	for (int i=1; i<=n; i++)
	  for (int j=i+1; j<=n; j++)
	  {
	  	if ((a[i]==a[j])&&(b[i]==b[j])&&(c[i]==c[j])) continue;
	  	p.a=a[i]*b[j]-a[j]*b[i];
	  	p.b=b[j]*c[i]-b[i]*c[j];
	  	p.c=a[i]*c[j]-a[j]*c[i];
	  	if (p.a==0) continue; else
	  	{
	  		long long tmp=gcd(abs(p.a),gcd(abs(p.b),abs(p.c)));
	  		p.a/=tmp; p.b/=tmp; p.c/=tmp;
	  	}
	  	if (p.a<0) 
	  	{
	  		p.a=-p.a;
	  		p.b=-p.b;
	  		p.c=-p.c;
	  	}
	  	//cout << i << ' ' << j << ' ' << p.a << ' ' << p.b << ' ' << p.c << endl;
	  	it=s.lower_bound((node) {p,0});
	  	if (it==s.end()) s.insert( (node) {p,1} ); else
	  	if ((*it).p==p) 
	  	{
	  		int tmp=(*it).cnt;
	  		s.erase(it);
	  		s.insert( (node) {p,tmp+1} );
	  	}
	  	else s.insert( (node) {p,1} );
	  }
	it=s.begin();
	int maxx=(*it).cnt,num=0;
	while (it!=s.end())
	{
		if ((*it).cnt>maxx)
		{
			maxx=(*it).cnt;
			num=0;
		}
		if ((*it).cnt==maxx) num++;
		it++;
	}
	//cout << maxx << ' ' << num << endl;
	for (int i=2; i<=n; i++) if (maxx*2==i*(i-1)) printf("%d %d\n",i,num);
	return 0;
}
