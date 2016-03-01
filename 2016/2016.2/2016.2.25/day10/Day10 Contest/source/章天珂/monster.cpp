#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20];
struct edge{
	int to,pre;
}e[100004];
int cnt=0,n,t;
int dp[2000][3],head[2000],w[2000];
void insert(int u,int v){
	e[++cnt]=(edge){v,head[u]};head[u]=cnt;
	e[++cnt]=(edge){u,head[v]};head[v]=cnt;
}

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	int num=1<<n;
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++)
		{
			
			int c=i^j,s=0;
			for(int k=0;k<=n+1;k++)
			{
				if (c&(1<<k)) s++;
			}
			if (s==1) insert(i,j);
		}	
	}
	for(int i=0;i<num;i++)
		scanf("%d",&dp[i][0]);
	int cur=0;
	while(t--){
		cur^=1;
		for(int i=0;i<num;i++) {
			dp[i][cur]=dp[i][cur^1];
			for(int j=head[i];j;j=e[j].pre){
				dp[i][cur]+=dp[e[j].to][cur^1];
			}
		}
	}
	for(int i=0;i<num;i++)
		printf("%d ",dp[i][cur]);
	return 0;
}
