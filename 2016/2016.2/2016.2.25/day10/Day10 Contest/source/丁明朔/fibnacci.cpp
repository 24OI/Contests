#include<cstdio>
using namespace std;

const int mod=1000000001;

int a[100010],n,m;

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(m--){
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			int now=1,pre=0;
			for(int i=l;i<=r;i++){
				a[i]=(a[i]+now)%mod;
				int t=pre;
				pre=now;
				now=(now+t)%mod;
			}
		}
		if(opt==2){
			int ret=0;
			for(int i=l;i<=r;i++){
				ret=(ret+a[i])%mod;
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}
