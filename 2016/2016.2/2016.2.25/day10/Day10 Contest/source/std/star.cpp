#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <LL, LL> Pll;
typedef pair <Pll, Pll> Ppp;
#define x first
#define y second
#define mp make_pair
#define N 1000 + 5
#define M 1000000 + 5
#define Mod1 1000000007
#define Mod2 998244353

int n, size, Max, cnt, A[N], B[N];
LL C[N];
Ppp P[M];

inline LL gcd(LL x, LL y)
{
    return !y ? x : gcd(y, x % y);
}

inline Pll Get_x(int u, int v)
{
    LL t_1 = C[v] * B[u] - C[u] * B[v];
    LL t_2 = (LL) A[u] * B[v] - (LL) A[v] * B[u];
    LL t = gcd(t_1, t_2);
    return mp(t_1 / t, t_2 / t);
}

inline Pll Get_y(int u, int v)
{    
    LL t_1 = C[v] * A[u] - C[u] * A[v];
    LL t_2 = (LL) B[u] * A[v] - (LL) B[v] * A[u];
    LL t = gcd(t_1, t_2);
    return mp(t_1 / t, t_2 / t);
}

inline bool Check(Ppp u, Ppp v, int Mod)
{
    int a_1 = u.x.x % Mod, b_1 = u.x.y % Mod;
    int a_2 = v.x.x % Mod, b_2 = v.x.y % Mod;
    if ((LL) a_1 * b_2 != (LL) a_2 * b_1) return 0;
    a_1 = u.y.x % Mod, b_1 = u.y.y % Mod;
    a_2 = v.y.x % Mod, b_2 = v.y.y % Mod;
    if ((LL) a_1 * b_2 != (LL) a_2 * b_1) return 0;
    return 1;
}

inline bool Judge(Ppp u, Ppp v)
{
    return Check(u, v, Mod1) && Check(u, v, Mod2);
}

int main()
{
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d%lld", A + i, B + i, C + i);
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
        {
            if ((LL) A[i] * B[j] == (LL) A[j] * B[i]) continue ;
            P[++ size] = mp(Get_x(i, j), Get_y(i, j));
        }
    sort(P + 1, P + size + 1);
    for (int i = 1, t = 0; i <= size; i ++)
    {
        if (i == 1 || Judge(P[i], P[i - 1])) t ++;
            else t = 1;
        if (t > Max) Max = t, cnt = 1;
            else if (t == Max) cnt ++;
    }
    for (int i = 1; ; i ++)
        if (i * (i - 1) / 2 == Max)
        {
            Max = i;
            break ;
        }
    
    printf("%d %d\n", Max, cnt);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
