#include<cstdio>
#include<iostream>
#define LL long long
using namespace std;
const int N = 100;
const int eN = 10000;
const LL MO = 593119681;
struct Mat{
	int h,l;
	LL f[N][N];
	void clear(){
		for(int i=0;i<=h;++i)
			for(int j=0;j<=l;++j)
				f[i][j]=0;
	}
	Mat(){ clear(); }
	Mat(int _h,int _l){ h=_h; l=_l; clear(); }
	Mat friend unit(Mat &A){
		Mat ret=Mat(A.h,A.l);
		for(int i=0;i<=ret.h;++i) ret.f[i][i]=1;
		return ret;
	}
	Mat friend operator * (Mat A,Mat B){
		Mat ret=Mat(A.h,B.l);
		for(int i=0;i<=ret.h;++i){
			for(int j=0;j<=ret.l;++j){
				for(int k=0;k<=A.l;++k){
					ret.f[i][j]+=A.f[i][k]*B.f[k][j];
					ret.f[i][j]%=MO;
				}
			}
		}
		return ret;
	}
	void print(){
		for(int i=0;i<=h;++i){
			for(int j=0;j<=l;++j){
				printf("%d ",f[i][j]);
			}
			printf("\n");
		}
	}
};
Mat qpow(Mat &x,int k){
	Mat ret=unit(x),t=x;
	for(;k;k>>=1){
		if(k&1) ret=ret*t; t=t*t; 
	}
	return ret;
}
bool conf(int x,int y){
	int z=x^y,cnt=0;
	for(;z;z>>=1) if(z&1)++cnt;
	if(cnt==1) return true;
	return false;
}
int n,k,t;
void solve1(){
	Mat M=Mat(k,k);
	for(int i=0;i<=k;++i){
		for(int j=i+1;j<=k;++j){
			if(conf(i,j)){
				M.f[i][j]=M.f[j][i]=1;
			}
		}
	}
	Mat A=Mat(k,k),B=Mat(k,k);
	for(int i=0;i<=k;++i) scanf("%I64d",&B.f[i][i]);
	for(int i=0;i<=k;++i) M.f[i][i]=1;
	//M.print();
	A=B*qpow(M,t);
	for(int i=0;i<=k;++i){
		LL Ans=0;
		for(int j=0;j<=k;++j){
			(Ans+=A.f[j][i])%=MO;
		}
		printf("%I64d ",Ans);
	}
}
int ce,head[eN],nex[eN*2],to[eN*2];
LL s[2][eN];
void add(int x,int y){
	nex[++ce]=head[x]; head[x]=ce; to[ce]=y;
}
void solve2(){
	for(int i=0;i<=k;++i) scanf("%I64d",&s[0][i]);
	for(int i=0;i<=k;++i){
		for(int j=i+1;j<=k;++j){
			if(conf(i,j)){
				add(i,j); add(j,i);
				//fprintf(stderr,"%d %d\n",i,j);
			}
		}
	}
	for(int tt=1;tt<=t;++tt){
		for(int o=0;o<=k;++o) s[tt&1][o]=s[(tt&1)^1][o];
		for(int o=0;o<=k;++o){
			for(int i=head[o];i;i=nex[i]){
				(s[tt&1][to[i]]+=s[(tt&1)^1][o])%=MO;
			}
		}
	}
	for(int i=0;i<=k;++i) printf("%I64d ",s[t&1][i]);
	printf("\n");
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	k = (1<<n)-1;
	if(n<=6){
		solve1();
	}else{
		solve2();
	}
	return 0;
}
