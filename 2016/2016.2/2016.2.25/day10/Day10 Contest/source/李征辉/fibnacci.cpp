#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const long N= 100000 + 5, T= 280000, P= 1000000000 + 1;
long f[N], sum[N], a[T], n, m, i, j, k, t, q, p;
vector<long> l[T];

void build(long q, long p, long t){
	if(q==p){a[t]= k; return;}
	long mid= (q+p)/2;
	if(i>mid) build(mid+1, p, t<<1|1); else build(q, mid, t<<1);
	a[t]= (a[t<<1|1]+a[t<<1])% P;
}

void join(long q, long p, long t, long _q, long _p, long _l){
	long mid= (q+p)/2;
	while(!l[t].empty()){
		long k= l[t][l[t].size()-1];
		a[t]= (a[t]+sum[k+p-q]-sum[k-1])% P;
		if(q != mid) l[t<<1].push_back(k); else a[t<<1]= (a[t<<1]+f[k])% P;
		if(p != (mid+1)) l[t<<1|1].push_back(k+mid-q+1); else a[t<<1|1]= (a[t<<1|1]+f[k+p-q])% P;
		l[t].pop_back();
	}
	if((q==_q) && (p==_p)){
		if(q==p) a[t]= (a[t]+f[_l])% P;
		else l[t].push_back(_l);
		return;
	}
	a[t]= (a[t]+sum[_l+_p-_q]-sum[_l-1])% P;
	if(_p<=mid) join(q, mid, t<<1, _q, _p, _l); else
	if(_q>mid) join(mid+1, p, t<<1|1, _q, _p, _l); else{
		join(q, mid, t<<1, _q, mid, _l);
		join(mid+1, p, t<<1|1, mid+1, _p, _l+mid+1-_q);
	}
}

long find(long q, long p, long t, long _q, long _p){
	long mid= (q+p)/2;
	while(!l[t].empty()){
		long k= l[t][l[t].size()-1];
		a[t]= (a[t]+sum[k+p-q]-sum[k-1])% P;
		if(q != mid) l[t<<1].push_back(k); else a[t<<1]= (a[t<<1]+f[k])% P;
		if(p != (mid+1)) l[t<<1|1].push_back(k+mid-q+1); else a[t<<1|1]= (a[t<<1|1]+f[k+p-q])% P;
		l[t].pop_back();
	}
	if((q==_q) && (p==_p)) return a[t];
	if(_p<=mid) return find(q, mid, t<<1, _q, _p); else
	if(_q>mid) return find(mid+1, p, t<<1|1, _q, _p); else{
		long ans=find(q, mid, t<<1, _q, mid);
		ans= (ans+find(mid+1, p, t<<1|1, mid+1, _p))% P;
		return ans;
	}
}

int main(){
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	scanf("%ld%ld", &n, &m);
	memset(l, 0, sizeof(l));
	f[0]= 0; f[1]= 1; sum[0]= 0; sum[1]= 1;
	for(i= 2; i<=n; i++){f[i]= (f[i-1]+f[i-2])% P; sum[i]= (sum[i-1]+f[i])% P;}
	for(i= 1; i<=n; i++){
		scanf("%ld", &k);
		k= k % P;
		build(1, n, 1);
	}
	for(t= 0; t<m; t++){
		scanf("%ld%ld%ld", &k, &q, &p);
		if(k==1) join(1, n, 1, q, p, 1);
		else printf("%ld\n", find(1, n, 1, q, p));
	}
	return 0;
}

