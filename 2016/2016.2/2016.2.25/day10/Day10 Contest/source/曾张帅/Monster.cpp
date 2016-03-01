#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long M=593119681;
int i,j,k;
int n,t;
long long a[3000];
long long dj[3000];
int l[1024][1024];
int lc[1024];
int c[11];
int ll,lll;
int hs();
int p=2;
int s=1;
int main()
{
	freopen("Monster.in","r",stdin);
	freopen("Monster.out","w",stdiout);
	cin>>n>>t;
	for(i=1;i<=n;i++)s*=p;
	s-=1;
	for(i=0;i<=s;i++)cin>>a[i];
	for(i=0;i<=s-1;i++)
	{
		memset(c,0,sizeof(c));
		int x=i;ll=0;lll=0;
		while(x>0)
		{
			c[ll++]=x%2;
			x/=2;
		}
		for(j=0;j<=n-1;j++)
		{
			if(c[j]==0)
			{
				c[j]=1;
				int xx=hs();
				l[i][lc[i]++]=xx;
				l[xx][lc[xx]++]=i;
				c[j]=0;
			}
		}
	}
	/*for(i=0;i<=s;i++)
	{
		for(j=0;j<=lc[i]-1;j++)cout<<l[i][j]<<' ';
		cout<<endl;
	}*/
	for(i=1;i<=t;i++)
	{
		memset(dj,0,sizeof(dj));
		for(j=0;j<=s;j++)
		{
			for(k=0;k<=lc[j]-1;k++)
			{
				dj[l[j][k]]=(dj[l[j][k]]+a[j])%M;
			}
		}
		for(j=0;j<=s;j++)a[j]=(a[j]+dj[j])%M;
	}
	for(i=0;i<=s;i++)cout<<a[i]<<' ';
	return 0;
}
int hs()
{
	int ii=0,ss=0;
	for(ii=n;ii>=0;ii--)
	{
		ss=ss*2+c[ii];
	}
	return ss;
}
