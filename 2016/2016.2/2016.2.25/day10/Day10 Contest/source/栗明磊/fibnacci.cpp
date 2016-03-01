#include<cstdio>
#include<queue>
#include<vector>
#define MOD 1000000001
using namespace std;
int maxf,n,m;
int a[100010],fib[100010];
struct qw{
	int l,r;
};
struct node{
	int l,r,w,lazy;
}tr[500000];
void pushdown(int i){
	if(tr[i].lazy){
		tr[i<<1].w=(tr[i<<1].w+tr[i].lazy*(fib[tr[i<<1].r+2]-fib[tr[i<<1].l+1]))%MOD;
		tr[(i<<1)|1].w=(tr[(i<<1)|1].w+tr[i].lazy*(fib[tr[(i<<1)|1].r+2]-fib[tr[(i<<1)|1].l+1]))%MOD;
		tr[i<<1].lazy+=tr[i].lazy;
		tr[(i<<1)|1].lazy+=tr[i].lazy;
		tr[i].lazy=0;
	}
}
void pushup(int i){
	tr[i].w=(tr[i<<1].w+tr[(i<<1)|1].w)%MOD;
}
void build(int l,int r,int i){
	tr[i].l=l;tr[i].r=r;
	if(l==r){tr[i].w=a[l];return;}
	int mid = (l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,(i<<1)|1);
	pushup(i);
}
int query(int l,int r,int i){
	if(tr[i].l>=l&&tr[i].r<=r)return tr[i].w;
	pushdown(i);
	if(r<=tr[i<<1].r)return query(l,r,i<<1);
	if(l>=tr[(i<<1)|1].l)return query(l,r,(i<<1)|1);
	return (query(l,r,i<<1)+query(l,r,(i<<1)|1))%MOD;
}
void modify(int l,int r,int i){
	if(tr[i].l>=l&&tr[i].r<=r){
		tr[i].w=(tr[i].w+fib[tr[i].r+2]-fib[tr[i].l+1])%MOD;
		tr[i].lazy++;
		return;
	}
	pushdown(i);
	if(r<=tr[i<<1].r)modify(l,r,i<<1);else
	if(l>=tr[(i<<1)|1].l)modify(l,r,(i<<1)|1);else
	{modify(l,r,i<<1);modify(l,r,(i<<1)|1);}
	pushup(i);
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,n,1);
	fib[1]=1,fib[2]=1;
	for(int i=3;i<=n+10;i++)fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int op,l,r;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&l,&r);
		switch(op){
			case 1:
				modify(l,r,1);
				break;
			case 2:
				printf("%d\n",query(l,r,1));
				break;
		}
	}
}
