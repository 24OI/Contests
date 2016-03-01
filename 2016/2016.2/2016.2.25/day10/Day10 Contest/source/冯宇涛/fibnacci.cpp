#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_N 100010
#define mod 1000000007
using namespace std;
inline int read(){
	int sum=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*t;
}
typedef long long ll;
int n,m,f[MAX_N],w[MAX_N];
ll res;

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	n=read(),m=read();
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)
		w[i]=read()%mod;
	for(;m;m--){
		int op=read(),l=read(),r=read();
		if(op==1){
			for(int i=l;i<=r;i++)
				w[i]=(w[i]%mod+f[i-l+1]%mod)%mod;
		}
		else {
			res=0;
			for(int i=l;i<=r;i++)
				res=(res%mod+w[i]%mod)%mod;
			printf("%lld\n",res%mod);
		}
	}
	return 0;
}
