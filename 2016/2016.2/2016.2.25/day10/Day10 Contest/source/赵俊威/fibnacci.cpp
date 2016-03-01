#include<cstdio>
using namespace std;
const int mod=1E9+1;
const int N=1E5+50;
int a[N],f[N];
int n,m;
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=mod;
	f[1]=1; f[2]=1;
	for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2],f[i]%=mod;
	for(int i=1;i<=m;i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		for(int j=l;j<=r;j++) a[j]+=f[j-l+1],a[j]%=mod;
		else{
			int tmp=0;
			for(int j=l;j<=r;j++) tmp+=a[j],tmp%=mod;
			printf("%d\n",tmp);
		}
	}
}
