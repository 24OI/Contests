#include <cstdio>
typedef long long int LL;
const LL MOD = 1000000001LL;
const int base[3][3] = {
	{1, 1, 0},
	{1, 0, 0},
	{1, 1, 1}
}, MAXN = 100005;

struct sgtNode{
	int sum, f0, f1;
}tr[MAXN << 2];
int n, m, exp[MAXN][3][3], ql, qr, val[MAXN];

void sgtInit(int x, int l, int r){
	if(l == r){
		tr[x].sum = val[r] % MOD;
		return;
	} int mid = (l + r) >> 1;
	sgtInit(x << 1, l, mid);
	sgtInit(x << 1 | 1, mid + 1, r);
	tr[x].sum = (tr[x << 1].sum + tr[x << 1 | 1].sum) % MOD;
}
void mul(int x[3][3], const int pre[3][3]){
	int i, j, k;
	for(i = 0; i < 3; ++ i)
		for(j = 0; j < 3; ++ j)
			for(k = 0; k < 3; ++ k)
				x[i][j] = (x[i][j] + LL(pre[i][k]) * base[k][j]) % MOD;
}
int getFib(int f0, int f1, int p){
	int i, ret = 0, tmp[3] = {f1, f0, f1};
	for(i = 0; i < 3; ++ i)
		ret = (ret + LL(exp[p - 1][0][i]) * tmp[i]) % MOD;
	return ret;
}
int getSum(int f0, int f1, int p){
	int i, ret = 0, tmp[3] = {f1, f0, f1};
	for(i = 0; i < 3; ++ i)
		ret = (ret + LL(exp[p - 1][2][i]) * tmp[i]) % MOD;
	return ret;
}
inline void update(int &a, int b){a += b; if(a >= MOD) a -= MOD;}
void add(int x, int l, int r, int f0, int f1){
	update(tr[x].sum, getSum(f0, f1, r - l + 1));
	update(tr[x].f0, f0);
	update(tr[x].f1, f1);
}
void pushDown(int x, int l, int r){
	if(tr[x].f0 || tr[x].f1){
		int mid = (l + r) >> 1;
		add(x << 1, l, mid, tr[x].f0, tr[x].f1);
		add(x << 1 | 1, mid + 1, r, getFib(tr[x].f0, tr[x].f1, mid + 1 - l), getFib(tr[x].f0, tr[x].f1, mid + 2 - l));
		tr[x].f0 = tr[x].f1 = 0;
	}
}
void sgtUpdate(int x, int l, int r){
	if(l >= ql && r <= qr){
		add(x, l, r, getFib(0, 1, l - ql), getFib(0, 1, l - ql + 1));
		return;
	} pushDown(x, l, r);
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x << 1, l, mid);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r);
	tr[x].sum = (tr[x << 1].sum + tr[x << 1 | 1].sum) % MOD;
}
int sgtQuery(int x, int l, int r){
	if(l >= ql && r <= qr) return tr[x].sum;
	pushDown(x, l, r); int mid = (l + r) >> 1;
	if(qr <= mid) return sgtQuery(x << 1, l, mid);
	if(ql > mid) return sgtQuery(x << 1 | 1, mid + 1, r);
	return (sgtQuery(x << 1, l, mid) + sgtQuery(x << 1 | 1, mid + 1, r)) % MOD;
}
int main(){
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	int i, op;
	for(i = 0; i < 3; ++ i) exp[0][i][i] = 1;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		mul(exp[i], exp[i - 1]);
		scanf("%d", &val[i]);
	}
	sgtInit(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &op, &ql, &qr);
		if(op == 1){//Modify
			sgtUpdate(1, 1, n);
		}else{//Query
			printf("%d\n", sgtQuery(1, 1, n));
		}
	}
	return 0;
}
