#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,t;
int size;
int k[300000];
int p[300000];
int m[2000][2000];
int dis[300000];
int mod=593119681;
int add=1;
int times=0;
int AskDis(int x)
{
	int num=0;
	while (x>1)
	{
		if (x%2==1) num++;
		x>>=1;
	}
	if (x==1) num++;
	return num;
}
int init()
{
	cin>>n>>t;
	size=pow(2,n);
	 for (int i=0;i<=pow(2,n)-1;i++)
	 	{
	 	cin>>k[i];
        if (k[i]!=0)
        {
        	p[0]++;
        	p[p[0]]=i;
        }
	    }
	 for (int i=1;i<=pow(2,n+1);i++)
     dis[i]=AskDis(i);
     for (int i=0;i<=size-1;i++)
     	for (int j=0;j<=size-1;j++)
     		if (dis[i^j]==1)
     		{
              m[i][0]++;
              m[i][m[i][0]]=j;
     		}
} 
int main()
{
    freopen("monster.in","r",stdin);
    freopen("monster.out","w",stdout);
	init();
     while (add!=0)
     {
     	add=0;
     	times++;
     	int len=p[0];
     	for (int i=1;i<=len;i++)
     	{
           for (int j=1;j<=m[p[i]][0];j++)
           {
             if (k[m[p[i]][j]]==0)
             {
                p[0]++;
                add++;
                p[p[0]]=m[p[i]][j];
             }
             k[m[p[i]][j]]++;
             if (k[m[p[i]][j]]>=mod)
                k[m[p[i]][j]]=k[m[p[i]][j]]%mod;
           }   
     	}
     }
     t=t-times;
     for (int i=1;i<=p[0];i++)
     {
     	for (int j=1;j<=m[p[i]][0];j++)
     		k[m[p[i]][j]]+=t;
     }
     for (int i=0;i<=size-1;i++)
     	cout<<k[i]%mod<<" ";
        cout<<endl;
}
