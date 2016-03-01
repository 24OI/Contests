#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int mod=593119681;
int n,t,head[50005],nxt[50005],e[50005],cnt,nu[50005],a[50005],flow[10][10];

void add(int u,int v){
	flow[u][v]=1;
	nxt[++cnt]=head[u],e[cnt]=v,head[u]=cnt;
	return;
}

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	int m=1<<n;m--;
	for(int i=0;i<=m;i++){
		int m=i,s=-1;
		while(s<n-1){
			int t=m%2;s++;
			if(t==0) add(i,i+(1<<s));
			else add(i,i-(1<<s));
			m/=2;
		}
	}
	for(int i=0;i<=m;i++){
		scanf("%d",&nu[i]);}
	while(t--){
		for(int i=0;i<=n;i++){
			if(nu[i]){
				for(int j=head[i];j;j=nxt[j])
				a[e[j]]+=nu[i];}
		}
		for(int i=0;i<=m;i++)	nu[i]=(a[i]+nu[i])%mod,a[i]=0;
	}
	for(int i=0;i<=m;i++) printf("%d ",nu[i]);
}
