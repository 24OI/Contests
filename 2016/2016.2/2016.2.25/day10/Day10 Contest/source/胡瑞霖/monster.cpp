#include<algorithm>
#include<cstdio>
#define mo 593119681
using namespace std;
int n,t,f[300];bool is[300];
int go[1100][11],sum[1100][1100];
int main(){
	freopen("monster.in","r",stdin);freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;++i)is[1<<i]=true;n=1<<n;
	for(int i=0;i<n;++i)scanf("%d",&sum[i][0]);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(is[i^j]||i==j){
				go[i][++go[i][0]]=j;
			}
	for(int tt=0;tt<t;++tt)
		for(int i=0;i<n;++i)
			for(int j=1;j<=go[i][0];++j){
				sum[go[i][j]][tt+1]+=sum[i][tt];sum[go[i][j]][tt+1]%=mo;
			}
	for(int i=0;i<n;++i)printf("%d ",sum[i][t]);
	return 0;
}
