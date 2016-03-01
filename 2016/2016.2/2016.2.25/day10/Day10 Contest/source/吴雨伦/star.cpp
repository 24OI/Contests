#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;


struct aline
{
	double a;
	double b;
	double c;
};

struct dick
{
	double xx;
	double yy;
};

aline l[100000];
dick d[10000000];
int n;

bool isone(dick A,dick B)
{
	if(fabs(A.xx-B.xx)<=0.0001 && fabs(A.yy-B.yy)<=0.0001) return true;
	else return false;
}

void solves(aline l1,aline l2,int p)
{
	double x=0,y=0;

	if((l2.a*l1.b-l1.a*l2.b)!=0)	x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if((l1.a*l2.b-l2.a*l1.b)!=0)	y=(l2.a*l1.c-l1.a*l2.c)/(l1.a*l2.b-l2.a*l1.b);

	d[p].xx=x,d[p].yy=y;
}

void inp()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lf%lf%lf",&l[i].a,&l[i].b,&l[i].c);
}

int cmp(const dick a,const dick b)
{
	if(a.xx>b.xx) return 0;
	if(a.yy<b.yy) return 0;
	return 1;
}

int cmm(const int a,const int b)
{
	return a>b?1:0;
}

void ge(int n)
{
	int o[100000],i=0,k=0;

	for(k=0;i<n && k<n;k++)		//o
	{
		o[k]=1;
		while(isone(d[i],d[i+1])==1 && i<n) o[k]++,i++;
		i++;
		//printf("%d\n",o[k]);
		k++;
	}

	sort(o,o+k,cmm);
	
	for(i=0;o[0]==o[i];i++);

	printf("%d %d\n",o[0],i);

}

void fun()
{
	int i,j,flag=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(j!=i)
			{
			//printf("solves(l[%d],l[%d],%d);\n",i,j,flag);
			solves(l[i],l[j],flag);
			flag++;
			}
			}

	sort(d,d+flag,cmp);

	ge(flag);

	//for(i=0;i<flag;i++) printf("%lf %lf\n",d[i].xx,d[i].yy);
}



main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	inp();
	fun();
	
	return 0;
}