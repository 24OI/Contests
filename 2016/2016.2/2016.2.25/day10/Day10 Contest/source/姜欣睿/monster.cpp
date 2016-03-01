#include<cstdio>
#include<cstdlib>
#define N (1<<18)
#define M 593119681
using namespace std;
int x[N][2],n,t;
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=0;i<(1<<n);i++) scanf("%d",&x[i][0]);
	for(int i=1,cur=1;i<=t;i++,cur^=1)
	{
		for(int j=0;j<(1<<n);j++) x[j][cur]=x[j][cur^1];
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<n;k++)
				x[j][cur]=(x[j][cur]+x[j^(1<<k)][cur^1])%M;
	}
	for(int i=0;i<(1<<n);i++) printf("%d ",x[i][t&1]); puts("");
	return 0;
}
