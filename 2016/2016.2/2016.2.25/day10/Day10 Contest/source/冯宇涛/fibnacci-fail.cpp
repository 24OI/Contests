#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_N 100010
#define mod 1000000007
using namespace std;
inline int read(){
	int sum=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*t;
}
typedef long long ll;
struct data{
	int l,r;
	ll sum,lz;
}tree[8*MAX_N];
int n,m,f[MAX_N],w[MAX_N],F[MAX_N],mx;
ll res;

void build(int ri,int l,int r){
	tree[ri].l=l;tree[ri].r=r;
	if(l==r){
		tree[ri].sum=w[l];mx=max(mx,ri);
		return ;
	}
	int mid=(l+r)>>1;
	build(ri<<1,l,mid);
	build((ri<<1)^1,mid+1,r);
	tree[ri].sum=(tree[ri<<1].sum+tree[(ri<<1)^1].sum)%mod;
}

void push(int ri){
	if(!tree[ri].lz||ri>mx)return ;
	tree[ri].sum=(tree[ri].sum%mod+F[tree[ri].lz+tree[ri].r-tree[ri].l]%mod-F[tree[ri].lz-1]+mod)%mod;
	push(ri<<1);push((ri<<1)+1);
	tree[ri<<1].lz=tree[ri].lz;tree[(ri<<1)^1].lz=tree[ri].lz+tree[(ri<<1)^1].l-tree[ri].l;
	tree[ri].lz=0;
}

void chg(int ri,int l,int r,int on){
	push(ri);
//	printf("%d:33\n",tree[9].sum);
//	printf("%d:lz\n",tree[9].sum);
	if(l>tree[ri].r||r<tree[ri].l)return ;
	if(l<=tree[ri].l&&r>=tree[ri].r){
		if(on>0)tree[ri].lz=tree[ri].l-l+1;
		else res=(res+tree[ri].sum)%mod;
		push(ri);
//		printf("%d %d %d::\n",tree[ri].l,tree[ri].r,tree[ri].sum);
		return ;
	}
	int lri=ri<<1,rri=lri^1;
	chg(lri,l,r,on);chg(rri,l,r,on);
	tree[ri].sum=(tree[lri].sum+tree[rri].sum)%mod;
//	printf("%d %d %d::\n",tree[ri].l,tree[ri].r,tree[ri].sum);
}

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	n=read(),m=read();
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)
		F[i]=(F[i-1]+f[i])%mod;
	for(int i=1;i<=n;i++)
		w[i]=read()%mod;
	build(1,1,n);
	for(;m;m--){
		int op=read(),l=read(),r=read();
		if(op==1){
			chg(1,l,r,1);
		}
		else {
			res=0;
			chg(1,l,r,-1);
			printf("%lld\n",res%mod);
		}
	}
	return 0;
}
