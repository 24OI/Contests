#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define lc o<<1
#define rc o<<1|1
using namespace std;
const int mod=(1e9)+1;
const int N=100000+5;
typedef long long ll;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll fib[N],sum[N];
double mul[N];
struct Node{
	int l,r,f;
	ll sum;
	bool tag,leaf;
}tr[N<<2];
void pushup(int o){
	tr[o].sum=(tr[lc].sum+tr[rc].sum)%mod;
}
ll s(int l,int r){
	return ((sum[r]-sum[l-1])%mod+mod)%mod;
}
void pushdown(int o){
	if(tr[o].tag){
		if(!tr[o].leaf){
			pushdown(lc);
			pushdown(rc);
		}
		tr[lc].tag=tr[rc].tag=true;
		int len=tr[o].r-tr[o].l+1,len1=len-(len>>1),len2=len>>1;
		tr[lc].f=tr[o].f;tr[rc].f=tr[o].f+len1;
		tr[lc].sum=(tr[lc].sum+s(tr[lc].f,tr[lc].f+len1-1))%mod;
		tr[rc].sum=(tr[rc].sum+s(tr[rc].f,tr[rc].f+len2-1))%mod;
		tr[o].tag=false;
	}
}
void update(int o,int a,int b,int f){
	int l=tr[o].l,r=tr[o].r;
	pushdown(o);
	if(l==a&&b==r){
		int len=r-l+1;
		tr[o].tag=true;
		tr[o].f=f;
		tr[o].sum=(tr[o].sum+s(f,f+len-1))%mod;
	}
	else{
		int m=l+r>>1;
		if(b<=m)update(lc,a,b,f);
		else if(m<a)update(rc,a,b,f);
		else update(lc,a,m,f),update(rc,m+1,b,f+m-a+1);
		pushup(o);
	}
}
ll query(int o,int a,int b){
	int l=tr[o].l,r=tr[o].r;
	if(l==a&&b==r)return tr[o].sum;
	else{
		pushdown(o);
		int m=l+r>>1;
		if(b<=m)return query(lc,a,b);
		else if(m<a)return query(rc,a,b);
		else return (query(lc,a,m)+query(rc,m+1,b))%mod;
	}
}
void build(int o,int l,int r){
	tr[o].l=l;tr[o].r=r;
	if(l==r){
		tr[o].sum=read()%mod;
		tr[o].leaf=true;
	}
	else{
		int m=l+r>>1;
		build(lc,l,m);build(rc,m+1,r);
		pushup(o);
	}
}
void pre(int n){
	fib[0]=0;fib[1]=1;sum[0]=0;sum[1]=1;
	for(int i=2;i<=100000;i++){
		fib[i]=(fib[i-1]+fib[i-2])%mod;
		sum[i]=(sum[i-1]+fib[i])%mod;
	}
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int n,m;n=read();m=read();
	build(1,1,n);
	pre(n);
	int opt,l,r;
	while(m--){
		opt=read();l=read();r=read();
		if(opt==1)update(1,l,r,1);
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}
		
