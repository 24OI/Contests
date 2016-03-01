#include<cstdio>
#define LL long long
using namespace std;
const int N = 1e5;
const int MO = 1e9+1;
int n,t,k,l,r;
LL a[N],f[N];
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&t);
	f[0]=0; f[1]=1;
	for(int i=2;i<=n;++i) (f[i]=f[i-1]+f[i-2])%=MO;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	while(t--){
		scanf("%d%d%d",&k,&l,&r);
		if(k==1){
			for(int i=l;i<=r;++i){
				(a[i]+=f[i-l+1])%=MO;
			}
		}else{
			LL Ans=0;
			for(int i=l;i<=r;++i){
				(Ans+=a[i])%=MO;
			}
			printf("%I64d\n",Ans);
		}
	}
	return 0;
}
