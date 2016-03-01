#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll base=10000000000000061;

struct fenshu
{
	ll a,b;
	
	fenshu friend operator +(fenshu a,fenshu b)
	{
		fenshu ans;
		ans.b=a.b*b.b;
		ans.a=a.a*b.b+a.b*b.a;
		return ans;
	}
	
	fenshu friend operator -(fenshu a,fenshu b)
	{
		fenshu ans;
		ans.b=a.b*b.b;
		ans.a=a.a*b.b-a.b*b.a;
		return ans;
	}
	
	fenshu friend operator *(fenshu a,fenshu b)
	{
		fenshu ans;
		ans.b=a.b*b.b;
		ans.a=a.a*b.a;
		return ans;
	}
	
	fenshu friend operator /(fenshu a,fenshu b)
	{
		fenshu ans;
		ans.b=a.b*b.a;
		ans.a=a.a*b.b;
		return ans;
	}
	
	fenshu friend operator -(fenshu a)
	{
		a.a=-a.a;
		return a;
	}
	
	bool friend operator !(fenshu a)
	{
		return !a.a;
	}
	
	bool friend operator ==(fenshu a,fenshu b)
	{
		return a.a==b.a && a.b==b.b;
	}
	
	bool friend operator !=(fenshu a,fenshu b)
	{
		return a.a!=b.a || a.b!=b.b;
	}
	
	bool friend operator <(fenshu a,fenshu b)
	{
		if(a.a!=b.a)return a.a<b.a;
		return a.b<b.b;
	}
}a[2333],b[2333],c[2333];

ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

fenshu yuefen(fenshu a)
{
	if(a.a==0)
	{
		a.b=1;
		return a;
	}
	if(a.a<0)
	{
		a.a=-a.a;
		a.b=-a.b;
	}
	ll k=gcd(a.a,a.b);
	a.a/=k;
	a.b/=k;
	return a;
}

struct node
{
	fenshu x,y;
	
	bool friend operator !=(node a,node b)
	{
		return a.x!=b.x || a.y!=b.y;
	}
	
	bool friend operator <(node a,node b)
	{
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	}
}d[2333333];
map<node,int>ma;
ll e[2333333];

int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	int i,j,k,m,n,u,v,last,ans=0,ansn;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&k);
		a[i].b=b[i].b=c[i].b=1;
		a[i].a=u;
		b[i].a=v;
		c[i].a=k;
	}
	m=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(!a[i] && !b[j])
			{
				m++;
				d[m].x=yuefen(-c[j]/a[j]);
				d[m].y=yuefen(-c[i]/b[i]);
			}
			else if(!b[i] && !a[j])
			{
				m++;
				d[m].x=yuefen(-c[i]/a[i]);
				d[m].y=yuefen(-c[j]/b[j]);
			}
			else if(a[i]*b[j]==a[j]*b[i]);
			else if(!a[i])
			{
				m++;
				d[m].y=yuefen(-c[i]/b[i]);
				d[m].x=yuefen((-b[j]*d[m].y-c[j])/a[j]);
			}
			else if(!a[j])
			{
				m++;
				d[m].y=yuefen(-c[j]/b[j]);
				d[m].x=yuefen((-b[i]*d[m].y-c[i])/a[i]);
			}
			else if(!b[i])
			{
				m++;
				d[m].x=yuefen(-c[i]/a[i]);
				d[m].y=yuefen((-a[j]*d[m].x-c[j])/b[j]);
			}
			else if(!b[j])
			{
				m++;
				d[m].x=yuefen(-c[j]/a[j]);
				d[m].y=yuefen((-a[i]*d[m].x-c[i])/b[i]);
			}
			else
			{
				m++;
				d[m].x=yuefen((c[j]*b[i]-c[i]*b[j])/(a[i]*b[j]-a[j]*b[i]));
				d[m].y=yuefen((-c[i]-a[i]*d[m].x)/b[i]);
			}
			e[m]=d[m].x.a;
			e[m]=e[m]*base+d[m].x.b;
			e[m]=e[m]*base+d[m].y.a;
			e[m]=e[m]*base+d[m].y.b;
			/*ma[d[m]]++;
			k=ma[d[m]];
			if(k>ans)
			{
				ans=k;
				ansn=0;
			}
			if(k==ans)
			{
				ansn++;
			}*/
			//printf("m=%d i=%d j=%d d[m].x=%I64d/%I64d d[m].y=%I64d/%I64d\n",m,i,j,d[m].x.a,d[m].x.b,d[m].y.a,d[m].y.b);
		}
	}
	/*sort(d+1,d+m+1);
	last=ans=1;
	ansn=0;
	for(i=2;i<=m+1;i++)
	{
		if(i>m || d[i]!=d[i-1])
		{
			if(i-last>ans)
			{
				ans=i-last;
				ansn=0;
			}
			if(i-last==ans)ansn++;
			last=i;
		}
	}*/
	sort(e+1,e+m+1);
	last=ans=1;
	ansn=0;
	for(i=2;i<=m+1;i++)
	{
		if(i>m || e[i]!=e[i-1])
		{
			if(i-last>ans)
			{
				ans=i-last;
				ansn=0;
			}
			if(i-last==ans)ansn++;
			last=i;
		}
	}
	for(i=1;i*(i-1)/2<ans;i++);
	printf("%d %d\n",i,ansn);
	return 0;
}
