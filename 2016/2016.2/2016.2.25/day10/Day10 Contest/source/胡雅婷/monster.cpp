#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1024,mod=593119681;

int f[maxn];
int a[maxn][maxn];
int d,n,K;

int b[maxn][maxn],c[maxn][maxn];

void mul(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				int x=1ll*a[i][k]*a[k][j]%mod;
				c[i][j]=(c[i][j]+x)%mod;
			}
				
	memcpy(a,c,sizeof(a));
	memset(c,0,sizeof(c));
}

void cal(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				int x=1ll*b[i][k]*a[k][j]%mod;
				c[i][j]=(c[i][j]+x)%mod;
			}
				
	memcpy(b,c,sizeof(b));
	memset(c,0,sizeof(c));
	
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	printf("\n");*/
}

int g[maxn];
void getans(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i]=(g[i]+1ll*b[i][j]*f[j]%mod)%mod;
}

void pow(){
	for(int i=K;i;i>>=1,mul())
		if(i&1) cal();
	getans();
}

int main(){

freopen("monster.in","r",stdin);
freopen("monster.out","w",stdout);
	scanf("%d %d",&d,&K);
	n=(1<<d);
	for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
	
	for(int x=0;x<n;x++){
		for(int i=0;i<d;i++)
			if(x&(1<<i)) a[x][x-(1<<i)]=1;
			else a[x][x+(1<<i)]=1;
		a[x][x]=1;
	}
	
	for(int i=0;i<n;i++) b[i][i]=1;
	
	pow();
	
	for(int i=0;i<n;i++)
		printf("%d ",g[i]);
}
