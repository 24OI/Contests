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
const long long mod = 593119681;
int n, t;
long long a[(1 << 18) + 1], b[(1 << 18) + 1];
inline long long qpow (int a, int b)
{
	long long sum = 1;
	while (b)
	{
		if (b & 1)
			sum = sum * a % mod;
		a = (long long)a * a % mod;
		b >>= 1;
	}
	return sum;
}
int main ()
{
	freopen ("monster.in", "r", stdin);
	freopen ("monster.out", "w", stdout);
	n = read();
	t = read();
	for (int i = 0; i < (1 << n); i++)
		a[i] = (long long) read();
	for (int s = 1; s <= t; s++)
	{
		for (int i = 0; i < (1 << n); i++)
		{
			long long tot = 0;
			for (int j = 0; j < n; j++)
				tot = (tot + a[i ^ (1 << j)]) % mod;
			b[i] = (a[i] + tot) % mod;
		}
		for (int i = 0 ; i < (1 << n); i++)
			a[i] = b[i];
	}
	for (int i = 0; i < (1 << n); i++)
		printf ("%lld ", b[i]);
	printf ("\n");
	return 0;
}