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

#define N 1000005

int n, b[N], maxa[N];
long long ans;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; ++i)
		scanf("%d", &b[i]);
	for (int i = 2; i <= n; ++i)
		maxa[i] = max(maxa[i - 1], b[i - 1]);
	for (int i = 1; i <= n; ++i)
		++maxa[i];
	for (int i = 1; i < n; ++i)
		ans += max(b[i] - maxa[i], 0);
	if (ans >= 2) { puts("-1"); return 0; }
	else if (ans == 1) { puts("1"); return 0; }
	else for (int i = 1; i <= n; ++i)
		ans += maxa[i] - 1;
	cout << ans + 1 << endl;
	return 0;
}
