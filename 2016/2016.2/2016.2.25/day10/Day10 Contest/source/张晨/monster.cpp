#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-8
#define md 593119681
#define N 1050
using namespace std;

ll ok[N],b[N],sum[N];
int s,n;
struct JU
{
	ll a[N][N];
	ll *operator [] (int x) { return a[x];}
	void outit()
	{
		for (int i=0;i<s;i++)
		{
			for (int j=0;j<s;j++)
			  printf("%lld ",a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}a,kuai,mid,ans;inline void solve(ll &a,ll b)
{
	a=b; if (a>=md) a-=md;
}

void cheng(JU &a,JU &b,int ax,int ay,int bx,int by,int dep,int X,int Y)
{
	if (dep==0)
	{
		kuai[X][Y]=a[ax][ay]*b[bx][by]%md;
		return;
	}
	int der=1<<(dep-1),mxn=X+(1<<dep),mxm=Y+(1<<dep);
	cheng(a,b,ax,ay,bx,by,dep-1,X,Y);
	cheng(a,b,ax,ay+der,bx,by+der,dep-1,X,Y+der);
	cheng(a,b,ax,ay,bx,by+der,dep-1,X+der,Y);
	cheng(a,b,ax,ay+der,bx,by,dep-1,X+der,Y+der);
	for (int i=X;i<X+der;i++)
	  for (int j=Y;j<Y+der;j++)
	  {
	    solve(mid[i][j],kuai[i][j]+kuai[i][j+der]); 
		mid[i+der][j+der]=mid[i][j];
	    solve(mid[i][j+der],kuai[i+der][j]+kuai[i+der][j+der]);
	    mid[i+der][j]=mid[i][j+der];
	  }
	for (int i=X;i<mxn;i++)
	  for (int j=Y;j<mxm;j++)
	    kuai[i][j]=mid[i][j];
}
//在kuai[][]返回答案不用清零 
void kpow(JU &a,int b)
{
	for (int i=0;i<s;i++) ans[i][i]=1;
	while (b)
	{
		if (b&1)
		{
			cheng(ans,a,0,0,0,0,n,0,0);
			for (int i=0;i<s;i++)
			  for (int j=0;j<s;j++)
			    ans[i][j]=kuai[i][j];
			//printf("ans\n"); ans.outit();
		}
		cheng(a,a,0,0,0,0,n,0,0);
		for (int i=0;i<s;i++)
		  for (int j=0;j<s;j++)
		    a[i][j]=kuai[i][j];
		//printf("a\n");a.outit();
		b>>=1;
	}
}
	
int main()
{
	freopen("monster.in","r",stdin); freopen("monster.out","w",stdout);
	int t;
	scanf("%d%d",&n,&t);
	ok[0]=1; for (int i=0;i<n;i++) ok[1<<i]=1;
	s=1<<n;
	for (int i=0;i<s;i++)
	  for (int j=0;j<s;j++)
	    a[i][j]=ok[i^j];
	//a.outit();
	kpow(a,t);
	for (int i=0;i<s;i++) scanf("%d",&b[i]);
	for (int j=0;j<s;j++)
	  for (int k=0;k<s;k++)
	    sum[j]=(sum[j]+b[k]*ans[k][j])%md;
	for (int i=0;i<s;i++) printf("%lld ",sum[i]); printf("\n");
	return 0;
}

