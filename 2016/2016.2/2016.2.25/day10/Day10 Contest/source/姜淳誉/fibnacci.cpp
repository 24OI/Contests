#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define MAXN 100010
#define MAXM 100010
#define INF 1000000000
#define MOD 1000000001
#define eps 1e-8
#define ll long long
int n,m;
int a[MAXN];
int v[MAXN*4];
int f[MAXN];
vector<pair<int,int> >ch[MAXN*4];
inline void ud(int x){
	v[x]=v[x<<1]+v[x<<1|1];
	v[x]%=MOD;
}
void build(int x,int y,int z){
	if(y==z){
		v[x]=a[y];
		if(v[x]<0){
			v[x]+=MOD;
		}
		return ;
	}
	int mid=y+z>>1;
	build(x<<1,y,mid);
	build(x<<1|1,mid+1,z);
	ud(x);
}
inline void toch(int x,int l,int r){
	v[x]+=f[r]-f[l-1];
	if(v[x]<0){
		v[x]+=MOD;
	}
	v[x]%=MOD;
	if(l!=r){
		ch[x].push_back(make_pair(l,r));
	}
}
inline void pd(int x){
	int i,y,z;
	int sz=ch[x].size();
	for(i=0;i<sz;i++){
		y=ch[x][i].first;
		z=ch[x][i].second;
		int mid=y+z>>1;
		toch(x<<1,y,mid);
		toch(x<<1|1,mid+1,z);
	}
	ch[x].clear();
}
void change(int x,int y,int z,int l,int r,int cl,int cr){
	if(y==l&&z==r){
		toch(x,cl,cr);
		return ;
	}
	pd(x);
	int mid=y+z>>1;
	if(r<=mid){
		change(x<<1,y,mid,l,r,cl,cr);
	}else if(l>mid){
		change(x<<1|1,mid+1,z,l,r,cl,cr);
	}else{
		change(x<<1,y,mid,l,mid,cl,cl+mid-l);
		change(x<<1|1,mid+1,z,mid+1,r,cl+mid-l+1,cr);
	}
	ud(x);
}
int ask(int x,int y,int z,int l,int r){
	if(y==l&&z==r){
		return v[x];
	}
	pd(x);
	int mid=y+z>>1;
	if(r<=mid){
		return ask(x<<1,y,mid,l,r);
	}else if(l>mid){
		return ask(x<<1|1,mid+1,z,l,r);
	}else{
		return (ask(x<<1,y,mid,l,mid)+ask(x<<1|1,mid+1,z,mid+1,r))%MOD;
	}
}
int main(){
	int i,j,o,x,y;
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1]=f[2]=1;
	for(i=3;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%MOD; 
	}
	for(i=1;i<=n;i++){
		f[i]+=f[i-1];
		f[i]%=MOD;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]%=MOD;
	}
	build(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			change(1,1,n,x,y,1,y-x+1);
		}else{
			printf("%d\n",ask(1,1,n,x,y));
		}
	}
	return 0;
}

/*

*/
