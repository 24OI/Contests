#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 1010
int n,ll,l;
int a[MAXN],b[MAXN],c[MAXN];
struct node{
	double x,y;
}d[MAXN*MAXN];
int s[MAXN];
int cal(int x)
{
	if (x==0) return 0;
	int y=floor(sqrt(2*x));
	return y+1;
}
int cmp(node a,node b)
{
	if (a.x<b.x || a.x==b.x && a.y<b.y) return 1;
	return 0;
}
int cmp1(int a,int b)
{
	return a>b;
}
int main()
{
freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
	    scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i=1;i<n;i++)
	   for (int j=i+1;j<=n;j++)
	      if (a[i]*b[j]!=a[j]*b[i])
	      {
	      	l++;
	      	if (b[i]==0)
	      	{
	      		d[l].x=(double)(-c[i]) / (double)a[i];
	            d[l].y=(double)(-c[j] - a[j]*d[l].x) / (double)b[j];
	      	}
	      	else
	      	 if (b[j]==0)
	      	 {
	      	 	d[l].x=(double)(-c[j]) / (double)a[j];
	      	 	d[l].y=(double)(-c[i] - a[i] * d[l].x) / (double)b[i];
	      	 }
	      	 else
	      	  {
	      	  	d[l].x=(double)(b[i]*c[j]-b[j]*c[i]) / (double) (b[j]*a[i]-b[i]*a[j]);
	      	  	d[l].y=(double)(a[i]*d[l].x+c[i])/(double)(-b[i]);
	      	  }
	      }
	sort(d+1,d+1+l,cmp);
	ll=0;
	for (int i=1;i<=l;i++)
	   if (d[i].x==d[i+1].x && d[i].y==d[i+1].y)
	     {
	     	s[ll]++;
	     }
	     else
	      {
	      	ll++;
	      	s[ll]=1;
	      }
   sort(s+1,s+ll+1,cmp1);
   printf("%d ",cal(s[1]));
   if (s[1]>0)
   {
     l=1;
   while (s[l]==s[l+1]) l++;
   printf("%d",l);
}
else
 cout<<0;
}
