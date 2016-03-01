#include<stdio.h>
const int maxn=1E6+3;
const int max6=99;
const int mod=593119681;

void print(int v){
	static bool first=true;
	if(first) printf("%d",v),first=false;
	else printf(" %d",v);
}

int N,M,T,V[maxn];

struct METRIX{
	int v[max6][max6];
	METRIX operator *(METRIX o){
		METRIX ret;
		for(int i=0;i<M;++i) for(int j=0;j<M;++j){
			ret.v[i][j]=0;
			for(int k=0;k<M;++k) ret.v[i][j]=(ret.v[i][j]+v[i][k]*o.v[k][j])%mod;
		}
		return ret;
	}
}base;

int cnt1(int v){
	int ret=0;
	while(v) ret+=v&1,v>>=1;
	return ret;
}

void solve1(){
	M=1<<N;
	for(int i=0;i<M;++i) for(int j=0;j<M;++j){
		base.v[i][j]=cnt1(i^j)<=1?1:0;
	}
	METRIX ans=base;
	--T;
	while(T){
		if(T&1) ans=ans*base;
		base=base*base;
		T>>=1;
	}
/*
	printf("base:\n");
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j) printf("%d ",ans.v[i][j]);
		printf("\n");
	}
	printf("--\n");
*/
	for(int i=0;i<M;++i){
		int out=0;
		for(int j=0;j<M;++j) out=(out+V[j]*ans.v[i][j])%mod;
		print(out);
	}
	printf("\n");
}

int nv[maxn];
void solve2(){
	M=1<<N;
	//for(int i=0;i<M;++i) for(int j=0;j<M;++j) map[i][j]=cnt1(i^j)<=1;
	while(T--){
		for(int i=0;i<M;++i){
			nv[i]=V[i];
			for(int j=0;j<N;++j) nv[i]=(nv[i]+V[i^(1<<j)])%mod;
		}
		for(int i=0;i<M;++i) V[i]=nv[i];
	}
	for(int i=0;i<M;++i) print(V[i]);
	printf("\n");
}

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&N,&T);
	for(int i=0;i<(1<<N);++i) scanf("%d",V+i);
	if(N<=7) solve1();
	else solve2();
}
