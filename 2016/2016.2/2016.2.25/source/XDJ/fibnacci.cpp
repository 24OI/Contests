#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define x1 x11
#define y1 y11
#include <vector>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MOD = int(1e9) + 1;

int n, m;
int op, l, r;
LL a[100033];
LL fib[100033];
LL prefix[100033];
void init() {
	fib[0] = 0; fib[1] = 1;
	g(i, 2, 100000) (fib[i] = fib[i - 1] + fib[i - 2]) %= MOD;
	g(i, 1, 100000) (prefix[i] = prefix[i - 1] + fib[i]) %= MOD;
	// get the prefix sums
}
LL res = 0;
void novice() {
	init();
	g(i, 1, n) scanf("%lld", a + i);
	f(i, 0, m) {
		scanf("%d%d%d", &op, &l, &r);
		// g(i, 1, n) printf("%lld ", a[i]); puts("");
		if (op == 1) {
			g(i, l, r) (a[i] += fib[i - l + 1]) %= MOD;
		} else {
			res = 0;
			g(i, l, r) (res += a[i]) %= MOD;
			printf("%lld\n", res);
		}
	}
}
int pos[100033], sz;
std::vector<LL> cover[10033];
LL sum[10033];
int lp, rp;
int ll, rr;
int L;
void solveUpd() {
	lp = pos[l]; rp = pos[r];
	if (lp == rp) {
		g(i, l, r) (a[i] += fib[i - l + 1]) %= MOD;
		return;
	}
	ll = l % sz; rr = r % sz;
	L = l;
	// puts("= =");
	if (rr) {
		while (r >= 1 && r % sz) {
			(a[r] += fib[r - L + 1]) %= MOD;
			--r;
		}
		// a[r] += fib[r - L + 1]; --r; --rr;
	}
	if (ll != 1) {
		while (l <= n && l % sz != 1) {
			(a[l] += fib[l - L + 1]) %= MOD;
			++l;
		}
	}
	g(i, pos[l], pos[r]) {
		cover[i].push_back(i * sz + 1 - L + 1);
		(sum[i] += prefix[(i + 1) * sz - L + 1] - prefix[i * sz - L + 1] + MOD) %= MOD;
	}
}
int left;
LL solveSum() {
	// g(i, 1, n) printf("%d ", a[i]); puts("");
	res = 0LL;
	lp = pos[l]; rp = pos[r];
	ll = l % sz; rr = r % sz;
	if (lp == rp) {
		f(i, 0, cover[lp].size()) {
			// printf("[(%d, %d), %d:%d %d]\n", ll, rr, cover[lp][i], cover[lp][i] + (rr?rr:sz) - 1, cover[lp][i] + (ll?ll:sz) - 2);
			(res += prefix[ cover[lp][i] + (rr?rr:sz) - 1 ] - prefix[ cover[lp][i] + (ll?ll:sz) - 2 ] + MOD) %= MOD;
		}
		g(i, l, r) (res += a[i]) %= MOD;
		return res;
	}
	L = l;
	if (rr) {
		f(i, 0, cover[rp].size()) {
			(res += prefix[ cover[rp][i] + rr - 1 ] - prefix[ cover[rp][i] - 1 ] + MOD) %= MOD;
		}
		while (r >= 1 && r % sz) {
			(res += a[r]) %= MOD;
			// (a[r] += fib[r - L + 1]) %= MOD;
			--r;
		}
	}
	if (ll != 1) {
		// left = sz - ll + 1;
		f(i, 0, cover[lp].size()) {
			// printf("`%d`\n", cover[lp][i]);
			(res += prefix[ cover[lp][i] + sz - 1 ] - prefix[ cover[lp][i] + (ll?ll:sz) - 2 ] + MOD) %= MOD;
		}
		while (l <= n && l % sz != 1) {
			(res += a[l]) %= MOD;
			// (a[l] += fib[l - L + 1]) %= MOD;
			++l;
		}
	}
	if (l > r) return res;
	g(i, pos[l], pos[r]) {
		(res += sum[i]) %= MOD;
		// cover[i].push_back(i * sz + 1 - L + 1);
		// (sum[i] += prefix[(i + 1) * sz - L + 1] - prefix[i * sz - L + 1] + MOD) %= MOD;
	}
	return res;
}
void moderate() {
	init();
	sz = sqrt(n * log(n));
	if (sz > n) sz = n;
	// printf("sz:%d\n", sz);
	g(i, 1, n) {
		scanf("%lld", a + i);
		pos[i] = (i - 1) / sz;
		(sum[ pos[i] ] += a[i]) %= MOD;
	}
	f(i, 0, m) {
		scanf("%d%d%d", &op, &l, &r);
		// g(i, 1, n) printf("%lld ", a[i]); puts("");
		if (op == 1) {
			solveUpd();
			// g(i, l, r) (a[i] += fib[i - l + 1]) %= MOD;
		} else {
			// sum = 0;
			// g(i, l, r) (sum += a[i]) %= MOD;
			printf("%lld\n", solveSum());
		}
	}
}
int main() {
#ifndef LOCAL
  freopen("fibnacci.in", "r", stdin);
  freopen("fibnacci.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  // moderate();
  // return 0;
  if (n <= 40000) {
  	novice();
  } else {
  	moderate();
  }

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

/*
5 2
0 0 0 0 0
1 1 4
2 2 5

5 2
0 0 0 0 0
1 1 4
2 1 1

10 1024
0 0 0 0 0 0 0 0 0 0
1 1 10

10 1024
0 0 0 0 0 0 0 0 0 0
1 1 10
2 2 2
1 2 4
2 2 4
 */
