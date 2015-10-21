#include <cstdio>
#include <ctime>
#include <cstring>
#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)

double st,ed;

typedef long long LL;

int n,a,b,k;
int d[2024][2024];
int dis;
#include <algorithm>
inline int abs(int x){
	if (x < 0)return -x;
	return x;
}
int main(){
#ifndef LOCAL
freopen("jump.in","r",stdin);
freopen("jump.out","w",stdout);
#endif

	scanf("%d%d%d%d",&n,&a,&b,&k);
	g(i,1,n)d[i][0] = 1;
	d[b][0] = 0;
	g(i,1,k)g(j,1,n)if (j == b)d[j][i] = 0;
	else {
		// dis = j - b;if (dis < 0)dis = -dis;
		// g(l,std::max(0,j - dis + 1),std::min(n,j + dis - 1))if (l != j){
			// d[l][i] += d[j][i - 1];
		// }
		g(q,1,n)if (q != j && abs(j - q) < abs(q - b)){
			d[q][i] += d[j][i - 1];
			// printf("```%d %d\n",q,i);
		}
	}
	// g(i,1,n){
		// g(j,1,k)printf("%d ",d[i][j]);puts("");
	// }
	printf("%d\n",d[a][k]);

#ifndef LOCAL
fclose(stdin);
fclose(stdout);
#endif
	return 0;
}
