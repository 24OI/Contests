#include <cstdio>
#include <cstring>
#include <cstdlib>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int T;
int n, m, p;
inline int d(int x) {
	int res = 0;
	g(i, 2, x) {
		while (x % i == 0) {
			x /= i; ++res;
		}
		if (i > x) break;
	}
	if (x != 1) ++res;
	return res;
}
int gcd(int x, int y) {
	if (y) return gcd(y, x % y);
	return x;
}
int phi[500033];
void novice() {
	int res = 0;
	g(i, 1, n) g(j, 1, m) {
		if ((gcd(i, j) == 1)) ++res;
	}
	printf("%d\n", res);
	// int res;
	// phi[1] = 1;
	// g(i, 2, 500000) if (!phi[i]) {
	// 	phi[i] = i;
	// 	for (int j = i; j <= 500000; j += i) if (phi[j]) {
	// 		phi[j] = phi[j] / i * (i - 1);
	// 	} else {
	// 		phi[j] = i;
	// 	}
	// }
	// g(i, 1, 10) printf("%d ", phi[i]); puts("");
	// g(i, 1, 10) {
	// 	res = 0;
	// 	g(j, 1, i) if (gcd(i, j) == 1) ++res;
	// 	printf("%d ", res);
	// }
	// puts("");
	// printf("%d\n", res);
}
void solve() {
	if (p == 0) {
		novice();
		return;
	}
	int res = 0;
	g(i, 1, n) g(j, 1, m) {
		if (d(gcd(i, j)) <= p) ++res;
	}
	printf("%d\n", res);
}
int main() {
#ifndef LOCAL
  freopen("field.in", "r", stdin);
  freopen("field.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
  	scanf("%d%d%d", &n, &m, &p);
  	solve();
  }

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}
