#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 593119681
using namespace std;
int n,t;
int N;
int a[1030],b[1030];
struct matrix 
{
	int h,l;
	int a[70][70];
}ans,p,c;
bool judge(int x)
{
	int cnt=0;
	while(x)
	{
		if(x%2==1)cnt++;
		if(cnt>1)return false;
		x/=2;
	}
	if(cnt==1)return true;
	return false;
}
matrix operator * (matrix a,matrix b)
{
	c.h=a.h;c.l=b.l;
	for(int i=0;i<c.h;i++)
	{
		for(int j=0;j<c.l;j++)
		{
			c.a[i][j]=0;
			for(int k=0;k<a.l;k++)
			{
				c.a[i][j]=(c.a[i][j]+(long long)a.a[i][k]*b.a[k][j]%MOD)%MOD;
			}
		}
	}
	return c;
}
void did()
{
	ans.h=N;ans.l=1;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&ans.a[i][0]);
	}
	p.h=N;p.l=N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(judge(i^j))
			{
				p.a[i][j]=1;
				//cout<<i<<" "<<j<<endl;
			}
			
		}
		p.a[i][i]=1;
	}
	
	while(t)
	{
		if(t&1)
		{
			//cout<<t<<endl;
			ans=p*ans;
		}
		p=p*p;
		t>>=1;
	}
	for(int i=0;i<N;i++)
	{
		printf("%d ",ans.a[i][0]);
	}
	return;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	N=1<<n;
	if(n<=6 && t>1000)
	{
		did();
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	while(t--)
	{
		memset(b,0,sizeof(b));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					b[i]=(b[i]+a[i-(1<<j)])%MOD;
				}
				else 
				{
					b[i]=(b[i]+a[i+(1<<j)])%MOD;
				}
			}
		}
		for(int i=0;i<N;i++)
		{
			a[i]=a[i]+b[i];
			a[i]%=MOD;
		}
	}
	for(int i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}
