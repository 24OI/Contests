#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define x1 x11
#define y1 y11

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int n;
double a[1033], b[1033], c[1033];
typedef std::pair<real, real> P;
std::vector<P> V;
const real EPS = 1e-8;
inline void add(int x, int y) {
	real a1 = a[x], b1 = b[x], c1 = c[x];
	real a2 = a[y], b2 = b[y], c2 = c[y];
	real yy = b1 * a2 - a1 * b2;
	if (fabs(yy) <= EPS) return;
	yy = (c2 * a1 - c1 * a2) / yy;
	real xx = -b1* yy - c1;
	if (fabs(a1) > EPS) xx /= a1;
	else {
		xx = -b2 * yy - c2;
		xx = xx / a2;
	}
	V.push_back(P(xx, yy));
}
int cnt, mx;
int num, nx;
int main() {
#ifndef LOCAL
  freopen("star.in", "r", stdin);
  freopen("star.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
  	scanf("%lf%lf%lf", a + i, b + i, c + i);
  	f(j, 0, i) add(j, i);
  }
  std::sort(V.begin(), V.end());
  if (V.size() == 0) {
  	puts("1 23333333333");
  	return 0;
  }
  if (V.size() == 1) {
  	puts("2 1");
  	return 0;
  }
  mx = 1; cnt = 1; num = 1; nx = 1;
  // f(i, 0, V.size()) printf("%lf %lf\n", V[i].first, V[i].second);
  f(i, 1, V.size()) {
  	// printf("%d %d %d %d\n", cnt, mx, num, nx);
  	if (fabs(V[i].first - V[i - 1].first) <= EPS && fabs(V[i].second - V[i - 1].second) <= EPS) {
  		++cnt;
  	} else {
  		if (num > nx) nx = num;
  		if (cnt > mx) {
  			mx = cnt;
  			num = 1;
  		} else if (cnt == mx) {
  			++num;
  		}
  		cnt = 1;
  	}
  }
  if (num > nx) nx = num;
  if (cnt > mx) {
  	mx = cnt;
  }
  printf("%d %d\n", mx + 1, nx);

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
/*
3
0 1 0
1 0 0
1 1 -1
 */
