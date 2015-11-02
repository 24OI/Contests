#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f, N = 109;

int map[N][N];
int dp[N][N][N][N];
int tow[N];

int main(){
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	memset(map, 0x3f, sizeof(map));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		map[i][i] = 0;
		//tow[i] = 1;
	}
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			scanf("%d", &map[i][j]);
	/*for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	*/
	dp[1][1][1][1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				for (int s = 1; s <= n; ++s){
				//if (tow[i]== 0 || tow[j] == 0 || tow[k] == 0){
					int a, b ,c;
					if (i == 1) a = INF;
					else a = dp[i - 1][j][k][s - 1] + map[i - 1][i];
					if (j == 1) b = INF;
					else b = dp[i][j - 1][k][s - 1] + map[j - 1][j];
					if (k == 1) c = INF;
					else c = dp[i][j][k - 1][s - 1] + map[k - 1][k];
					int tmp = min(min(a, b), c);
					if (tmp == a){
						if (!tow[i]){
							dp[i][j][k][s + 1] = tmp;
							tow[i] = 1;
						}
						else dp[i][j][k][s] = tmp;
					}
					else if (tmp == b){
						if (!tow[j]){
							dp[i][j][k][s + 1] = tmp;
							tow[j] = 1;
						}
						else dp[i][j][k][s] = tmp;
					}
					else {
						if (!tow[k]){
							dp[i][j][k][s + 1] = tmp;
							tow[k] = 1;
						}
						else dp[i][j][k][s] = tmp;
					}
				//}
				//else {
				}
	int ans = INF;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (dp[i][j][k][n] < ans) ans = dp[i][j][k][n];
	printf("%d\n", ans);
	return 0;
}
