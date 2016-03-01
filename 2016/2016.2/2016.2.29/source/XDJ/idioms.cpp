#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
std::vector<int> G;

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int n, d;
int dig;
const int MAXN = 50033;
char s[MAXN][12];
int r[MAXN];
bool cmp(int x, int y) {
	// G.push_back(x); G.push_back(y);
	if (x >= n || y >= n) return 1;
	// printf("%d %d\n", x, y);
	f(i, 0, 4) {
		if (dig & (1 << i)) continue;
		if (s[x][i] == s[y][i]) continue;
		return s[x][i] < s[y][i];
	}
}
inline void print(int x) {
	f(i, 0, 5) {
		if ((dig & (1 << i)) == 0) {
			putchar(s[x][i]);
		}
	}
}
inline bool same(int x, int y) {
	f(i, 0, 5) {
		if (dig & (1 << i)) continue;
		if (s[x][i] != s[y][i]) return 0;
	}
	// print(x); putchar(':'); print(y);
	// f(i, 0, 5) putchar(s[x][i]); puts("");
	// f(i, 0, 5) putchar(s[y][i]); puts("");
	return 1;
}
inline int dis(int x, int y) {
	int res = 0;
	f(i, 0, 4) res += int(s[x][i] != s[y][i]);
	return res;
}
int res = 0;
int cnt;
int rank[MAXN];
int num;
void solve0() {
	dig = 0;
	f(i, 0, n) r[i] = i;
	std::sort(r, r + n, cmp);
	// f(i, 0, n) rank[ r[i] ] = i;
	cnt = 1;
	f(i, 1, n) {
		if (same(r[i], r[i - 1])) {
			++cnt;
		} else {
			num += (cnt) * (cnt - 1) / 2;
		  cnt = 1;
		}
		num += (cnt) * (cnt - 1) / 2;
	}
}
int dir1[] = {1, 2, 4, 8};
void solve1(int fff) {
	f(idx, 0, 4) {
		dig = dir1[idx];
	  f(i, 0, n) r[i] = i;
		std::sort(r, r + n, cmp);
		// f(i, 0, n) rank[ r[i] ] = i;
		cnt = 1;
		f(i, 1, n) {
			if (same(r[i], r[i - 1])) {
				++cnt;
			} else {
				res += (cnt) * (cnt - 1) / 2 * fff;
				cnt = 1;
			}
		}
		res += (cnt) * (cnt - 1) / 2 * fff;
	}
}
int dir2[] = {3, 5, 6, 9, 10, 12};
void solve2(int fff) {
	f(idx, 0, 6) {
		dig = dir2[idx];
	  f(i, 0, n) r[i] = i;
		std::sort(r, r + n, cmp);
		// f(i, 0, n) r[ r[i] ] = i;
		cnt = 1;
		f(i, 1, n) {
			if (same(r[i], r[i - 1])) {
				// printf("%s %s\n", s[ r[i - 1] ], s[ r[i] ]);
				++cnt;
			} else {
				res += (cnt) * (cnt - 1) / 2 * fff;
				cnt = 1;
			}
		}
		res += (cnt) * (cnt - 1) / 2 * fff;
	}
}
int dir3[] = {7, 11, 13, 14};
inline bool cc(int x, int y) {
	G.push_back(x); G.push_back(y);
	return 0;
}
void solve3(int fff) {
	f(idx, 0, 4) {
		dig = dir3[idx];
	  f(i, 0, n) r[i] = i;
		std::sort(r, r + n, cmp);
		// std::sort(G.begin(), G.end());
		// printf("%d %d\n", G[0], G[G.size() - 1]);
		// printf("Done %d\n", dig);
		// f(i, 0, n) rank[ r[i] ] = i;
		// f(i, 0, n) printf("%d\n", rank[i]); puts("");
		cnt = 1;
		f(i, 1, n) {
			if (same(r[i], r[i - 1])) {
				// print(r[i]); putchar(','); print(r[i - 1]);
				// printf("\n%s %s\n", s[ r[i] - 1 ], s[ r[i] ]);
				++cnt;
			} else {
				// if (cnt - 1) printf("cnt: %d\n", cnt);
				res += (cnt) * (cnt - 1) / 2 * fff;
				cnt = 1;
			}
		}
		res += (cnt) * (cnt - 1) / 2 * fff;
	}
}
void solve4() {
	dig = 15;
// care

}
int get1() {
  solve1(1);
  res -= num * 4;
  if (res < 0) res = 0;
  int tee = res; res = 0;
  return tee;
}
int get2() {
  solve2(1);
  solve1(-3);
  res -= num * 6;
  if (res < 0) res = 0;
  int tee = res; res = 0;
  return tee;
}
int get3() {
  solve3(1);
  // printf("%d\n", res);
  solve2(-2);
  // printf("%d\n", res);
  solve1(3);
  // printf("%d\n", res);
  res -= num * 4;
  if (res < 0) res = 0;
  int tee = res; res = 0;
  return tee;
}
int get4() {

}
void novice() {
	f(i, 0, n) f(j, 0, i) if (dis(i, j) == d) {
    // printf("%s %s\n", s[j], s[i]);
    ++res;
  }
  // printf("WTF::::%d\n", dis(7, 22));
  printf("%d\n", res);
}
int main() {
#ifndef LOCAL
  freopen("idioms.in", "r", stdin);
  freopen("idioms.out", "w", stdout);
#endif

#ifdef TI
  double st = clock();
#endif
  // freopen("a.out", "r", stdin);
  scanf("%d%d", &n, &d);
  f(i, 0, n) {
  	scanf("%s", &s[i][0]);
  	// s[i][4] = '\0';
  }
  if (n <= 3000) {
  	novice();
  	return 0;
  }
  // dig = 0;
  // f(i, 0, n) r[i] = i;
  // std::sort(r, r + n, cmp);
  // f(i, 0, n) {
  // 	print(r[i]);
  // 	puts("");
  // }
  // 
  // f(i, 0, n) {
  // 	printf("%d\n", strlen(s[i]));
  // }
  // f(i, 0, n) gets(s[i]);
  solve0();
  // printf("%d\n", num);
  if (d == 1) {
  	printf("%d\n", get1());
  } else if (d == 2) {
  	printf("%d\n", get2());	
  } else if (d == 3) {
  	printf("%d\n", get3());
  } else {
  	// solve4();
  	int tee = (LL)n * (n - 1) / 2;
  	printf("%d\n", tee - get1() - get2() - get3());
  }
  // f(i, 0, n) r[i] = i;
  // std::sort(r, r + n, cmp);
  // f(i, 0, n) printf("%d ", r[i]); puts("");
  // f(i, 0, n) f(j, 0, i) if (dis(i, j) == d) ++res;
  // printf("%d\n", res);

#ifdef TI
  double ed = clock();
  fprintf(stderr, "%lf\n", (ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}

/*
4 2
0000
a010
0202
a0e2
 */
