#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mod 593119681
#define ll long long
using namespace std;
int i,j,k,m,n,s,t,n1;
int b[300000],a[300000],p[50],a1[300000];
ll c[100][100],d[100][100],e[100][100];
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
void xc1()
{
	int i,j,k;
	for (i=0;i<=n1;i++)
	  for (j=0;j<=n1;j++)
	    {
	    	e[i][j]=0;
	    	for (k=0;k<=n1;k++)
	    	  e[i][j]=(e[i][j]+c[i][k]*c[k][j])%mod;
	    }
	for (i=0;i<=n1;i++)
	  for (j=0;j<=n1;j++)
	  c[i][j]=e[i][j];
}
void xc2()
{
		int i,j,k;
	for (i=0;i<=n1;i++)
	  for (j=0;j<=n1;j++)
	    {
	    	e[i][j]=0;
	    	for (k=0;k<=n1;k++)
	    	  e[i][j]=(e[i][j]+d[i][k]*c[k][j])%mod;
	    }
	for (i=0;i<=n1;i++)
	  for (j=0;j<=n1;j++)
	  d[i][j]=e[i][j];
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	n=read();
	m=read();
	n1=(1<<n)-1;
	for (i=0;i<=n1;i++)
	  b[i]=read();                    //!!!!!!!!!!!!!!!!!!
	for (i=1;i<=n;i++)
	  p[i]=1<<i>>1;
/*	for  (m=1;m<=10;m++)
	  {
	  	cout<<endl;
	  	for (i=0;i<=n1;i++)
	  	b[i]=bb[i];*/
	if (m<=1000)
	{
	for (int T=1;T<=m;T++)
	{
		for (i=0;i<=n1;i++)
		  a[i]=0;
		for (i=0;i<=n1;i++)
		  for (j=1;j<=n;j++)
		  {
		  	if (i&p[j]) k=i-p[j]; else k=i+p[j]; 
		  	a[i]=(a[i]+b[k])%mod;
		  }
		for (i=0;i<=n1;i++)
		  b[i]=(b[i]+a[i])%mod;
	  }
	  for (i=0;i<=n1;i++)
	    printf("%d ",b[i]);
    }else if (n<=6)
    {
    	for (i=0;i<=n1;i++)
    	  c[i][i]=1;
    	for (i=0;i<=n1;i++)
    	  for (j=1;j<=n;j++)
    	  {
    	  if (i&p[j]) k=i-p[j]; else k=i+p[j];
    	     c[i][k]=1;
           }
        for (i=0;i<=n1;i++)
          d[i][i]=1;
        while (m)
        {
        	if (m&1) xc2();
        	xc1();
        	m>>=1;
        }
        for (i=0;i<=n1;i++)
          for (j=0;j<=n1;j++)
          a1[i]=(a1[i]+b[j]*d[i][j])%mod;
        for (i=0;i<=n1;i++)
          printf("%d ",a1[i]);
    } else
    {
    	
    }
   //   }
}
