#include <cstdio>
#include <cctype>
#define NAME "fibnacci"
#undef INT
#define INT long long
#define N_MAX 100003
#define MOD 1000000001LL
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
INT fib[N_MAX];
struct seg // [l, r) <=> [l, m)U[m, r)
{
    INT l, m, r, sum, fib;
    seg * pl, * pr;
} seg_pool[N_MAX << 1], * seg_cur = seg_pool;
inline seg * seg_node(INT p, INT v)
{
    *seg_cur = (seg) {p, p, p + 1, v, 0, NULL, NULL};
    return seg_cur++;
}
inline seg * seg_node(INT l, INT m, INT r, seg * pl, seg * pr)
{
    *seg_cur = (seg) {l, m, r, ((pl ? pl->sum : 0) + (pr ? pr->sum : 0)) % MOD, 0, pl, pr};
    return seg_cur++;
}
inline seg * seg_build(INT l, INT r, const INT a[])
{
    //if (l == r) return NULL;
    if (l + 1 == r) return seg_node(l, a[l]);
    INT m = (l + r) >> 1;
    return seg_node(l, m, r, seg_build(l, m, a), seg_build(m, r, a));
}
inline void seg_update(seg * w)
{
    if (w->pl) w->sum = (w->pl->sum + w->pr->sum) % MOD;
}
void seg_pushdown(seg * w)
{
    if (w->pl && w->fib)
    {
        seg_pushdown(w->pl); seg_pushdown(w->pr);
        w->pl->fib = w->fib;
        w->pl->sum = ((w->pl->sum + fib[w->pl->fib - w->l + w->m - 1] - fib[w->pl->fib - 1]) % MOD + MOD) % MOD;
        w->pr->fib = w->fib - w->l + w->m;
        w->pr->sum = ((w->pr->sum + fib[w->pr->fib - w->m + w->r - 1] - fib[w->pr->fib - 1]) % MOD + MOD) % MOD;
        w->fib = 0;
    }
}
void seg_modify(seg * w, INT l, INT r, INT f = 1)
{
    seg_pushdown(w);
    if (l == w->l && r == w->r)
    {
        w->fib = f;
        w->sum = ((w->sum + fib[f - w->l + w->r - 1] - fib[f - 1]) % MOD + MOD) % MOD;
    }
    else
    {
        if (r <= w->m) seg_modify(w->pl, l, r, f);
        else if (l >= w->m) seg_modify(w->pr, l, r, f);
        else seg_modify(w->pl, l, w->m, f), seg_modify(w->pr, w->m, r, f - l + w->m);
        seg_update(w);
    }
}
INT seg_sum(seg * w, INT l, INT r)
{
    seg_pushdown(w);
    if (l == w->l && r == w->r) return w->sum;
    else if (r <= w->m) return seg_sum(w->pl, l, r);
    else if (l >= w->m) return seg_sum(w->pr, l, r);
    else return (seg_sum(w->pl, l, w->m) + seg_sum(w->pr, w->m, r)) % MOD;
}
INT n, m, i, a[N_MAX], op, l, r, f0 = 0, f1 = 1, f2;
seg * T;
int main()
{
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
    I(n); I(m);
    for (fib[0] = 0, fib[1] = 1, i = 2; i <= n; ++i) // prefix-sum of fib
    {
        fib[i] = (fib[i - 1] + (f2 = (f0 + f1) % MOD)) % MOD;
        f0 = f1; f1 = f2;
    }
    //for (i = 0; i <= n; ++i) printf("fib["), O(i), printf("] = "), O(fib[i]), putchar('\n');
    for (i = 0; i < n; ++i) I(a[i]);
    T = seg_build(0, n, a);
    while (m--)
    {
        I(op); I(l); I(r);
        switch (op)
        {
            case 1: seg_modify(T, l - 1, r); break;
            case 2: O(seg_sum(T, l - 1, r)); putchar('\n'); break;
        }
//#ifdef dDEBUG
        //for (i = 0; i < n; ++i)
            //O(seg_sum(T, i, i + 1)), putchar(' ');
        //putchar('\n');
//#endif
    }
    return 0;
}
