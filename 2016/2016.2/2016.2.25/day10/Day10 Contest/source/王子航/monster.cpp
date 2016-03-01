#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 593119681
#define ll long long
using namespace std;
int n,t,num[1100],cnt,head[1100];
bool boo[1100][1100];
struct Matrix
{
	int v[70][70];
}A,B;
struct edge
{
	int to,next;
}e[2000010];
inline void insert(int u,int v)
{
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
inline Matrix operator*(const Matrix &a,const Matrix &b)
{
	Matrix res;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		ll now=0;
		for(int k=0;k<n;k++)
		{
			now+=(ll)a.v[i][k]*b.v[k][j];
			now%=mod;
		}
		res.v[i][j]=now;
	}
	return res;
}
inline Matrix qpow(Matrix a,int b)
{
	Matrix res;
	memset(res.v,0,sizeof(res.v));
	for(int i=0;i<n;i++)res.v[i][i]=1;
	while(b)
	{
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	if(n<=6)
	{
		n=(1<<n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				int tmp=i^j,cnt=0;
				while(tmp)
				{
					if(tmp&1)cnt++;
					if(cnt>1)break;
					tmp/=2;
				}
				if(cnt==1)B.v[i][j]=B.v[j][i]=1;
			}
		}
		for(int i=0;i<n;i++)B.v[i][i]=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&A.v[i][0]);
			if(A.v[i][0]>=mod)A.v[i][0]%=mod;
		}
		B=qpow(B,t);
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)cout<<B.v[i][j]<<" ";
			cout<<endl;
		}*/
		A=B*A;
		for(int i=0;i<n-1;i++)printf("%d ",A.v[i][0]);
		printf("%d\n",A.v[n-1][0]);
	}
	else
	{
		n=(1<<n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				int tmp=i^j,cnt=0;
				while(tmp)
				{
					if(tmp&1)cnt++;
					if(cnt>1)break;
					tmp/=2;
				}
				if(cnt==1)insert(i,j),insert(j,i);
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>=mod)num[i]%=mod;
		}
		for(int tim=1;tim<=t;tim++)
		{
			static int tmpnum[1100];
			memset(tmpnum,0,sizeof(tmpnum));
			for(int u=0;u<n;u++)
			{
				for(int i=head[u];i;i=e[i].next)
				{
					int v=e[i].to;
					tmpnum[v]+=num[u];
					if(tmpnum[v]>=mod)tmpnum[v]-=mod;
				}
				tmpnum[u]+=num[u];
				if(tmpnum[u]>=mod)tmpnum[u]-=mod;
			}
			for(int u=0;u<n;u++)num[u]=tmpnum[u];
		}
		for(int u=0;u<n-1;u++)printf("%d ",num[u]);
		printf("%d\n",num[n-1]);
	}
	return 0;
}
