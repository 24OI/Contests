#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define MAXN 110
#define MAXM 100010
#define INF 1000000000
#define MOD 593119681
#define eps 1e-8
#define ll long long
struct mat{
	int N;
	int M;
	int x[MAXN][MAXN];
	mat(){
		memset(x,0,sizeof(x));
	}
	mat(int _N,int _M){
		N=_N;
		M=_M;
		memset(x,0,sizeof(x));
	}
	friend mat operator *(mat &x,mat &y){
		int i,j,k;
		mat z(x.N,y.M);
		for(i=0;i<x.N;i++){
			for(j=0;j<y.M;j++){
				for(k=0;k<x.M;k++){
					z.x[i][j]+=(((ll)x.x[i][k]*y.x[k][j])%MOD);
					z.x[i][j]%=MOD;
				}
			}
		}
		return z;
	}
	void pt(){
		int i,j;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				cout<<x[i][j]<<' ';
			}
			cout<<endl;
		}
	}
};
int n=1,N,T;
mat a,b,c;
int A[2][2500];
void cal1(){
	int i,j,k=0,t;
	for(i=0;i<n;i++){
		scanf("%d",&A[0][i]);
	}
	while(T--){
		for(i=0;i<n;i++){
			A[k^1][i]=A[k][i];
		}
		for(i=0;i<n;i++){
			for(j=1,t=1;j<=N;j++,t<<=1){
				A[k^1][i^t]+=A[k][i];
				A[k^1][i^t]%=MOD;
			}
		}
		k^=1;
	}
	for(i=0;i<n;i++){
		printf("%d ",A[k][i]);
	}
	printf("\n");
}
void cal2(){
	int i,j;
	a=mat(1,n);
	b=mat(n,n);
	c=mat(n,n);
	for(i=0;i<n;i++){
		scanf("%d",&a.x[0][i]);
	}
	for(i=0;i<n;i++){
		//cout<<i<<':'<<endl;
		for(j=0;j<n;j++){
			if(i==j){
				b.x[i][j]=1;
				c.x[i][j]=1;
			}
			int t=i^j;
			int tmp=0;
			while(t){
				tmp+=t&1;
				t>>=1;
			}
			if(tmp==1){
			//	cout<<j<<' ';
				b.x[j][i]=1;
			}
		}
		//cout<<endl;
	}
//	b.pt();
	while(T){
		if(T&1){
			c=c*b;
		}
		b=b*b;
		T>>=1;
	}
	a=a*c;
	for(i=0;i<n;i++){
		printf("%d ",a.x[0][i]);
	}
	printf("\n");
}
int main(){
	int i,j;
	//*
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	//*/
	scanf("%d%d",&N,&T);
	for(i=1;i<=N;i++){
		n*=2;
	}
	if(N>6){
		cal1();
	}else{
		cal2();
	}
	
	return 0;
}

/*

*/
