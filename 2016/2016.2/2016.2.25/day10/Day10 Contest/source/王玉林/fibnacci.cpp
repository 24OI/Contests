#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
#define maxn 100010
int n,m,op,l,r;
const int mod=1e9+1;
int f[maxn],s[maxn],a[maxn];
struct treenode{
	int l,r,data,tag;
}t[maxn*4];
void read(int &n){
	 char c=getchar();
	 n=0;
	 while (c<'0' || c>'9') c=getchar();
	 while (c>='0' && c <='9') n=n*10+c-'0',c=getchar();
}
void pb(int x){
	if (t[x].tag!=0){
		if (t[x].l!=t[x].r){
		if (t[x<<1].tag!=0) pb(x<<1);
		t[x<<1].tag=t[x].tag;
		if (t[(x<<1)+1].tag!=0) pb((x<<1)+1); 
		t[(x<<1)+1].tag=t[x].tag+(t[x<<1].r-t[x<<1].l+1);
		}
		t[x].data=(s[t[x].r-t[x].l+t[x].tag]-s[t[x].tag-1]+t[x].data)%mod;
		if (t[x].data<0) t[x].data+=mod;
		t[x].tag=0;
	}
}
void updata(int x){
    pb(x);
	pb(x<<1);
	pb((x<<1)+1);
	t[x].data=(t[x<<1].data+t[(x<<1)+1].data)%mod;
}
void build(int x,int l,int r){
	if (l>r) return;
	t[x].l=l;
	t[x].r=r;
	t[x].tag=0;
	if (l==r){
		t[x].data=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	updata(x);
}
void add(int x,int l,int r,int p){
	pb(x);
	if (t[x].l==l && t[x].r==r){
		t[x].tag=p;
		pb(x);
		return;
	}
	if (r<=t[x<<1].r) add(x<<1,l,r,p);
	else if (l>=t[(x<<1)+1].l) add((x<<1)+1,l,r,p);
	else {
		add(x<<1,l,t[x<<1].r,p);
		add((x<<1)+1,t[(x<<1)+1].l,r,p+t[x<<1].r-l+1);
	}
	updata(x);
}
int ask(int x,int l,int r){
	pb(x);
	if (t[x].l==l && t[x].r==r) return t[x].data;
	if (r<=t[x<<1].r) return ask(x<<1,l,r)%mod;
	else if (l>=t[(x<<1)+1].l) return ask((x<<1)+1,l,r)%mod;
	else {
		return (ask(x<<1,l,t[x<<1].r)+ask((x<<1)+1,t[(x<<1)+1].l,r))%mod;
	}
	updata(x);
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]),a[i]%=mod;
	build(1,1,n);
	f[1]=1;s[1]=1;
	for (int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod,s[i]=(s[i-1]+f[i])%mod;
	for (int i=1;i<=m;i++) {
		read(op),read(l),read(r);
		if (op==1) add(1,l,r,1);
		else printf("%d\n",ask(1,l,r));
	}
	return 0;
}

