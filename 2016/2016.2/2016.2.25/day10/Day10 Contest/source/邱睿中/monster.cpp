#include <cstdio>
#include <cctype>
#include <cstring>
#define NAME "monster"
#undef INT
#define INT long long
#define N_MAX 2048
#define MOD 593119681LL
inline void I(INT & x)
{
    x = 0; int c; bool s = false;
    do  (c = getchar()) == '-' ? s = true : false;
    while (c != EOF && !isdigit(c));
    while (c != EOF && isdigit(c))
        x = x * 10 - '0' + c, c = getchar();
    if (s) x = -x;
}
void O(INT x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) O(x / 10);
    putchar((int)(x % 10 + '0'));
}
INT dis(INT u, INT v)
{
    INT ans = 0;
    for (INT x = u ^ v; x; ans += (x & 1) ? 1 : 0, x >>= 1);
    return ans;
}
INT n, t, m, u, v, num[N_MAX], tmp[N_MAX];
int main()
{
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
    I(n); I(t); m = 1 << n;
    for (u = 0; u < m; ++u) I(num[u]), num[u] %= MOD;
    memcpy(tmp, num, (size_t) m * sizeof (INT));
    while (t--)
    {
        for (u = 0; u < m; ++u)
            for (v = 0; v < m; ++v)
                if (dis(u, v) == 1) tmp[v] = (tmp[v] + num[u]) % MOD;
        memcpy(num, tmp, (size_t) m * sizeof (INT));
//#ifdef DEBUG
//        for (u = 0; u < m; ++u)
//            O(num[u]), putchar(' ');
//        putchar('\n');
//#endif
    }
    for (u = 0; u < m; ++u)
        O(num[u]), putchar(' ');
    putchar('\n');
    return 0;
}
