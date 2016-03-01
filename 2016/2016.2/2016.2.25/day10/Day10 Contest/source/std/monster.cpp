#include <cstdio>
typedef long long LL;
#define N 262144 + 5
#define Mod 593119681
#define Inv_2 296559841

int n, t, A[N], B[N];

inline int Inc(int a, int b)
{
    return a + b - (a + b >= Mod ? Mod : 0);
}

inline int power(int u, int v)
{
    int res = 1;
    for (; v; v >>= 1)
    {
        if (v & 1) res = (LL) res * u % Mod;
        u = (LL) u * u % Mod;
    }
    return res;
}

inline void FWT(int *p)
{
    for (int k = 1; k < (1 << n); k <<= 1)
        for (int i = 0; i < (1 << n); i ++)
        {
            if (i & k) continue ;
            int u = Inc(p[i], p[i + k]);
            int v = Inc(p[i], Mod - p[i + k]);
            p[i] = u, p[i + k] = v;
        }
}

inline void Inv_FWT(int *p)
{
    for (int k = (1 << n - 1); k; k >>= 1)
        for (int i = 0; i < (1 << n); i ++)
        {
            if (i & k) continue ;
            int u = (LL) Inc(p[i], p[i + k]) * Inv_2 % Mod;
            int v = (LL) Inc(p[i], Mod - p[i + k]) * Inv_2 % Mod;
            p[i] = u, p[i + k] = v;
        }
}

int main()
{
    freopen("monster.in", "r", stdin);
    freopen("monster.out", "w", stdout);
    
    scanf("%d%d", &n, &t);
    for (int i = 0; i < (1 << n); i ++)
        scanf("%d", A + i);
    B[0] = 1;
    for (int i = 0; i < n; i ++)
        B[1 << i] = 1;
    FWT(A), FWT(B);
    for (int i = 0; i < (1 << n); i ++)
        B[i] = (LL) power(B[i], t) * A[i] % Mod;
    Inv_FWT(B);
    for (int i = 0; i < (1 << n); i ++)
        printf("%d%c", B[i], i == (1 << n) - 1 ? '\n' : ' ');
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
