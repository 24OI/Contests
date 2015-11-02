#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define x1 x11
#define y1 y11
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
 
#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
 
typedef long long LL;
typedef long double real;

double st,ed;
int n;
int map[133][133];
int dp[133][133][133][133];
void get(){
	int tee;
	int ans = ~0u >> 2;
	memset(dp,0x1f,sizeof dp);
	dp[1][1][1][1] = 0;
	// int cnt = 0;
	g(cur,2,n){
		f(i,1,cur)f(j,1,cur)f(k,1,cur)if (std::max(std::max(i,j),k) == cur - 1){
			tee = dp[cur - 1][i][j][k];
			dp[cur][i][j][cur] = std::min(dp[cur][i][j][cur],tee + map[k][cur]);
			dp[cur][i][cur][k] = std::min(dp[cur][i][cur][k],tee + map[j][cur]);
			dp[cur][cur][j][k] = std::min(dp[cur][cur][j][k],tee + map[i][cur]);
			// printf("%d %d %d %d %d %d %d\n",i,j,k,tee,dp[cur][i][j][cur],dp[cur][i][cur][k],dp[cur][cur][j][k]);
			if (cur == n){
				ans = std::min(ans,dp[cur][cur][j][k]);
				ans = std::min(ans,dp[cur][i][cur][k]);
				ans = std::min(ans,dp[cur][i][j][cur]);
			}
			// ++cnt;
			// printf("%d ",cur);
		}
		// puts("");
	}
	// printf("%d\n",cnt);
	printf("%d\n",ans);
}
int main(){
#ifndef LOCAL
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
#endif


	scanf("%d",&n);
	f(i,1,n){
		g(j,i + 1,n)scanf("%d",&map[i][j]);
	}
	// g(i,1,n){
	// 	g(j,1,n)printf("%d ",map[i][j]);
	// 	puts("");
	// }
#ifdef TI
	st = clock();
#endif
	get();

#ifdef TI
	ed = clock();
	printf("%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
/*
5
1 1 1 2
33 33 33
33 33
33

 */
