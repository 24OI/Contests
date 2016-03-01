#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const long long MOD=1000000001;
int n,m,mark[MAXN];
long long f[MAXN],fib[MAXN],tree[MAXN<<2];
void build(int node,int begin,int end){
	if(begin==end){tree[node]=f[begin];return;}
	int mid=(begin+end)>>1;
	build(node<<1,begin,mid);
	build(node<<1|1,mid+1,end);
	tree[node]=(tree[node<<1]+tree[node<<1|1])%MOD;
}
void pushdown(int node,int begin,int end){
	if(begin!=end){
		int mid=(begin+end)>>1;
		tree[node<<1]=(tree[node<<1]+mark[node]*(fib[mid]-fib[begin-1]+MOD)%MOD)%MOD;
		tree[node<<1|1]=(tree[node<<1|1]+mark[node]*(fib[end]-fib[mid]+MOD)%MOD)%MOD;
		mark[node<<1]+=mark[node];
		mark[node<<1|1]+=mark[node];
	}
	mark[node]=0;
}
void change(int node,int begin,int end,int l,int r){
	if(begin>r||end<l)return;
	if(begin>=l&&end<=r){++mark[node];tree[node]=(tree[node]+(fib[end]-fib[begin-1]+MOD)%MOD)%MOD;return;}
	pushdown(node,begin,end);
	tree[node]=(tree[node]+(fib[min(end,r)]-fib[max(begin,l)-1]+MOD)%MOD)%MOD;
	int mid=(begin+end)>>1;
	change(node<<1,begin,mid,l,r);
	change(node<<1|1,mid+1,end,l,r);
}
long long query(int node,int begin,int end,int l,int r){
	if(begin>r||end<l)return 0;
	if(begin>=l&&end<=r)return tree[node];
	int mid=(begin+end)>>1;
	pushdown(node,begin,end);
	return (query(node<<1,begin,mid,l,r)+query(node<<1|1,mid+1,end,l,r)+MOD)%MOD;
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&f[i]);
	fib[1]=1;
	for(int i=2;i<=n;++i)fib[i]=(fib[i-1]+fib[i-2])%MOD;
	for(int i=2;i<=n;++i)fib[i]=(fib[i]+fib[i-1])%MOD;
	build(1,1,n);
	while(m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)change(1,1,n,l,r);
		else printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}
