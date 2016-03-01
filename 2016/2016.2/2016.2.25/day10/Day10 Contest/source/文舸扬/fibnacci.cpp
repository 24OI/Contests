#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
inline int read()
{
	int res;
	char ch;
	for (ch = getchar (); ch < '0' || ch > '9'; ch = getchar ())
		;
	res = ch - '0';
	for (ch = getchar (); ch >= '0' && ch <= '9'; ch = getchar ())
		res = res * 10 + ch - '0';
	return res;
}
const long long mod = 1e9 + 1;
int n, a[100005], m;
long long f[100005], sum[100005], tree[400005];
inline void build (int l, int r, int k)
{
	if (l == r)
	{
		tree[k] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build (l, mid, k << 1);
	build (mid + 1, r, k << 1 | 1);
	tree[k] = (tree[k << 1] + tree[k << 1 | 1]) % mod;
}
inline void work (int l, int r, int x, int y, int k)
{
	if (r < x || l > y)
		return ;
	if (x <= l && r <= y)
	{
		tree[k] += sum[r - x + 1] - sum[l - x];
		tree[k] %= mod;
	}
	if (l == r)
		return ;
	int mid = (l + r) >> 1;
	work (l, mid, x, y, k << 1);
	work (mid + 1, r, x, y, k << 1 | 1);
	tree[k] = (tree[k << 1] + tree[k << 1 | 1]) % mod;
}
inline long long ask (int l, int r, int x, int y, int k)
{
	if (r < x || l > y)
		return 0;
	if (x <= l && r <= y)
		return tree[k];
	int mid = (l + r) >> 1;
	long long num = (ask (l, mid, x, y, k << 1) + ask (mid + 1, r, x, y, k << 1 | 1)) % mod;
	return num;
}
int main ()
{
	freopen ("fibnacci.in", "r", stdin);
	freopen ("fibnacci.out", "w", stdout);
	n = read();
	m = read();
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	for (int i = 1; i <= n; i++)
		sum[i] = (sum[i - 1] + f[i]) % mod;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build (1, n, 1);
	for (int i = 1; i <= m; i++)
	{
		int op, l, r;
		op = read();
		l = read();
		r = read();
		if (op == 1)
			work (1, n, l, r, 1);
		else
			printf ("%lld\n", ask (1, n, l, r, 1));
	}
	return 0;
}