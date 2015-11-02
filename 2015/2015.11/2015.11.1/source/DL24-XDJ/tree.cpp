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
int map[533][533];
int m;
int x,y,z;
int a,b,c,d;
int ans;
int main(){
#ifndef LOCAL
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d",&n);
	memset(map,0x1f,sizeof map);
	f(i,1,n){
		scanf("%d%d%d",&x,&y,&z);
		map[y][x] = map[x][y] = z;
	}
	g(k,1,n)g(i,1,n)g(j,1,n)map[i][j] = std::min(map[i][j],map[i][k] + map[k][j]);
	scanf("%d",&m);
	while (m--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans = 0;
		g(i,a,b)g(j,c,d)ans = std::max(ans,map[i][j]);
		printf("%d\n",ans);
	}

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
1 2 1
2 3 2
1 4 3
4 5 4
1
2 3 4 5
 */
