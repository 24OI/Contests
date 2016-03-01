#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
typedef long long LL;
using namespace std;
const int N = 100010, mod = 1000000000 + 1;
struct mat{
	int a[2][2];
};
mat operator * (mat a, mat b){
	mat c;
	rep(i,0,1) rep(j,0,1){
		LL w = 0;
		rep(k,0,1) w += 1LL * a.a[i][k] * b.a[k][j];
		c.a[i][j] = w % mod;
	}		
	return c;
}
mat operator + (mat a, mat b){
	mat c;
	rep(i,0,1) rep(j,0,1) c.a[i][j] = (a.a[i][j] + b.a[i][j]) % mod;
	return c;
}

mat pw[N], s[N], A;
int sum[N * 4], a[N];
typedef pair<int, int> node;
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
node tag[N * 4];
node operator + (const node &a, const node &b){
	return mp((a.first + b.first) % mod, (a.second + b.second) % mod);
}
mat R;
node mult(node t, int l){
	R.a[0][0] = t.x, R.a[1][0] = t.y, R.a[0][1] = 0, R.a[1][1] = 0;
	R = pw[l] * R;
	return mp(R.a[0][0], R.a[1][0]);
}
int S(node t, int l){
	R.a[0][0] = t.x, R.a[1][0] = t.y, R.a[0][1] = 0, R.a[1][1] = 0;
	R = s[l - 1] * R;
	return R.a[0][0];
}
#undef x
void upd(int x){
	sum[x] = (sum[x << 1] + sum[(x << 1) + 1]) % mod;
}
void build(int x, int l, int r){
	if (l == r) sum[x] = a[l] % mod;
	else {
		int mid = (l + r) >> 1, lc = x << 1, rc = (x << 1) + 1;
		build(lc, l, mid), build(rc, mid + 1, r);
		upd(x);
	}
}
void push(int x, int l, int r){
	if (tag[x] != mp(0, 0)){
		//cout <<x<<' '<<l<<' '<<r<<' '<<tag[x].first<<' '<<tag[x].second<<endl;
		if (l < r){
			int mid = (l + r) >> 1, lc = x << 1, rc = (x << 1) + 1;
			tag[lc] = tag[lc] + tag[x];
			tag[rc] = tag[rc] + mult(tag[x], mid - l + 1);
		}
		sum[x] += S(tag[x], r - l + 1), sum[x] %= mod;
		tag[x] = mp(0, 0);
	}
}
void add(int x, int l, int r, int a, int b, node d){
	if (a <= l && r <= b) tag[x] = tag[x] + mult(d, l - a), push(x, l, r);
	else {
		push(x, l, r);
		int mid = (l + r) >> 1, lc = x << 1, rc = (x << 1) + 1;
		if (a <= mid) add(lc, l, mid, a, b, d); else push(lc, l, mid);
		if (b >  mid) add(rc, mid + 1, r, a, b, d); else push(rc, mid + 1, r);
		upd(x);
	}
}
int qry(int x, int l, int r, int a, int b){
	push(x, l, r);
	if (a <= l && r <= b) return sum[x];
	else {
		int mid = (l + r) >> 1, lc = x << 1, rc = (x << 1) + 1, ans = 0;
		if (a <= mid) ans += qry(lc, l, mid, a, b);
		if (b >  mid) ans += qry(rc, mid + 1, r, a, b), ans %= mod;
		return ans;
	}
}
void print(int x, int l, int r){
	cout <<"x = "<<x<<" l = "<<l<<" r = "<<r<<" s = "<<sum[x]<<" tag = ("<<tag[x].first<<","<<tag[x].second<<")"<<endl;
	if (l < r){
		int mid = (l + r) >> 1, lc = x << 1, rc = (x << 1) + 1;
		print(lc, l, mid), print(rc, mid + 1, r);
	}
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int n, m; scanf("%d%d",&n,&m);
	pw[0].a[0][0] = pw[0].a[1][1] = 1;
	pw[0].a[1][0] = pw[0].a[0][1] = 0;
	A.a[0][0] = A.a[0][1] = A.a[1][0] = 1, A.a[1][1] = 0;
	s[0] = pw[0];
	rep(i,1,n) pw[i] = pw[i - 1] * A, s[i] = s[i - 1] + pw[i];	
	rep(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	rep(i,1,m){
		int op, l, r; scanf("%d%d%d",&op,&l,&r);
		if (op == 1) add(1, 1, n, l, r, mp(1, 0));
		else printf("%d\n",qry(1, 1, n, l, r));
		//print(1,1,n); cout <<endl;
	}
	return 0;
}
