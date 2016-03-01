#include<cstdio>
#define LL long long
using namespace std;
const int mod=593119681;
LL a[1500][1500],d[1500][1500];
LL b[1500],c[1500];
int n,t,w;
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	w=(1<<n)-1;
	for(int i=0;i<=w;i++) scanf("%I64d",&b[i]),b[i]%=mod,a[i][i]++;
	for(int i=0;i<=w;i++){
		for(int j=0;j<n;j++){
			a[i][(i^(1<<j))]++;
		}
	}
	while(t>0){
		if(t%2==1){
			for(int i=0;i<=w;i++){
				for(int j=0;j<=w;j++){
					c[j]+=a[i][j]*b[i];
					c[j]%=mod;
				}
			}
			for(int i=0;i<=w;i++) b[i]=c[i],c[i]=0;
		}
		for(int i=0;i<=w;i++){
			for(int j=0;j<=w;j++){
				for(int k=0;k<=w;k++){
					d[i][j]+=a[i][k]*a[k][j];
					d[i][j]%=mod;
				}
			}
		}
		for(int i=0;i<=w;i++){
			for(int j=0;j<=w;j++) a[i][j]=d[i][j],d[i][j]=0;
		}
		t>>=1;
	}
	for(int i=0;i<=w-1;i++) printf("%I64d ",b[i]);
	printf("%I64d",b[w]);
}
