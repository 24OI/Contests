#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-9
using namespace std;
int i,j,k,m,n,s,t,bo,ans,tmp;
double s1,s2,s3,l1[1010][5];
struct p{
	double x,y;
};
struct line{
	p a,b;
}ll[1010];
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();};
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double operator *(p a,p b)
{
	return a.x*b.y-b.x*a.y;
}
p operator -(p a,p b)
{
	return (p){a.x-b.x,a.y-b.y};
}
p operator +(p a,p b)
{
	return (p){a.x+b.x,a.y+b.y};
}
p operator *(p a,int b)
{
	return (p){a.x*b,a.y*b};
}
p getjiao(line a,line b)
{
	double t=(b.b*(a.a-b.a))/(a.b*b.b);
	return a.a+a.b*t;
}
bool pd(p q,int c)
{
	//if (fabs(a.a*b.a)<eps||fabs(a.a*ll[c].a)<eps||fabs(b.a*ll[c].a)<eps) return 0;
	 // p q=getjiao(a,b);
	  if (fabs(q.y-(-q.x*l1[c][1]-l1[c][3])/l1[c][2])<eps) return 1; else return 0;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	n=read();
	for (i=1;i<=n;i++)
	 {
	 	l1[i][1]=read();
	 	l1[i][2]=read();
	 	l1[i][3]=read();
	 	if (!l1[i][2])
	 	{
	 		ll[i].a=(p){-l1[i][3]/l1[i][1],1};
	 		p xx=(p){-l1[i][3]/l1[i][1],2};
	 		ll[i].b=xx-ll[i].a;
	 	} else
	 	{
	    p xx=(p){1,(-l1[i][1]-l1[i][3])/l1[i][2]};
	    ll[i].a=xx;
	    xx=(p){2,(-2*l1[i][1]-l1[i][3])/l1[i][2]};
	    ll[i].b=xx-ll[i].a;
	    }
	 }
	 if (n>300)
	 {
	 	for (i=1;i<=n;i++)
	 	  for (j=1;j<=n;j++)
	 	    if (fabs(ll[i].b*ll[j].b)<eps)
	 	      s++;
	 	printf("2 %d\n",s);
	 	return 0;
	 }
	 for (i=1;i<=n;i++)
	   for (j=i+1;j<=n;j++)
	     if (fabs(ll[i].b*ll[j].b)>eps)
	     {
	     //	bo=0;
	     	p pp=getjiao(ll[i],ll[j]);
	     	s=2;
	     	for (k=j+1;k<=n;k++)
	     	 // if (k!=i&&k!=j)
	     	  if (pd(pp,k))
	     	  {
	     	  	s++;
	     	  /*	if (k<=i&&k<=j)
	     	  	  if (s>2) {bo=1;break;} */
	     	  }
	     	 // if (!bo)
	        if (s>ans)
	           {
	           	ans=s;
	           	tmp=1;
	           }else if (s==ans) tmp++;
	     }
	printf("%d %d\n",ans,tmp);
}
