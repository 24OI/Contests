#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct unit
{double A,B,C;
};
struct unit a[1010];

struct point
{double x,y;
};
struct point b[1010],c[1000010],p;

struct hash
{int flag;
 point p;
};
struct hash h[1000010];

int n,m,ans,tot,ans2,modh=999983;
int used[1010];
double eps=1e-9;

bool cmp(struct point A,struct point B)
{if(fabs(A.x-B.x)<eps)
	return A.y<B.y;
 else
 	return A.x<B.x;
}

int add(point p1)
{int j;
 j=(long long)(p1.x+p1.y)%modh;
 while(h[j].flag && (fabs(h[j].p.x-p1.x)>eps || fabs(h[j].p.y-p1.y)>eps)) j=(j+1)%modh;
 if(h[j].flag==1)
 	return 0;
 else
 {	h[j].flag=1;
 	h[j].p=p1;
 	return 1;
 }
}

int calc(int i,int j)
{double x1;
 
 if(a[i].A*a[j].B==a[i].B*a[j].A) return 0;
 if(a[i].B==0)
 {	x1=-a[i].C/a[i].A;
	p.x=x1;
	p.y=-a[j].A/a[j].B*x1+a[j].C/a[j].B;
 }
 else if(a[j].B==0)
 {	x1=-a[j].C/a[j].A;
	p.x=x1;
	p.y=-a[i].A/a[i].B*x1+a[i].C/a[i].B;
 }
 else
 {	p.x=(a[i].C/a[i].B-a[j].C/a[j].B)/(a[j].A/a[j].B-a[i].A/a[i].B);
 	p.y=-a[i].A/a[i].B*p.x-a[i].C/a[i].B;
 }
 return 1;
}
 	 
int main()
{freopen("star.in","r",stdin);
 freopen("star.out","w",stdout);

 int i,j,k,x;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 	scanf("%lf%lf%lf",&a[i].A,&a[i].B,&a[i].C);
 for(i=1;i<=n;i++)
 {	//cout<<i<<endl;
 	m=0;
 	for(j=1;j<=n;j++)
	 	if(j!=i && calc(i,j))
		{	m++;
			b[m]=p;
		}
 	sort(b+1,b+m+1,cmp);
 	memset(used,0,sizeof(used));
	x=0;
	k=1;
	used[k]=1;
	for(j=2;j<=m;j++)
 		if(fabs(b[j].x-b[k].x)<eps && fabs(b[j].y-b[k].y)<eps)
 			used[k]++;
		else
		{	x=max(x,used[k]);
			used[j]++;
			k=j;
		}
	x=max(x,used[k]);
	if(x>=ans)
	{	if(x>ans) 
		{	ans=x;
			tot=0;
		}
		for(j=1;j<=m;j++)
			if(used[j]==x)
			{	tot++;
				c[tot]=b[j];
			}
	}
 }
 if(tot<=1000000)
 {	sort(c+1,c+tot+1,cmp);
 	ans2=tot;
 	for(i=2;i<=tot;i++)
 		if(fabs(c[i].x-c[i-1].x)<eps && fabs(c[i].y-c[i-1].y)<eps)
 			ans2--;
 }
 else
 {	ans2=0;
 	for(i=1;i<=tot;i++)
 	{	//cout<<i<<endl;
	 	if(add(c[i]))
 			ans2++;
 	}
 }
 printf("%d %d\n",ans+1,ans2);
 return 0;
}
 	
