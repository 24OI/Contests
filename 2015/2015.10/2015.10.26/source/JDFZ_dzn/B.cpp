#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define N 4010

int n, m, k, s[N], t[N], h[N], a[N], val[N], ans, bel[N], in[N], out[N];
int p[N / 2], far[N / 2], f[N / 2][N / 2], vis[N / 2], maxf[N / 2];

map<int, int> mp;

int head[N];

struct graph
{
	int next, to, val;
	graph() {}
	graph(int _next, int _to, int _val)
	: next(_next), to(_to), val(_val) {}
} edge[N * 2];

inline void add(int x, int y, int z)
{
	static int cnt = 0;
	edge[++cnt] = graph(head[x], y, z);
	head[x] = cnt;
}

void dfs(int x, int fa)
{
	bel[x] = fa;
	for (int i = head[x]; i; i = edge[i].next)
		if (!bel[edge[i].to])
			dfs(edge[i].to, fa);
}

void dfs2(int x, int deep)
{
	// cout << x << endl;
	p[deep] = val[x], vis[x] = 1;
	for (int i = head[x]; i; i = edge[i].next)
	{
		if (!vis[edge[i].to])
			far[deep + 1] = edge[i].val, dfs2(edge[i].to, deep + 1);
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &s[i], &t[i]),
		h[i * 2 - 1] = s[i], h[i * 2] = t[i];
	sort(h + 1, h + 2 * n + 1);
	for (int i = 1; i <= n * 2; ++i)
		mp[h[i]] = i;
	for (int i = 1; i <= n; ++i)
		a[mp[s[i]]] = i, a[mp[t[i]]] = -i;
	ans += h[1]; ans += m - h[n * 2];
	for (int i = 1; i < n * 2; ++i)
		if (a[i] > 0 && a[i + 1] < 0)
		{
			if (a[i] == -a[i + 1])
				val[a[i]] += h[i + 1] - h[i];
			else
				add(a[i], -a[i + 1], h[i + 1] - h[i]),
				add(-a[i + 1], a[i], h[i + 1] - h[i]);
		}
		else if (a[i] > 0 && a[i + 1] > 0)
			val[a[i]] += h[i + 1] - h[i];
		else if (a[i] < 0 && a[i + 1] < 0)
			val[-a[i + 1]] += h[i + 1] - h[i];
		else if (a[i] < 0 && a[i + 1] > 0)
			ans += h[i + 1] - h[i];
	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if (!bel[i]) dfs(i, ++tot);
	for (int i = 1; i <= n; ++i)
		if (head[i] == 0)
			in[bel[i]] = i, out[bel[i]] = i;
		else if (edge[head[i]].next == 0)
		{
			if (in[bel[i]]) out[bel[i]] = i;
			else in[bel[i]] = i;
		}
	for (int i = 1; i < tot; ++i)
		add(out[i], in[i + 1], 0), add(in[i + 1], out[i], 0);
	dfs2(in[1], 1);
	// for (int i = 1; i <= n; ++i)
		// cout << p[i] << ' ' << far[i] << endl;
	for (int i = 1; i <= n; ++i)
	{
		f[i][1] = p[i];
		for (int j = 2; j <= k; ++j)
		{
			f[i][j] = f[i - 1][j - 1] + far[i] + p[i];
			f[i][j] = max(f[i][j], maxf[j - 1] + p[i]);
			maxf[j - 1] = max(maxf[j - 1], f[i - 1][j - 1]);
		}
	}
	for (int i = 1; i <= n; ++i)
		f[0][k] = max(f[0][k], f[i][k]);
	cout << ans + f[0][k] << endl;
	return 0;
}
