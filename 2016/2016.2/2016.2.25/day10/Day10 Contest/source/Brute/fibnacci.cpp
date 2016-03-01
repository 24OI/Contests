#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define Mod 1000000001

int n, m, A[N];

inline int Inc(int a, int b)
{
    return a + b - (a + b >= Mod ? Mod : 0);
}

int main()
{
    freopen("fibnacci.in", "r", stdin);
    freopen("fibnacci.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    while (m --)
    {
        int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if (op == 1)
        {
            int a = 1, b = 1;
            for (int i = 0; u <= v; i ++, u ++)
            {
                A[u] = Inc(A[u], a);
                b = Inc(a, b);
                a = Inc(b, Mod - a);
            }
        }
        else
        {
            int res = 0;
            for (; u <= v; u ++) res = Inc(res, A[u]);
            printf("%d\n", res);
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
