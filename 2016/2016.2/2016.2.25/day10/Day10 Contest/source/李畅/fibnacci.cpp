#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long mod=1000000001LL;
const int MAXN=100005;

long long f[MAXN],m,n,nu[MAXN],ad[MAXN],as[MAXN];

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&nu[i]);
		as[i]=(as[i-1]+nu[i])%mod;
    }
	for(int i=1;i<=m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==1){
			for(int i=b;i<=c;i++){
				nu[i]=(nu[i]+f[i-b+1])%mod;}
		}
		else {
				long long ans=0;
				for(int i=b;i<=c;i++){
					ans=(ans+nu[i])%mod;
				}
				printf("%lld\n",ans);
		}
	}
	return 0;
}

