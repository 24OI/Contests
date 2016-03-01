#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int n, m;
std::vector<int> G[20033];
int u[200033], v[200033];
int done[200033];
int vis[200033];
typedef std::pair<int, int> PII;
std::vector<PII> ans1, ans2;
void col1(int x);
void dfs1(int x) {
  if (!vis[ u[x] ]) col1(u[x]);
  if (!vis[ v[x] ]) col1(v[x]);
}
void col1(int x) {
  vis[x] = 1;
  int pre = 0;
  f(i, 0, G[x].size()) if (!done[ G[x][i] ]) {
    if (pre) {
      ans1.push_back(PII(pre, G[x][i]));
      done[pre] = 1; done[ G[x][i] ] = 1;
      pre = 0;
    }
    else pre = G[x][i];
  }
  if (pre) dfs1(pre);
}
void col2(int x);
void dfs2(int x) {
  if (!vis[ u[x] ]) col2(u[x]);
  if (!vis[ v[x] ]) col2(v[x]);
}
void col2(int x) {
  vis[x] = 1;
  int pre = 0;
  f(i, 0, G[x].size()) if (!done[ G[x][i] ]) {
    if (pre) {
      ans2.push_back(PII(pre, G[x][i]));
      done[pre] = 1; done[ G[x][i] ] = 1;
      pre = 0;
    }
    else pre = G[x][i];
  }
  if (pre) dfs2(pre);
}
int main() {
#ifndef LOCAL
  freopen("pair.in", "r", stdin);
  freopen("pair.out", "w", stdout);
#endif

  scanf("%d%d", &m, &n);
  g(i, 1, n) {
    scanf("%d%d", u + i, v + i);
    G[ u[i] ].push_back(i);
    G[ v[i] ].push_back(i);
  }
  g(i, 1, n) dfs1(i);
  memset(done, 0, sizeof done);
  memset(vis, 0, sizeof vis);
  gd(i, n, 1) dfs2(i);
  if (ans1.size() > ans2.size()) {
    printf("%d\n", ans1.size());
    f(i, 0, ans1.size()) {
      printf("%d %d\n", ans1[i].first, ans1[i].second);
    }
  } else {
    printf("%d\n", ans2.size());
    f(i, 0, ans2.size()) {
      printf("%d %d\n", ans2[i].first, ans2[i].second);
    }
  }

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}

/*
7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6


7 10
1: 1 2
2: 1 3
3: 2 4
4: 3 4
5: 4 5
6: 4 6
7: 5 7
8: 6 7
9: 2 5
10: 3 6
 */
