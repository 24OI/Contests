#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=(2<<18)+20,MOD=593119681;
typedef long long LL;
int head[maxn],to[maxn],nxt[maxn],cnt,bin[20],num[maxn],used[maxn];
void add(int x,int y){
	nxt[++cnt]=head[x],head[x]=cnt,to[cnt]=y;
//	nxt[++cnt]=head[y],head[y]=cnt,to[cnt]=x;
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int n,t;
	bin[0]=1;
	scanf("%d%d",&n,&t);
	for(int i=1;i<20;i++) bin[i]=bin[i-1]*2;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<=n;j++){
			if((i>>j)&1&&i!=i-bin[j]&&i-bin[j]>=0)
				add(i,i-bin[j]);
			else if(i+bin[j]<bin[n]&&i!=i+bin[j])
				add(i,i+bin[j]);
		}
	}
	/*for(int i=0;i<(1<<N);i++){
		for(int j=0;j<=n;j++){
			if((i>>j)&1)
			else
		}
	}*/
/*	for(int i=0;i<(1<<n);i++){
		for(int j=head[i];j;j=nxt[j]) printf("%d ",to[j]);
		printf("\n");
	}*/
	for(int i=0;i<(1<<n);i++)
		scanf("%d",&num[i]),used[i]=num[i];
	while(t--){
		for(int i=0;i<(1<<n);i++){
			if(used[i]!=0){
				for(int j=head[i];j;j=nxt[j]) 
					num[to[j]]=(num[to[j]]+used[i])%MOD;
			}
		}
		for(int i=0;i<(1<<n);i++) used[i]=num[i];
	}
	for(int i=0;i<(1<<n);i++) printf("%d ",num[i]%MOD);
	return 0;
}
