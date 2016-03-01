#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MAXN = 10000033;
int n;
int b[MAXN];
inline int read(int &x) {
  x = 0; char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return x;
}
int premin[MAXN];
int ans;
struct node {
  int l, r, md;
  node *ls, *rs;
  int mn, mx;
  inline node(int ll = 0, int rr = 0):l(ll), r(rr), md(ll + (rr - ll >> 1)) {
    if (ll == rr) {
      ls = rs = NULL;
      mn = mx = b[ll];
      return;
    }
    ls = new node(ll, md);
    rs = new node(md + 1, rr);
    mn = std::min(ls->mn, rs->mn);
    mx = std::max(ls->mx, rs->mx);
  }
  inline int min(int ll, int rr) {
    if (ll == l && rr == r) {
      return mn;
    }
    if (ll > md) return rs->min(ll, rr);
    if (rr <= md) return ls->min(ll, rr);
    return std::min(ls->min(ll, md), rs->min(md + 1, rr));
  }
  inline int max(int ll, int rr) {
    if (ll == l && rr == r) {
      return mx;
    }
    if (ll > md) return rs->max(ll, rr);
    if (rr <= md) return ls->max(ll, rr);
    return std::max(ls->max(ll, md), rs->max(md + 1, rr));
  }
};
int mnn, mxx;
int main() {
#ifndef LOCAL
  freopen("array.in", "r", stdin);
  freopen("array.out", "w", stdout);
#endif

  read(n);
  g(i, 1, n) read(b[i]);
  node* root = new node(1, n);
  ans = 1;
  f(i, 0, n) premin[i + 1] = std::min(premin[i], b[i]);
  g(i, 1, n) {
    gd(j, (i - ans), 1) {
      if (premin[j] > b[j]) break;
      mnn = root->min(j, i);
      if (mnn == b[j]) {
        mxx = root->max(j, i);
        if (mxx > b[i]) break;
      // if (root->min(j, i) == b[j] && root->max(j, i) == b[i]) {
        if (mxx == b[i]) ans = std::max(ans, i - j + 1);
      }
    }
  }
  printf("%d\n", ans);

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}

/*
9
2 1 6 5 4 2 7 2 2
 */