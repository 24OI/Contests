#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <LL, LL> Pll;
#define N 200 + 5
#define x first
#define y second
#define mp make_pair
#define Mod1 1000000007
#define Mod2 998244353

int n, size, Max, cnt, A[N], B[N], C[N];

inline int Inc(int a, int b, int p)
{
    return a + b - (a + b >= p ? p : 0);
}

inline LL gcd(LL x, LL y)
{
    return !y ? x : gcd(y, x % y);
}

inline Pll Get_x(int u, int v)
{
    LL t_1 = (LL) C[v] * B[u] - (LL) C[u] * B[v];
    LL t_2 = (LL) A[u] * B[v] - (LL) A[v] * B[u];
    LL t = gcd(t_1, t_2);
    return mp(t_1 / t, t_2 / t);
}

inline Pll Get_y(int u, int v)
{    
    LL t_1 = (LL) C[v] * A[u] - (LL) C[u] * A[v];
    LL t_2 = (LL) B[u] * A[v] - (LL) B[v] * A[u];
    LL t = gcd(t_1, t_2);
    return mp(t_1 / t, t_2 / t);
}

inline bool Check(Pll x, Pll y, int k, int p)
{
    int a = Inc(A[k], p, p), b = Inc(B[k], p, p), c = Inc(C[k], p, p);
    int x_1 = Inc(x.x % p, p, p), y_1 = Inc(x.y % p, p, p);
    int x_2 = Inc(y.x % p, p, p), y_2 = Inc(y.y % p, p, p);
    int delta = ((LL) x_1 * a % p * y_2 % p + (LL) y_1 * x_2 % p * b % p + (LL) c * y_1 % p * y_2 % p) % p;
    return delta == 0;
}

int main()
{
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d%d", A + i, B + i, C + i);
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
        {
            if ((LL) A[i] * B[j] == (LL) A[j] * B[i]) continue ;
            Pll x = Get_x(i, j), y = Get_y(i, j);
            int _cnt = 2;
            for (int k = j + 1; k <= n; k ++)
                if (Check(x, y, k, Mod1) && Check(x, y, k, Mod2)) _cnt ++;
            if (_cnt > Max) Max = _cnt, cnt = 1;
                else if (_cnt == Max) cnt ++;
        }
    printf("%d %d\n", Max, cnt);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
