#include <cstdio>
#include <cstring>
#include <cmath>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
typedef long long LL;

bool prime[1000086];
int _ans[1000086];
#define ans(x) _ans[(x) - l]

int main(){
	LL l, r; scanf("%I64d%I64d", &l, &r);
	int n = sqrt(r) + 4;
	memset(prime, 1, sizeof(prime));
	memset(_ans, 0, sizeof(_ans));
	f(i, 2, n) if(prime[i]){
		for(int j = i + i; j <= n; j += i) prime[j] = 0;
		for(LL j = ((l - 1) / i + 1) * i; j <= r; j += i) if(!ans(j)) ans(j) = i;
	}
	for(LL i = l; i <= r; ++i) if(ans(i)) printf("%d\n", ans(i)); else printf("%I64d\n", i);
	return 0;
}
