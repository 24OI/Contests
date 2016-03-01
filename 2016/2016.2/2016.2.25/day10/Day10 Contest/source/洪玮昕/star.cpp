#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=2000100;
const double eps=1e-9;
struct point
{
	double x,y;
}p[N];
int mycomp(const point&a,const point&b)
{
	return (a.x-b.x<-eps||(fabs(a.x-b.x)<eps&&a.y-b.y<-eps));
}
int n,m,x,y,z,ans,sum,l,r;
double A[N],B[N],C[N];

int pd(int a,int b)
{
	return (fabs(p[a].x-p[b].x)<eps&&fabs(p[a].y-p[b].y)<eps);
}
int main()
{
	int a,b,c,i,j;
	double s1,s2,x,y;
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf%lf",&A[i],&B[i],&C[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
		{
			s1=B[i]*C[j]-B[j]*C[i];
			s2=A[i]*B[j]-B[i]*A[j];
			if(fabs(s2)<eps) continue;
			x=s1/s2;
			if(fabs(B[i])<=0) y=-(A[j]*x+C[j])/B[j];
			else y=-(A[i]*x+C[i])/B[i];
			p[++z]=(point) {x,y};
		}
	sort(p+1,p+z+1,mycomp);
	l=r=1;
	while(r<z)
	{
		if(pd(l,r+1)) r++;
		else
		{
			if(ans<r-l+1)
			{
				ans=r-l+1;
				sum=0;
			}
			if(ans==r-l+1) sum++;
			r++;
			l=r;
		}
	}
	if(ans<r-l+1)
	{
		ans=r-l+1;
		sum=0;
	}
	if(ans==r-l+1) sum++;
	for(i=1;i<=10000;i++)
	{
		ans-=i;
		a=i;
		if(ans==0) break;
	}
	ans=a+1;
	printf("%d %d",ans,sum);
}
