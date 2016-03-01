#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
const int M=1200,N=130,mod=593119681;
struct Matrix{
	int a[N][N];
	void wr(int n)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				printf("%9d",a[i][j]);
			printf("\n");	
		}
	}
}A;
struct Ans{
	int f[N];
}F;

int n,t,c[M],a[M][M],ans;

Matrix operator * (const Matrix &A,const Matrix &B)
{
	Matrix C;
	memset(C.a,0,sizeof(C.a));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
			{
				ll o=A.a[i][k];
				o=o*A.a[k][j]%mod;
				C.a[i][j]=(C.a[i][j]+o)%mod;
			}
	return C;
}

Ans operator * (const Ans &A,const Matrix &B)
{
	Ans C;
	memset(C.f,0,sizeof(C.f));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			ll o=A.f[j];
			o=o*B.a[j][i]%mod;
			C.f[i]=(C.f[i]+o)%mod;
		}
	return C;
}

void init();
void jc();
void baoli();
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	n=1<<n;
	if (n<=7) jc();
	else baoli();

	return 0;
}
void init()
{
	for (int i=0;i<n;i++)
		scanf("%d",&F.f[i]);
	for (int i=0;i<n;i++)
	{
		A.a[i][i]=1;
		for (int j=0;j<n;j++)	
		{
			int u=i^j,tot=0;
			while (u){if (u&1) tot++;u>>=1;}
			if (tot==1) A.a[i][j]=1;
		}	
	}
}
void jc()
{
	init();
	int u=t;
	while (u)
	{
		if (u&1) F=F*A;
		A=A*A;
		u>>=1;
	}
	for (int i=0;i<n;i++)
		printf("%d ",F.f[i]);
	printf("\n");
}
void baoli()
{
	static int f[M][M],len[M],d[M][M];
	memset(f,0,sizeof(f));
	memset(len,0,sizeof(len));
	for (int i=0;i<n;i++) scanf("%d",&f[0][i]);
	
	for (int i=0;i<n;i++)
	{
		a[i][i]=1;
		for (int j=0;j<n;j++)	
		{
			int u=i^j,tot=0;
			while (u){if (u&1) tot++;u>>=1;}
			if (tot==1) a[i][j]=1;
		}	
	}
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]) d[i][++len[i]]=j;
	
	for (int i=1;i<=t;i++)
		for (int j=0;j<n;j++)
			for (int k=1;k<=len[j];k++)
				f[i][j]=(f[i][j]+f[i-1][d[j][k]])%mod;
	
	for (int i=0;i<n;i++)
		printf("%d ",f[t][i]);
	printf("\n");
}
