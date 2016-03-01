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
struct node
{
	double a, b, c;
}a[1005];
struct point
{
	double x, y;
};
map <long long, int> mp;
int n, sum, ans;
inline void work (int s, int t)
{
	point now;
	long long zy;
	now.y = (a[t].a * a[s].c - a[s].a * a[t].c) / (a[s].a * a[t].b - a[t].a * a[s].b);
	now.x = (a[t].b * a[s].c - a[s].b * a[t].c) / (a[s].b * a[t].a - a[t].b * a[s].a);
	zy = (long long)now.x * 1e10 + (long long)now.y;
	mp[zy] ++;
	if (mp[zy] > ans)
	{
		ans = mp[zy];
		sum = 1;
	}
	else if (mp[zy] == ans)
		sum++;
}
int main ()
{
	freopen ("star.in", "r", stdin);
	freopen ("star.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].a = (double)read();
		a[i].b = (double)read();
		a[i].c = (double)read();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
			work (i, j);
	}
	printf ("%d %d\n", ans + 1, sum);
	return 0;
}