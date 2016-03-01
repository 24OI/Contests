#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
typedef long long LL;
const LL p = 1e9 + 1;
const LL maxn = 4444444;
LL n, m;
LL op, l, r;
LL a[1111111];
LL tree[maxn], mrka[maxn], mrkb[maxn];
LL cz[3];
class Matrix {
public:
	LL n, m;
	LL a[3][3];
	void clear() {
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	Matrix operator %(const LL p) const {
		Matrix tmp;
		tmp.n = n, tmp.m = m;
		for (LL i = 1; i <= n; ++i)
			for (LL j = 1; j <= m; ++j)
				tmp.a[i][j] = a[i][j] % p;
		return tmp;
	}
	Matrix operator *(const Matrix &b) const {
		Matrix tmp;
		tmp.clear();
		tmp.n = n, tmp.m = b.m;
		for (LL i = 1; i <= n; ++i)
			for (LL j = 1; j <= b.m; ++j)
				for (LL k = 1; k <= m; ++k) {
					tmp.a[i][j] += (a[i][k] * b.a[k][j]) % p;
					tmp.a[i][j] %= p;
				}
		return tmp % p;
	}
};

void Buildtree(LL l, LL r, LL num);
LL query(LL ql, LL qr, LL nowl, LL nowr, LL num);
inline LL update(LL ql, LL qr, LL nowl, LL nowr, LL num, LL delta1, LL delta2);
LL solve(LL b[], LL n, LL t, LL p);
LL get(LL a, LL b, LL n);
void pushdown(LL num, LL l);

int main() {
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (LL i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	n = LL(pow(2, ceil(log2(n))));
	Buildtree(1, n, 1);
	for (; m; m--) {
		scanf("%lld%lld%lld", &op, &l, &r);
		if (op == 1) {
			update(l, r, 1, n, 1, 1, 1);
		} else {
			printf("%lld\n", query(l, r, 1, n, 1));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline void Buildtree(LL l, LL r, LL num) {
	if (l == r) {
		tree[num] = a[l] % p;
		mrka[num] = mrkb[num] = 0;
		return;
	}
	Buildtree(l, l + r >> 1, num << 1);
	Buildtree((l + r >> 1) + 1, r, num << 1 | 1);
	tree[num] = (tree[num << 1] + tree[num << 1 | 1]) % p;
	return;
}

inline LL query(LL ql, LL qr, LL nowl, LL nowr, LL num) {
    if (ql > nowr || nowl > qr) return 0;
	if (ql <= nowl && nowr <= qr) {
		return tree[num];
	}
    if (mrka[num] != 0) pushdown(num, nowr-nowl + 1);
    return (query(ql, qr, nowl, (nowl + nowr >> 1), num << 1) + query(ql, qr, (nowl + nowr >> 1) + 1, nowr, num << 1 | 1)) % p;
}

inline LL solve(LL b[], LL n, LL t, LL p) {
	Matrix M, F, E;
	F.n = M.n = M.m = E.n = E.m = n;
	F.m = 1;
	for (LL i = 1; i < n; ++i) M.a[i][i + 1] = 1;
	for (LL i = 1; i <= n; ++i) {
		M.a[n][i] = 1;
		F.a[i][1] = b[i] % p;
		E.a[i][i] = 1;
	}
	if (t <= n) return b[t] % p;
	for (t -= n; t; t >>= 1) {
		if (t & 1) E = (M * E) % p;
		M = (M * M) % p;
	}
	F = (E * F) % p;
	return F.a[n][1];
}

inline LL get(LL a, LL b, LL n) {
	cz[1] = a % p, cz[2] = b % p;
	return solve(cz, 2, n, p);
}

inline LL update(LL ql, LL qr, LL nowl, LL nowr, LL num, LL delta1, LL delta2) {
	LL tmp;
    if (ql > nowr || nowl > qr) return 0;
    if (ql <= nowl && nowr <= qr) {
        tree[num] = (( tree[num] + get(delta1, delta2, nowr-nowl + 3) - delta2 )% p + p) % p;
        mrka[num] = ( mrka[num] + delta1 ) % p;
        mrkb[num] = ( mrkb[num] + delta2 ) % p;
        return nowr - nowl + 1;
    }
    if (mrka[num] != 0) pushdown(num, nowr-nowl + 1);
    if (ql > nowr + nowl >> 1) {
    	tmp = update(ql, qr, (nowl + nowr >> 1) + 1, nowr, num << 1 | 1, delta1, delta2);
    } else if (qr <= nowr + nowl >> 1) {
    	tmp = update(ql, qr, nowl, (nowl + nowr >> 1), num << 1, delta1, delta2);
    } else {
    	tmp = update(ql, qr, nowl, (nowl + nowr >> 1), num << 1, delta1, delta2);
    	tmp += update(ql, qr, (nowl + nowr >> 1) + 1, nowr, num << 1 | 1, get(delta1, delta2, tmp + 1), get(delta1, delta2, tmp + 2));
	}
    tree[num] = ( tree[ num << 1 ] + tree[ num << 1 | 1 ] ) % p;
    return tmp;
}

inline void pushdown(LL num, LL l) {
	mrka[num << 1] += mrka[num];
	mrkb[num << 1] += mrkb[num];
	mrka[num << 1 | 1] += get(mrka[num], mrkb[num], l / 2 + 1);
	mrkb[num << 1 | 1] += get(mrka[num], mrkb[num], l / 2 + 2);
	tree[num << 1] = ((tree[num << 1] + get(mrka[num], mrkb[num], l / 2 + 2) - mrkb[num]) % p + p) % p;
	tree[num << 1 | 1] = ((tree[num << 1 | 1] + get(mrka[num], mrkb[num], l + 2) - get(mrka[num], mrkb[num], l / 2 + 2)) % p + p) % p;
	mrka[num] = mrkb[num] = 0;
	return;
}
