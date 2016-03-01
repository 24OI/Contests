#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define P 593119681
#define LL long long
#define MAXN 262200
int l,n,t,s,m,p,T;
bool flag;
long long x;
int head[MAXN];
long long a[MAXN],last[MAXN];
struct node{
	int y,next;
}edge[MAXN*3];
void add(int x,int y)
{
	l++;
	edge[l].y=y;
	edge[l].next=head[x];
	head[x]=l;
}
long long ksm(int a,int b)
{
	long long y=a;
	long long ans=1;
	while (b)
	{
		if (b & 1==1) ans=(ans*y) % P;
		y=(y * y) % P;
		b=b >> 1;
	}
	return ans;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d", &n ,&t);
    m=1<<n;
    for (int i=0;i<m;i++)
    {
    	scanf("%d", &a[i]);
    	last[i]=a[i];
    }
    for (int i=0;i<m-1;i++)
       for (int j=i+1;j<m;j++)
          {
            x=i ^ j;
          	s=0;
          	while (x>0)
          	{
          		s+=x & 1;
          		x>>=1;
          	}
            if (s==1)
            {
            	add(i,j);add(j,i);
           }
         }
    T=t;
    for (int i=1;i<=t;i++)
    {
    	x=a[0];
    	flag=1;
    	for (int j=1;j<m;j++)
    	    if (x!=a[j]) {flag=0;break;}
    	if (flag)
    	{
    		T=i;
    	    break;	
    	}
    	for (int x=0;x<m;x++)
    	{
    		p=head[x];
    		while (p)
    		{
    		    a[edge[p].y]=(a[edge[p].y]+last[x]) % P;
				p=edge[p].next;	
    		}
    	}
    	for (int x=0;x<m;x++)
    	    last[x]=a[x];
    }
    if (T<t)
    {
    	x=ksm(n+1,t-T+1);
    	x=((LL)x * a[0]) % P;
		for (int i=0;i<m;i++)
		     printf("%lld ", x); 
    }
    else
    {
    	for (int i=0;i<m;i++)
            printf("%lld ", a[i]); 
    }
}
