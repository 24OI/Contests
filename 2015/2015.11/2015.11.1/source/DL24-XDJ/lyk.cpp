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
int a[100033];
int t[100033];
int b[100033];
int x,y;
int ans;
inline int lowbit(int x){
	return x & -x;
}
inline void upd(int x){
	for(int i = x;i <= n;i += lowbit(i)){
		t[i] ^= 1;
	}
}
inline int sum(int x){
	int res = 0;
	for(int i = x;i;i -= lowbit(i)){
		res ^= t[i];
	}
	return res & 1;
}
int res;
int get(){
	memcpy(a,b,sizeof a);
	ans = 0;
	gd(i,n,1){
		upd(a[i]);
		ans ^= sum(a[i] - 1);
	}
	return res = ans & 1;
}
int m;
int main(){
#ifndef LOCAL
	freopen("lyk.in","r",stdin);
	freopen("lyk.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d",&n);
	g(i,1,n){
		scanf("%d",b + i);
	}
	scanf("%d",&m);
	get();
	while (m--){
		scanf("%d%d",&x,&y);
		std::swap(b[x],b[y]);
		if (x != y)res ^= 1;
		printf("%d\n",res);
		// printf("%d\n",get());
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
//答案取模2

