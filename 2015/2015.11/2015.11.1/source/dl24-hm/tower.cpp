#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here\n")

int n;
int dis[110][110];
int dp[110][110][110];

int DP(int x, int y, int z)
{
	if (~dp[x][y][z]) return dp[x][y][z];
	int next = std::max(x, std::max(y, z)) + 1;
	if (next > n) return 0;
	return dp[x][y][z] = std::min(DP(next, y, z) + dis[x][next], std::min(DP(x, next, z) + dis[y][next], DP(x, y, next) + dis[z][next]));
}

int main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	
	scanf("%d", &n);
	int i, j;
	f(i, 1, n - 1) f(j, 1, n - i)
	{
		scanf("%d", &dis[i][i + j]);
		dis[i + j][i] = dis[i][i + j];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(1, 1, 1));
	
	return 0;
}
