#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100007
#define mod 1000000001

int f[N],s[N],a[N];
struct edge{
	int l,r,sum,tag;
}t[4*N];
int n,m;
int ans;

void update(int idx){
	t[idx].sum=(t[idx<<1].sum+t[idx<<1|1].sum) % mod;
}

void buildtree(int l,int r,int idx){
	t[idx].l=l;
	t[idx].r=r;
	t[idx].tag=-1;
	if (l==r){
		t[idx].sum=a[l]%mod;
		return;
	}	
	int mid=(l+r)>>1;
	buildtree(l,mid,idx<<1);
	buildtree(mid+1,r,idx<<1|1);
	update(idx);
}

void pushdown(int idx){
	if ( t[idx].l==t[idx].r){
		return;
	}
	if (t[idx<<1].tag!=-1){
		pushdown(idx<<1);
	}
	if (t[idx<<1|1].tag!=-1) pushdown(idx<<1|1);
	t[idx<<1].tag=t[idx<<1|1].tag=t[idx].tag;
	t[idx<<1].sum+=s[t[idx<<1].r-t[idx].tag+1]-s[t[idx<<1].l-t[idx].tag];
	t[idx<<1|1].sum+=s[t[idx<<1|1].r-t[idx].tag+1]-s[t[idx<<1|1].l-t[idx].tag];
	t[idx<<1].sum%=mod;t[idx<<1|1].sum%=mod;
	return;
}

void changetree(int x,int y,int po,int idx){
	int l=t[idx].l;int r=t[idx].r;
	if (t[idx].tag!=-1) pushdown(idx);
	if (l==x && r==y){
		t[idx].sum+=s[r-po+1]-s[l-po];
		t[idx].sum%=mod;
		t[idx].tag=po;
		return;
	}
	int mid=(l+r)>>1;
	if (y<=mid) changetree(x,y,po,idx<<1);
		else if(x>mid) changetree(x,y,po,idx<<1|1);
		else {
		changetree(x,mid,po,idx<<1);
		changetree(mid+1,y,po,idx<<1|1);
	}
	update(idx);
	return;
}

int querytree(int x,int y,int idx){
	int l=t[idx].l;
	int r=t[idx].r;
	if (t[idx].tag!=-1) pushdown(idx);
	if (l==x && r==y) {
		return t[idx].sum%mod;
	}
	int mid=(l+r)>>1;
	if (y<=mid) return querytree(x,y,idx<<1)%mod;
		else if (x>mid) return querytree(x,y,idx<<1|1)%mod;
		else{
			return (querytree(x,mid,idx<<1)+querytree(mid+1,y,idx<<1|1))%mod;
		}
}

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	f[0]=0;f[1]=1;
	s[0]=0;s[1]=1;
	for(int i=2;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2]) % mod;
		s[i]=(s[i-1]+f[i]) % mod;
	}
	scanf("%d%d",&n,&m);
	if (n<=1000){
		while (m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if (op==1){
			for(int i=l;i<=r;i++)
				a[i]=(a[i]+f[i-l+1])%mod;
		}
		if (op==2) {
			ans=0;
			for(int i=l;i<=r;i++)
				ans=(ans+a[i])%mod;
			printf("%d\n",ans);
		}
		}
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	buildtree(1,n,1);
	while (m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if (op==1) changetree(l,r,l,1);
		if (op==2) {
			ans=querytree(l,r,1);
			printf("%d\n",ans % mod);
		}
	}
	return 0;
}
