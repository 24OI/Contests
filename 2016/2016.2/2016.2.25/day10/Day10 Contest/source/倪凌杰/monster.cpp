#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=593119681;
const int N=1100;
struct Edge{int to,next;}e[N*10];
int head[N],cnt;
void ins(int u,int v){
	e[++cnt]=(Edge){v,head[u]};head[u]=cnt;
}
bool calc(int x){
	int ans=0;
	while(x){
		ans+=x&1;
		if(ans>1)return false;
		x>>=1;
	}
	return ans;
}
void build(int n){
	for(int i=0;i<(1<<n);i++)
	for(int j=i+1;j<(1<<n);j++){
		if(calc(i^j)){
			ins(i,j),ins(j,i);
		}
	}
}
ll ex[2][N];
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int n,t;scanf("%d%d",&n,&t);
	build(n);
	for(int i=0;i<(1<<n);i++)
	scanf("%d",&ex[0][i]);
	for(int i=1;i<=t;i++){
		int now=i&1;
		memset(ex[now],0,sizeof(ex[now]));
		for(int u=0;u<(1<<n);u++){
			for(int j=head[u];j;j=e[j].next)
			ex[now][u]=(ex[now][u]+ex[now^1][e[j].to])%mod;
			ex[now][u]=(ex[now][u]+ex[now^1][u])%mod;
		}
	}
	for(int i=0;i<(1<<t);i++)
	printf("%lld ",ex[t&1][i]);
	return 0;
}
