#include <cstdio>
const int mod = 593119681;
int sons[30], n, t, N;
int newarr[300044], lstarr[300044];
inline int read() {
	int ret = 0; char c = getchar();
	while ( c < '0' || '9' < c ) c = getchar();
	while ('0' <= c && c <= '9') { ret = ret * 10 - '0' + c; c = getchar(); }
	return ret;
}
int main () {
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	n = read(); t = read();
	N = (1 << n);
	sons[0] = 1;
	for (int i = 1; i < n; ++i)
		sons[i] = (sons[i - 1] << 1);
	for (int i = 0; i < N; ++i)
		lstarr[i] = read();
	int tmp;
	int *now = newarr, *lst = lstarr, *ttt;
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < N; ++j) {
			now[j] = lst[j];
			for (int k = 0; k < n; ++k) {
				tmp = sons[k] ^ j;
				now[j] = (now[j] + lst[tmp]) % mod;
			}
		}
		ttt = now; now = lst; lst = ttt;
	}
	for (int i = 0; i < N; ++i)
		printf("%d ", lst[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
