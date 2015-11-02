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
void get(){
	int m1 = 1,m2 = 1,m3 = 1;
	int ans = 0;
	g(cur,2,n){
		if (map[m1][cur] <= map[m2][cur] && map[m1][cur] <= map[m3][cur]){
			ans += map[m1][cur];
			m1 = cur;
		}else if (map[m2][cur] <= map[m1][cur] && map[m2][cur] <= map[m3][cur]){
			ans += map[m2][cur];
			m2 = cur;
		}else {
			ans += map[m3][cur];
			m3 = cur;
		}
		// printf("%d %d %d %d\n",m1,m2,m3,cur);
	}
	printf("%d\n",ans);
}
int main(){
#ifndef LOCAL
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d",&n);
	f(i,1,n){
		g(j,i + 1,n)scanf("%d",&map[i][j]);
	}
	// g(i,1,n){
	// 	g(j,1,n)printf("%d ",map[i][j]);
	// 	puts("");
	// }
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
