#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=593119681;
inline long long lowbit(long long x)
{
	return (x&(-x));
}
inline bool ist(long long x)
{
	return lowbit(x)==x;
}
inline bool adj(long long x,long long y)
{
	return ist(x^y)||x==y;
}
struct matrix
{
	long long a[70][70];
	long long siz;
	inline void multi(const matrix&b)
	{
		long long c[70][70];
		memset(c,0,sizeof(c));
		for (long long i=1;i<=siz;i++)
		{
			for (long long j=1;j<=siz;j++)
			{
				for (long long k=1;k<=siz;k++)
				{
					c[i][j]+=a[i][k]*b.a[k][j]%mod;
					c[i][j]%=mod;
				}
			}
		}
		for (long long i=1;i<=siz;i++)
		{
			for (long long j=1;j<=siz;j++)
			{
				a[i][j]=c[i][j];
			}
		}
	}
}mat1,mat2;
long long n,m,a[300000];;
long long dp[1100][1100];
inline void fastexp(long long x)
{
	if(x==1)return;
	mat1.multi(mat1);
	if(x%2==1)mat1.multi(mat2);
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%I64d %I64d",&n,&m);
	for (long long i=0;i<(1<<n);i++)
	{
		scanf("%I64d",&a[i]);
		a[i]%=mod;
		dp[0][i]=a[i];
	}
	if(m<=2000)
	{
		for (long long i=1;i<=m;i++)
		{
			for (long long j=0;j<(1<<n);j++)
			{
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=mod;
				for (long long k=0;k<n;k++)
				{
					dp[i][(j^(1<<k))]+=dp[i-1][j];
					dp[i][(j^(1<<k))]%=mod;
				}
			}
		}
		for (long long j=0;j<(1<<n);j++)
		{
			printf("%I64d ",dp[m][j]);
		}printf("\n");
	}
	else
	{
		mat1.siz=mat2.siz=(1<<n);
		for (long long i=0;i<(1<<n);i++)
		{
			for (long long j=0;j<(1<<n);j++)
			{
				mat1.a[i+1][j+1]=mat2.a[i+1][j+1]=adj(i,j);
			}
		}
		fastexp(m);
		for (long long i=0;i<(1<<n);i++)
		{
			long long ans=0;
			for (long long j=0;j<(1<<n);j++)
			{
				ans+=mat1.a[i+1][j+1]*a[j];
			}printf("%I64d ",ans);
		}printf("\n");
	}
	return 0;	
}	
