#include	<cstdio>
#include	<cstring>
#include	<iostream>
#include    <algorithm>
#include    <vector>

using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 1;

inline int lowbit(int x)
{
    return x & (-x);
}

int n, Q, bit[N], sum[N], sum_[N], f[N];

inline void Modify(int p, int x)
{
    for(; p <= n; p += lowbit(p))
    {
        bit[p] += x;
        if(bit[p] >= MOD)
            bit[p] %= MOD;
    }
    return ;
}

inline int Query(int p)
{
    int r = 0;
    for(; p; p -= lowbit(p))
    {
        r += bit[p];
        if(r >= MOD)
            r %= MOD;
    }
    return r;
}

int main(int argc, char **argv)
{
    freopen("fibnacci.in", "r", stdin);
    freopen("fibnacci.out", "w", stdout);
    scanf("%d%d", &n, &Q);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &sum[i]);
    for(int i = 1; i <= n; i ++)
    {
        sum[i] += sum[i - 1];
        if(sum[i] >= MOD)
            sum[i] %= MOD;
    }
    f[0] = 0, f[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] >= MOD)
            f[i] %= MOD;
    }
    while(Q --)
    {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if(c == 1) for(int i = a; i <= b; i ++)
            Modify(i, f[i - a + 1]);
        else
            printf("%d\n", ((Query(b) - Query(a - 1) - sum[a - 1] + sum[b]) % MOD + MOD) % MOD);
    }
    return 0;
}
