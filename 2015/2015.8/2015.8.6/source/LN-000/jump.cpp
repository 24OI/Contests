#include <cstdio>
#include <cstring>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
const int MOD = 1000000007;

int n, a, b, k;
int dp[2007], ndp[2007];

int main(){
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	scanf("%d%d%d%d", &n, &a, &b, &k);
	memset(dp, 0, sizeof(dp));
	dp[a] = 1;
	while(k--){
		memset(ndp, 0, sizeof(ndp));
		f(i, 1, n) if(i < b){
			int lef = 2 * i - b + 1;
			if(lef < 1) lef = 1;
			(ndp[lef] += dp[i]) %= MOD;
			(ndp[i] += MOD - dp[i]) %= MOD;
			(ndp[i + 1] += dp[i]) %= MOD;
			(ndp[b] += MOD - dp[i]) %= MOD;
		}else if(i > b){
			int rig = 2 * i - b;
			if(rig > n + 1) rig = n + 1;
			(ndp[b + 1] += dp[i]) %= MOD;
			(ndp[i] += MOD - dp[i]) %= MOD;
			(ndp[i + 1] += dp[i]) %= MOD;
			(ndp[rig] += MOD - dp[i]) %= MOD;
		}
		dp[1] = ndp[1];
		f(i, 2, n) (dp[i] = dp[i - 1] + ndp[i]) %= MOD;
	}
	int ans = 0;
	f(i, 1, n) (ans += dp[i]) %= MOD;
	printf("%d\n", ans);
	return 0;
}
