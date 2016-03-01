#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=3*1E5,MOD=593119681;
int A[maxn];
int f[maxn][20],B[maxn];
int n,T,N;
struct Mat{
	int x[70][70];
	Mat(){for(int i=1;i<=70;i++)for(int j=1;j<=70;j++)x[i][j]=0;}
};
Mat P(Mat A,Mat B)
{
	Mat C;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)C.x[i][j]+=A.x[i][k]*B.x[k][j];
	return C;
}
Mat Pow(Mat G,int T)
{
	Mat b,r;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)b.x[i][j]=G.x[i][j];
	for(int i=1;i<=N;i++)r.x[i][i]=1;
	while(T)
	{
		if(T&1)r=P(b,G);
		b=P(b,b);
		T>>=1;
	}
	return r;
}
void work()
{
	Mat G,ans;
	for(int i=0;i<N;i++){
		int t=1;
		for(int j=1;j<=n;j++,t<<=1)
			G.x[i][i^t]=A[i];
		G.x[i][i]=A[i];
	}
	ans=Pow(G,T);
	for(int i=1;i<=N;i++)printf("%d ",ans.x[i][i]);
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&T);
	N=1;
	for(int i=1;i<=n;i++)N*=2;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	if(T>2000){work();return 0;}
	for(int i=0;i<N;i++){
		int t=1;
		for(int j=1;j<=n;j++,t<<=1)
			f[i][j]=i^t;
	}
	for(int i=1;i<=T;i++)
	{
		for(int i=0;i<N;i++)B[i]=A[i];
		for(int i=0;i<N;i++)
			for(int j=1;j<=n;j++)(A[f[i][j]]+=B[i])%=MOD;
	}
	for(int i=0;i<N;i++)printf("%d ",(A[i]+MOD)%MOD);
}
