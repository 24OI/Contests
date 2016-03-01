#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX_N (2<<18)+10
#define mod 593119681
using namespace std;
inline int read(){
	int sum=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*t;
}
int n,t,next[MAX_N<<1],fir[MAX_N],to[MAX_N<<1],w[MAX_N<<1],cnt,lz[MAX_N<<1];
void add(int x,int y){
	next[++cnt]=fir[x];to[cnt]=y;fir[x]=cnt;
}

void solve(){
	for(int s=0;s<1<<n;s++){
		for(int j=0;j<n;j++)
			lz[s^(1<<j)]=(lz[s^(1<<j)]+w[s])%mod;
	}
}

void relax(){
	for(int s=0;s<1<<n;s++)
		w[s]=(w[s]%mod+lz[s]%mod)%mod,lz[s]=0;
}

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	n=read(),t=read();
	for(int s=0;s<1<<n;s++)
		w[s]=read();
	for(int i=1;i<=t;i++){
		solve();
		relax();
	}
	for(int s=0;s<1<<n;s++)
		printf("%d ",w[s]);
	printf("\n");
	return 0;
}
