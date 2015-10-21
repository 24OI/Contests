#include <cstdio>
#include <ctime>
#include <cstring>
#define f(x,y,z) for(int x = (y),_var_ = (z);x < _var_;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)

double st,ed;

typedef long long LL;

int n;
#include <vector>
std::vector<int> V[2];
int pos,ans;
int main(){
#ifndef LOCAL
freopen("eat.in","r",stdin);
freopen("eat.out","w",stdout);
#endif
#ifdef LOG
st = clock();
#endif

	scanf("%d",&n);
	f(i,0,n){
		scanf("%d",&pos);
		V[0].push_back(pos);
	}
	while (233){
		pos = ans & 1;
		++ans;
		V[pos ^ 1].clear();
		V[pos ^ 1].push_back(V[pos][0]);
		f(j,1,V[pos].size()){
			if (V[pos][j] > V[pos][j - 1])V[pos ^ 1].push_back(V[pos][j]);
		}
		// f(i,0,V[pos ^ 1].size())printf("%d ",V[pos ^ 1][i]);puts("");
		if (V[pos ^ 1].size() == V[pos].size())break;
		if (ans > n){
			puts("1");return 0;
		}
	}
	printf("%d\n",ans - 1);

#ifdef LOG
ed = clock();
fprintf(stderr,"%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif
#ifndef LOCAL
fclose(stdin);
fclose(stdout);
#endif
	return 0;
}
