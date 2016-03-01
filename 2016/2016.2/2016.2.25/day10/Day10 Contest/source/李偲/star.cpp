#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int a[1005],b[1005],c[1005];
int flag[1005][1005];
int num;
struct node
{
	double x,y;
}f[1000005];
double eps=1e-10;
bool operator == (const node &i,const node &j)
{
	if(fabs(i.x-j.x)<eps&&fabs(i.y-j.y)<eps)return true;
	else return false;
}
bool operator < (const node &i,const node &j)
{
	if(i.x==j.x)
	{
		if(i.y<j.y)return true;
	}
	else
		if(i.x<j.x)return true; 
	return false;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&!flag[i][j]&&!flag[j][i])
			{
				if(b[i]==0)
				{
					if(b[j]==0)
						continue;
					f[++num].x=double(-c[i]/a[i]);
					f[num].y=double((double)(a[j]*c[i]-c[j]*a[i])/(double)(b[j]*a[i]));
					//printf("%d %d %.1f %.1f\n",i,j,f[num].x,f[num].y);
					flag[i][j]=1;
					flag[j][i]=1;
					continue;
				}
				if(b[j]==0)
				{
					if(b[i]==0)
						continue;
					f[++num].x=double(-c[j]/a[j]);
					f[num].y=double((double)(a[i]*c[j]-c[i]*a[j])/(double)(b[i]*a[j]));
					//printf("%d %d %.1f %.1f\n",i,j,f[num].x,f[num].y);
					flag[i][j]=1;
					flag[j][i]=1;
					continue;
				}
				if(a[i]==0)
				{
					if(a[j]==0)
					continue;
					f[++num].y=double(-c[i]/b[i]);
					f[num].x=double((double)(b[j]*c[i]-c[j]*b[i])/(double)(b[i]*a[j]));
					//printf("%d %d %.1f %.1f\n",i,j,f[num].x,f[num].y);
					flag[i][j]=1;
					flag[j][i]=1;
					continue;
				}
				if(a[j]==0)
				{
					if(a[i]==0)
					continue;
					f[++num].y=double(-c[j]/b[j]);
					f[num].x=double((double)(b[i]*c[j]-c[i]*b[j])/(double)(b[j]*a[i]));
					//printf("%d %d %.1f %.1f\n",i,j,f[num].x,f[num].y);
					flag[i][j]=1;
					flag[j][i]=1;
					continue;
				}
				if(a[j]*b[i]==a[i]*b[j])
					continue;
				f[++num].x=double((double)(b[j]*c[i]-c[j]*b[i])/(double)(b[i]*a[j]-b[j]*a[i]));
				f[num].y=double((double)(a[i]*c[j]-c[i]*a[j])/(double)(b[i]*a[j]-b[j]*a[i]));
				//printf("%d %d %.1f %.1f\n",i,j,f[num].x,f[num].y);
				flag[i][j]=1;
					flag[j][i]=1;
			}
		}
	}
	sort(f+1,f+num+1);
	
	/*for(int i=1;i<=num;i++)
	{
		printf("%.11f %.11f\n",f[i].x,f[i].y);
	}*/
	int ans=0;
	int ans2=0;
	for(int i=1;i<=num;i++)
	{
		//printf("%d %.1f %.1f\n",i,f[i].x,f[i].y);
		double tx=f[i].x;
		double ty=f[i].y;
		int num=0;
		int j=i;
		while(f[j]==f[i])
		{
			j++;
		}
		i=j-1;
		for(int k=1;k<=n;k++)
		{
			if(fabs(a[k]*tx+b[k]*ty+c[k])>-eps&&fabs(a[k]*tx+b[k]*ty+c[k])<eps)
				num++;
		}
		//printf("%d %.1f %.1f\n",num,tx,ty);
		if(ans2==0)
		{
			ans=num,ans2++;
			continue;
		}
		if(num==ans)
		{
			ans2++;
			continue;
		}
		if(num>ans)
			ans=num,ans2=1;
	}
	printf("%d %d\n",ans,ans2);
	return 0;
}
