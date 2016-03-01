#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000005,MOD=593119681;
int n,t,st[MAXN],l,r;
int head[MAXN],next[MAXN],to[MAXN],cnt;
int check[MAXN],s[MAXN];
void insert(int x,int y){next[++cnt]=head[x];to[cnt]=y;head[x]=cnt;}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	memset(check,-1,sizeof check);
	for(int i=0;i<1<<n;++i){
		for(int k=0;k<n;++k)
		if(i>>k&1^1){
			insert(i,i|(1<<k));
			insert(i|(1<<k),i);
		}
	}
	int times=0;
	for(int x,i=0;i<1<<n;++i){
		scanf("%d",&s[i]);
		if(s[i]){
			check[st[r++]=i]=times;
		}
	}
	while(times<t&&l<1<<n){
		++times;
		int now=r;
		for(int i=l;i<r;++i){
			int x=st[i];
			for(int j=head[x];j;j=next[j]){
				if(check[to[j]]==-1){
					check[st[now++]=to[j]]=times;
				}
				s[to[j]]=(s[to[j]]+(t-check[x])%MOD)%MOD;
			}
		}
		l=r;
		r=now;
	}
	for(int i=0;i<1<<n;++i)printf("%d ",s[i]);
	return 0;
}
