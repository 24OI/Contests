#include <cstdio>
#include <cstring>
typedef long long int LL;
const int MAXN = 1035;
const LL MOD = 593119681LL;

int tmp[MAXN][MAXN], res[MAXN][MAXN], base[MAXN][MAXN], n, t, initial[MAXN];

inline int bitCount(int x){
	int ret = 0;
	while(x) ret += x & 1, x >>= 1;
	return ret;
}
void mul(int x[MAXN][MAXN]){
	int i, j, k;
	for(i = 0; i < n; ++ i)
		for(j = 0; j < n; ++ j){
			tmp[i][j] = 0;
			for(k = 0; k < n; ++ k)
				tmp[i][j] = (tmp[i][j] + LL(x[i][k]) * base[k][j]) % MOD;
		}
	memcpy(x, tmp, sizeof(tmp));
}
int main(){
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	int i, j, k;
	scanf("%d%d", &n, &t); n = 1 << n;
	for(i = 0; i < n; ++ i) scanf("%d", &initial[i]);
	for(i = 0; i < n; ++ i){
		res[i][i] = 1;
		for(j = 0; j < n; ++ j)
			base[i][j] = bitCount(i ^ j) == 1 ? 1 : 0;
		base[i][i] = 1;
	}
	while(t){
		if(t & 1) mul(res);
		mul(base);
		t >>= 1;
	}
	for(i = 0; i < n; ++ i){
		for(k = j = 0; j < n; ++ j)
			k = (k + LL(res[i][j]) * initial[j]) % MOD;
		printf("%d ", k);
	}
	return 0;
}
