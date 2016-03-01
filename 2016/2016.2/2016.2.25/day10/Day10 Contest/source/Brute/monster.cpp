#include <cstdio>
typedef long long LL;
#define N 64
#define Mod 593119681

int n, t;

inline int Inc(int a, int b)
{
    return a + b - (a + b >= Mod ? Mod : 0);
}

struct Rec
{
    int r, c, num[N][N];
    inline Rec operator * (const Rec a)
    {
        Rec b;
        b.r = r, b.c = a.c;
        for (int i = 0; i < b.r; i ++)
            for (int j = 0; j < b.c; j ++)
            {
                b.num[i][j] = 0;
                for (int k = 0; k < c; k ++)
                    b.num[i][j] = Inc(b.num[i][j], (LL) num[i][k] * a.num[k][j] % Mod);
            }
        return b;
    }
}f, g;

int main()
{
    freopen("monster.in", "r", stdin);
    freopen("monster.out", "w", stdout);
    
    scanf("%d%d", &n, &t);
    f.r = 1, f.c = 1 << n;
    g.r = g.c = 1 << n;
    for (int i = 0; i < (1 << n); i ++)
        scanf("%d", f.num[0] + i);
    for (int i = 0; i < (1 << n); i ++)
    {
        g.num[i][i] = 1;
        for (int j = 1; j < (1 << n); j <<= 1)
            g.num[i][i ^ j] = 1;
    }
    for (; t; t >>= 1)
    {
        if (t & 1) f = f * g;
        g = g * g;
    }
    for (int i = 0; i < (1 << n); i ++)
        printf("%d%c", f.num[0][i], i == (1 << n) - 1 ? '\n' : ' ');
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
