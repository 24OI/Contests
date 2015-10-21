#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
typedef long long ll;
ll l,r,primecnt;
bool isprime[5000008];
ll prime[5000008];
ll mi[5000008];
int generateprimelist(int n){
	int cnt=0;
	for (int i = 0; i <=n; ++i)
	{
		isprime[i]=true;
	}
	isprime[0]=isprime[1]=false;
	for (int i = 2; i <=n; ++i)
	{
		if(isprime[i]){
			mi[i]=i;
			prime[cnt++]=i;
		}
		for (int j= 0; j < cnt; ++j)
		{
			if(prime[j]*i >n){
				break;
			}
			isprime[prime[j]*i]=false;
			mi[prime[j]*i]=min(mi[prime[j]*i],prime[j]);
			if(i%prime[j]==0){
				mi[i]=min(mi[i],prime[j]);
				break;
			}
		}
	}
	return cnt;
}

int main(){
	open("factor.in","factor.out");
	cin>>l>>r;
	for (int i = 0; i < 5000008; ++i)
	{
		mi[i]=INT_MAX;
	}
	primecnt=generateprimelist(5000008);
	if(r<5000008){
		for (ll i = l; i <=r; ++i)
		{
			cout<<mi[i]<<endl;
		}
	}else{
		for (ll i = l; i <=r; ++i)
		{
			for (int j = 0; j <primecnt; ++j)
			{
				if(i%prime[j]==0){
					cout<<prime[j]<<endl;
					break;
				}else{
					if(j==primecnt-1)
						cout<<i<<endl;
				}
			}
		}
	}
	return 0;
}
