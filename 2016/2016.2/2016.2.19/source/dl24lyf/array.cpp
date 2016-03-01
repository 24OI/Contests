#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
const int maxn = 10001111;
int n, ans = INT_MIN;
int a[maxn], k[maxn];
inline int Read();
inline int calc(int);
int main() {
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	n = Read();
	//printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) a[i] = Read();
	for (int i = 1; i <= n; ++i) {
		k[i] = calc(i);
		//printf("%d ", k[i]);
	}
	//puts("");
	for (int i = 1; i <= n; ++i) ans = std::max(ans, a[i] - k[i] + 1);
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline int calc(int n) {
	int rtn = n, max = a[n], min = a[n];
	for (int i = n - 1; i > 0; --i) {
		if (a[i] > a[n]) break;
		if (a[i] < min) {
			min = a[i];
			rtn = i;
		}
	}
	return rtn;
}

inline int Read() {
	char ch = getchar();
	int data = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	do {
		data = data * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return data;
}
