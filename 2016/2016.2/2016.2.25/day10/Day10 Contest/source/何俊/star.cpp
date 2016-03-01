#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define N 1010
#define INF 0x7fffffff

int n,tot,Spe_num,Maxans,Ansnum,S_tot,num[N];
double A[N][3],B[N][3],willdo[N*N];
double q[N];
map<double,bool> flag;
	
double Cal(double x,int k)
{
	return A[k][0]*x+A[k][2];
}

int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&A[i][0],&A[i][1],&A[i][2]);
		A[i][0]*=(-1.0);A[i][2]*=(-1.0);
		if(A[i][1]==0)
		{
			A[i][1]=INF;A[i][0]=(A[i][2]*(-1))/A[i][0];
		}
		else 
		{
			A[i][0]=A[i][0]/A[i][1];A[i][2]=A[i][2]/A[i][1];
			A[i][1]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(A[i][1]==INF)
			{
				if(A[j][1]==INF)
					continue;
				else 
				{
					if(flag[A[i][0]])
						continue;
					else 
					{
						flag[A[i][0]]=true;
						willdo[++tot]=A[i][0];
					}
				}
			}
			else 
			{
				if(A[j][1]==INF)
				{
					if(flag[A[j][0]])
						continue;
					else 
					{
						flag[A[j][0]]=true;
						willdo[++tot]=A[j][0];
					}
				}
				else 
				{
					if(A[i][0]==A[j][0])
						continue;
					double now=(A[i][2]-A[j][2])*(-1.0)/(A[i][0]-A[j][0]);
					if(flag[now])
						continue;
					else 
					{
						flag[now]=true;
						willdo[++tot]=now;
					}
				}
			}
		}
	}
	for(int i=1;i<=tot;i++)
	{
		Spe_num=0;S_tot=0;
		double x=willdo[i];
		for(int j=1;j<=n;j++)
		{
			if(A[j][1]==INF)
			{
				if(A[j][0]==x)
				Spe_num++;
				continue;
			}
			double y=Cal(x,j);
			bool Find=false;
			for(int t=1;t<=S_tot;t++)
			{
				if(y==q[t])
				{
					Find=true;
					num[t]++;break;
				}
			}
			if(!Find)
			{
				q[++S_tot]=y;num[S_tot]=1;
			}
		}
		for(int j=1;j<=S_tot;j++)
		{
			if(num[j]+Spe_num>Maxans)
			{
				Maxans=num[j]+Spe_num;
				Ansnum=1;
			}
			else if(num[j]+Spe_num==Maxans)
				Ansnum++;
			q[j]=0;num[j]=0;
		}
	}
	cout<<Maxans<<" "<<Ansnum<<endl;
	return 0;
}
						
