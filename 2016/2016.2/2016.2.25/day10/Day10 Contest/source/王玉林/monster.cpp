#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
#define maxn 1000030
const int mod=593119681;
int n,t,a[maxn],b[maxn];
void read(int &n){
	 char c=getchar();
	 n=0;
	 while (c<'0' || c>'9') c=getchar();
	 while (c>='0' && c <='9') n=n*10+c-'0',c=getchar();
	 }
int main(){
	freopen("monster.in","r",stdin); 
	freopen("monster.out","w",stdout);
	read(n),read(t);
	for (int i=0;i<(1<<n);i++) read(a[i]),a[i]%=mod;
	for (int i=1;i<=t;i++){
		for (int j=0;j<(1<<n);j++)
		if (a[j]!=0)
		 for (int k=0;k<n;k++)
		  if ((j&(1<<k))!=0) b[j-(1<<k)]=(b[j-(1<<k)]+a[j])% mod;
		  else  b[j+(1<<k)]=(b[j+(1<<k)]+a[j])% mod;
		for (int j=0;j<(1<<n);j++) a[j]=(a[j]+b[j])%mod,b[j]=0;
	}
	for (int i=0;i<(1<<n);i++) printf("%d ",a[i]);
	return 0;
}

