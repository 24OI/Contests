#define PROB Training
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
typedef std::pair<int,int> PII;

#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)
#define CLR(X) memset(X,0,sizeof(X))
#define SET(ARR,X) memset(ARR,X,sizeof(ARR))
#define R(X,Y) f(X,0,Y)
#define G(x,y) g(X,0,Y)
#define MAXN 2000033

#ifdef WIN32
	#define LLD "%I64d"
	#define LLU "%I64u"
#else
	#define LLD "%lld"
	#define LLU "%llu"	
#endif

typedef long long LL;
typedef long double real;

int n;
LL l,r;
int pri[MAXN];
bool isNot[MAXN];
int sz;
LL ans[MAXN];
void init(){
	sz = 0;
	isNot[1] = isNot[0] = 1;
	g(i,2,2000000){
		if (!isNot[i])pri[sz++] = i;
		f(j,0,sz){
			if ((LL)i * pri[j] > 2000000)break;
			isNot[ i * pri[j] ] = 1;
			if (i % pri[j] == 0)break;
		}
	}
	int lb,rb,tee;
	// printf("%d\n",sz);
	// f(i,0,10)printf("%d ",pri[i]);puts("");
	f(i,0,sz){
		lb = l / pri[i];
		rb = r / pri[i];
		// printf("%d %d %d\n",i,lb,rb);
		g(k,lb,rb){
			tee = k * pri[i] - l;
			if (tee < 0)continue;
			// DIDNT GET AC BECAUSE OF THE FAULT HERE!!!!
			// tee might < 0 and cause RE!!!
			if (!ans[tee])ans[tee] = pri[i];
		}
	}
}
int main(){
#ifndef LOCAL
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
#endif

	scanf("%lld%lld",&l,&r);
	init();
	g(i,0,r - l){
		if (!ans[i])ans[i] = i + l;
		// printf("%lld %lld\n",i + l,ans[i]);
		printf("%lld\n",ans[i]);
	}

#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
