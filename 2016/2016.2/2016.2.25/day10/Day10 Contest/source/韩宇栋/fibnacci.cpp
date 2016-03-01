#include <cstdio>
const int mod = 1000000001;
int fib[100005], n, m, a[100005];
inline int read() {
	int ret = 0; char c = getchar();
	while ( c < '0' || '9' < c ) c = getchar();
	while ('0' <= c && c <= '9') { ret = ret * 10 - '0' + c; c = getchar(); }
	return ret;
}
int main() {
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	n = read(); m = read();
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 100000; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	for (int i = 1; i <= n; ++i)
		a[i] = read() % mod;
	int op, l, r, ans;
	while (m--) {
		op = read(); l = read(); r = read();
		if (op & 1) for (int i = l; i <= r; ++i) a[i] = (a[i] + fib[i - l + 1]) % mod;
		else { ans = 0; for (int i = l; i <= r; ++i) ans = (ans + a[i]) % mod; printf("%d\n", ans); }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}