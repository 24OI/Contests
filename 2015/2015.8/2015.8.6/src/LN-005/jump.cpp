#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#define MOD 1000000007
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)

using namespace std;
typedef long long ll;

int nn,aa,bb,kk;
int cnt=0;
void dfs(int n,int a,int b,int k){
	if(k==0){
		++cnt;
		cnt%=MOD;
		return;
	}
	if(a>b){
		int temp=0;
		for (int i = b+1; i <min(n+1,2*a-b); ++i)
		{
			if(i==a)continue;
			dfs(n,i,b,k-1);
		}
	}else{
		int temp=0;
		for (int i = max(1,2*a-b+1); i <b; ++i)
		{
			if(i==a)continue;
			dfs(n,i,b,k-1);
		}
	}
}
int main(){
	open("jump.in","jump.out");
	cin>>nn>>aa>>bb>>kk;
	dfs(nn,aa,bb,kk);
	cout<<cnt;
}
