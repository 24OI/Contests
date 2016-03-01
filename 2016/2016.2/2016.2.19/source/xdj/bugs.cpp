#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MAXN = 1000033;
int n, m, p;
int s[MAXN];
struct mat {
  int a[3][3];
  inline mat() {
    memset(a, 0, sizeof a);
  }
  inline mat operator * (const mat& T) const {
    mat res;
    f(i, 0, 2) f(j, 0, 2) f(k, 0, 2) (res.a[i][j] += (LL)a[i][k] * T.a[k][j] % p) %= p;
    return res;
  }
};
std::vector<int> a[2];
std::vector<int> hash;
int pow(int x, int y) {
  int res = 1, bas = x;
  while (y) {
    if (y & 1) res = (LL)res * bas % 998244353;
    bas = (LL)bas * bas % 998244353;
    y >>= 1; 
  }
  return res;
}
int val(int st) {
  int ed = st + m - 1, pre;
  if (st) pre = hash[st - 1];
  else pre = 0;
  // printf("val:%d ==> %d %d %d\n", st, pre, hash[ed], pow(2, m));
  return (hash[ed] - (LL)pre * pow(2, m) % 998244353 + 998244353) % 998244353;
}
void brutal() {
  a[0].push_back(0);
  int cur, nx;
  g(i, 1, n) {
    nx = i & 1; cur = nx ^ 1;
    a[nx].clear();
    f(j, 0, a[cur].size()) {
      if (a[cur][j] == 0) {
        a[nx].push_back(1);
      } else {
        a[nx].push_back(0);
        a[nx].push_back(1);
      }
    }
  }
  cur = (n & 1);
  int sz = a[cur].size();
  f(i, 0, sz) {
    if (i) hash.push_back((hash[i - 1] * 2 + a[cur][i]) % 998244353);
    else hash.push_back(a[cur][0]);
  }
  // f(i, 0, sz) printf("%d ", a[cur][i]); puts("");
  // f(i, 0, sz) printf("%d ", hash[i]); puts("");
  int has = 0;
  f(i, 0, m) (has = has * 2 + s[i]) % 998244353;
  // printf("val:%d\n", has);
  int cnt = 0;
  f(i, 0, sz) {
    if (i + m - 1 >= sz) break;
    // printf("%d %d %d\n", i, val(i), has);
    if (val(i) == has) ++cnt;
  }
  printf("%d\n", cnt);
}
bool spe() {
  if (m == 2 && s[0] == 0 && s[1] == 1) return 1;
  if (m == 1 && s[0] == 0) return 1;
  if (m == 1 && s[0] == 1) {
    ++n;
    return 1;
  }
  return 0;
}
int delta;
void wingardium() {
  n -= 2;
  mat res, s;
  res.a[0][0] = res.a[1][1] = 1;
  s.a[0][0] = 0;
  s.a[0][1] = s.a[1][0] = s.a[1][1] = 1;
  while (n) {
    if (n & 1) res = s * res;
    s = s * s;
    n >>= 1;
  }
  // printf("%d %d\n%d %d\n", res.a[0][0], res.a[0][1], res.a[1][0], res.a[1][1]);
  memset(s.a, 0, sizeof s.a);
  s.a[1][0] = 1;
  res = res * s;
  printf("%d\n", res.a[0][0] - delta);
  // printf("%d %d\n%d %d\n", res.a[0][0], res.a[0][1], res.a[1][0], res.a[1][1]);
}
int num[33];
void magic() {
  if (spe()) {
    wingardium();
    return;
  }
  a[0].push_back(0);
  int cur, nx, st = 0;
  int has = 0;
  f(j, 0, m) (has = has * 2 + s[j]) % 998244353;
  g(i, 1, 21) {
    nx = i & 1; cur = nx ^ 1;
    a[nx].clear();
    f(j, 0, a[cur].size()) {
      if (a[cur][j] == 0) {
        a[nx].push_back(1);
      } else {
        a[nx].push_back(0);
        a[nx].push_back(1);
      }
    }
    cur = (i & 1);
    int sz = a[cur].size();
    hash.clear();
    f(j, 0, sz) {
      if (j) hash.push_back((hash[j - 1] * 2 + a[cur][j]) % 998244353);
      else hash.push_back(a[cur][0]);
    }
    // f(j, 0, sz) printf("%d ", a[cur][j]); puts("");
    // f(j, 0, sz) printf("%d ", hash[j]); puts("");
    // printf("val:%d\n", has);
    int cnt = 0;
    f(j, 0, sz) {
      if (j + m - 1 >= sz) break;
      // printf("%d %d %d\n", j, val(j), has);
      if (val(j) == has) ++cnt;
    }
    num[i] = cnt;
    if (num[i] == 1) {
      if (st == 0) st = i;
      // break;
    }
    // printf("%d\n", cnt);
  }
  int pos;
  g(i, 2, 23) if (num[i] != num[i - 1] + num[i - 2]) pos = i & 1;
  // g(i, 1, n) printf("%d ", num[i]); puts("");
  // printf("st: %d\n", st);
  n -= st; n += 4;
  delta = ((n - 2) & 1) == pos;
  // puts("wtf");
  wingardium();
}
int main() {
#ifndef LOCAL
  freopen("bugs.in", "r", stdin);
  freopen("bugs.out", "w", stdout);
#endif

  scanf("%d%d%d\n", &n, &m, &p);
  f(i, 0, m) scanf("%1d", s + i);
  if (n <= 23) {
    brutal();
    return 0;
  }
  magic();

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
}

/*
1 0
01 0
101 1
01101 1
10101101 3
0110110101101 4
101011010110110101101 8
0110110101101101011010110110101101 12
1010110101101101011010110110101101101011010110110101101 21
 */
