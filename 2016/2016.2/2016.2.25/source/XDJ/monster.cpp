#include <cstdio>
#include <cstring>
#include <cstdlib>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MOD = 593119681;
int n, t;
int ss;
LL cnt[262233], num[262233];
int tee;
struct node {
	int t, x;
} e[2622330];
int idx = 1, head[262233];
inline void add(int x, int y) {
	e[++idx].t = y; e[idx].x = head[x]; head[x] = idx;
	e[++idx].t = x; e[idx].x = head[y]; head[y] = idx;
}
int done[262233];
void novice() {
  // printf("idx: %d\n", idx);
  f(ti, 1, t) {
  	f(i, 0, n) num[i] = cnt[i];
  	// f(i, 0, n) printf("%d ", num[i]); puts("");
  	f(i, 0, n) {
  		cnt[i] = num[i];
  		for (int j = head[i]; j; j = e[j].x) {
  			(cnt[i] += num[e[j].t]) %= MOD;
  			// printf("(%d, %d)\n", i, e[j].t);
  		}
  	}
  }
  f(i, 0, n) printf("%d ", cnt[i]); puts("");
}
struct mat {
	int a[66][66];
	inline mat() {
		memset(a, 0, sizeof a);
	}
	inline mat operator * (const mat& T) const {
		mat res;
		f(i, 0, n) f(j, 0, n) f(k, 0, n) (res.a[i][j] += (LL)a[i][k] * T.a[k][j] % MOD) %= MOD;
		return res;
	}
} r, l;
void moderate() {
	f(i, 0, n) {
		r.a[i][i] = 1;
		for (int j = head[i]; j; j = e[j].x) {
			r.a[i][e[j].t] = r.a[e[j].t][i] = 1;
		}
	}
	f(i, 0, n) l.a[i][i] = 1;
	int x = t;
	while (t) {
		if (t & 1) l = l * r;
		r = r * r;
		t >>= 1;
	}
	t = x;
	// f(i, 0, n) {
	// 	f(j, 0, n) printf("%d ", l.a[i][j]); puts("");
	// }
	memset(r.a, 0, sizeof r.a);
	f(i, 0, n) r.a[i][0] = num[i];
	r = l * r;
	f(i, 0, n) printf("%d ", r.a[i][0]); puts("");
}
int main() {
#ifndef LOCAL
  freopen("monster.in", "r", stdin);
  freopen("monster.out", "w", stdout);
#endif

  scanf("%d%d", &n, &t); ss = n;
  n = 1 << n;
  f(i, 0, n) scanf("%lld", num + i);
  memset(done, -1, sizeof done);
  f(i, 0, n) {
  	for (int j = n; j >= 0; j >>= 1) {
  		if ((i ^ j) < i && done[i ^ j] != i) {
  			add(j ^ i, i);
  			// printf("[%d, %d]\n", i ^ j, i);
  			done[i ^ j] = i;
  			(cnt[i] += num[j ^ i]) %= MOD;
  			(cnt[i ^ j] += num[i]) %= MOD;
  		}
  		if (j == 0) break;
  	}
  	(cnt[i] += num[i]) %= MOD;
  }
  // moderate();
	// novice();
  // return 0;
  if (ss <= 6 && t <= 1000) novice();
  else {
  	moderate();
  }


#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
