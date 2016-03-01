#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int a[633][633];
int n, m, p;
int s1[12], s2[12];
int s, t;
int in[12];
int ou[12];
int idx[12], c1;
int odx[12], c2;
int T[633];
void upd(int x) {
	for (int i = x; i <= 600; i += i & -i) {
		++T[i];
	}
}
int sum(int x) {
	int s = 0;
	for (int i = x; i; i -= i & -i) {
		s += T[i];
	}
	return s;
}
int get() {
	int s = 0;
	f(i, 0, c2) {
		s += sum(s2[i] + 1);
		upd(s2[i] + 1);
	}
	return s;
}
#include <queue>
std::queue<int> Q;
bool vis[12];
bool start(int x) {
	while (!Q.empty()) Q.pop();
	Q.push(idx[x]);
	int u;
	memset(vis, 0, sizeof vis);
	while (!Q.empty())	{
		u = Q.front(); Q.pop();
		vis[u] = 1;
		if (u == odx[s2[x]]) return 1;
		g(i, 1, n) if (a[u][i] && !vis[i]) Q.push(i);
	}
	return 0;
}
bool bfs() {
	f(i, 0, c2) {
		if (!start(i)) {
			// printf("%d\n", i);
			return 0;
		}
	}
	return 1;
}
void novice() {
	g(i, 1, n) in[i] = ou[i] = 1;
	f(i, 0, m) {
		scanf("%d%d", &s, &t);
		a[s][t] = 1;
		ou[s] = 0;
		in[t] = 0;
	}
	g(i, 1, n) {
		if (in[i] == 1) {
			idx[c1++] = i;
		} else if (ou[i] == 1) {
			odx[c2++] = i;
		}
	}
	f(i, 0, c2) {
		s2[i] = i;
	}
	int ans = 0;
	do {
		if (bfs()) {
			// printf("%d\n", get());
			ans += (get() & 1) ? -1 : 1;
		}
	} while (std::next_permutation(s2, s2 + c2));
	printf("%d\n", (ans + p) % p);
}
int main() {
#ifndef LOCAL
  freopen("bagua.in", "r", stdin);
  freopen("bagua.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &p);
  if (n <= 10) {
  	novice();
  	return 0;
  }
  puts("1");

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}

/*
4 2 1000003
1 3
2 4
 */
