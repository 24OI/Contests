#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3009, INF = 0x3f3f3f3f;

int map[MAXN][MAXN];

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	memset(map, 0x3f, sizeof(map));
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		map[x][y] = z;
		map[y][x] = z;
		map[i][i] = 0;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	scanf("%d", &m);
	for (int t = 1; t <= m; ++t){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int ans = 0;
		for (int i = a; i <= b; ++i)
			for (int j = c; j <= d; ++j)
				if (map[i][j] > ans) ans = map[i][j];
		printf("%d\n", ans);
	}
	return 0;
}
