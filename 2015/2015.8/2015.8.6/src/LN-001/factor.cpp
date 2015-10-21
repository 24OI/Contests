#include <cstdio>
#include <ctime>
#include <cstring>
#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)

double st,ed;

typedef long long LL;
LL l,r;
LL pri[1000024];
bool notp[1000024];
int sz,id;
void init(){
// st = clock();
	memset(notp,0,sizeof notp);
	notp[1] = 1;
	memset(pri,0,sizeof pri);
	id = 0;sz = 1000000;
	g(i,2,sz)if (!notp[i]){
		pri[id++] = i;
		for(LL j = (LL)i * i;j <= sz;j += i){
			notp[j] = 1;
			// ans[j] = i;
		}
	}
// ed = clock();
	// printf("%lf\n",(ed - st) / CLOCKS_PER_SEC);
	// f(i,0,id)printf("%d\n",pri[i]);
}
int pre;
LL ans[1000024];
inline int get(LL x){
	f(i,0,id)if (x % pri[i] == 0)return pri[i];
}
LL lb,rb,pos;
int main(){
#ifndef LOCAL
freopen("factor.in","r",stdin);
freopen("factor.out","w",stdout);
#endif
#ifdef LOG
st = clock();
#endif
	scanf("%I64d%I64d",&l,&r);
	memset(ans,0,sizeof ans);
	init();
	// for(LL i = l;i <= r;++i)if (!ans[i - l]){
		// pre = get(i);
		// for(LL j = i + pre;j <= r;j += pre)if (!ans[j])ans[j] = pre;
	// }
	f(i,0,id){
		lb = l / pri[i];rb = r / pri[i];
		g(j,lb,rb){
			pos = (LL)j * pri[i] - l;
			if (!ans[pos])ans[pos] = pri[i];
		}
	}
	g(i,0,r - l){
		if (!ans[i])ans[i] = i + l;
		printf("%I64d\n",ans[i]);
	}


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
