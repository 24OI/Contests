#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mod 1000000001
using namespace std;
int i,j,k,m,n,s,t,l,r;
int f[100100],b[100100],ans;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	n=read();
	m=read();
	f[1]=1;
	for (i=2;i<=n;i++)
	  f[i]=(f[i-1]+f[i-2])%mod;
	for (i=1;i<=n;i++)
	  b[i]=read();
	if (m<=2000)
	{
	while (m--)
	{
		s=read();
		l=read();
		r=read();
		if (s==1)
		{
			for (i=l;i<=r;i++)
			  b[i]=(b[i]+f[i-l+1])%mod;
		} else
	    {
	    	ans=0;
	    	for (i=l;i<=r;i++)
	    	  ans=(ans+b[i])%mod;
	    	  	    printf("%d\n",ans);
	    }
	}
    }else
	{
		
    }
}
