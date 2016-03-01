#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define mod 593119681LL
const int maxn=262146;
vector<int> tu[maxn];int n,t;
int f[2][maxn];int cur=0;
int main()
{freopen("monster.in","r",stdin);
freopen("monster.out","w",stdout);
scanf("%d%d",&n,&t);
int S=(1<<n);
for(int i=0;i<S;i++){scanf("%d",&f[0][i]);
}
int u=1;
for(int i=0;i<S;i++)
{for(int j=0;(1<<j)<S;j++){tu[i].push_back(i^(1<<j));
}
}
for(int i=0;i<t;i++)
{cur^=1;
memset(f[cur],0,sizeof(f[cur]));
for(int j=0;j<S;j++)
{f[cur][j]=f[cur^1][j];
for(int k=0;k<tu[j].size();k++){
f[cur][j]+=f[cur^1][tu[j][k]];
f[cur][j]%=mod;	
}
}
}
for(int i=0;i<S;i++)
{if(i)printf(" ");
printf("%d",f[cur][i]);
}
}
