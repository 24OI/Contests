#include	<cstdio>
#include	<cstring>
#include	<iostream>

using namespace std;
typedef long long data;

const int N = 128;
const int MOD = 593119681;

int n, m, T;

inline int Count(int x)
{
	int r = 0;
	while(x != 0)
	    x &= (x - 1), r ++;
	return r;
}

struct Matrix
{
    data a[N][N];

    Matrix() {memset(a, 0, sizeof(a));}

    Matrix operator * (const Matrix &b) const
    {
        Matrix c;
        for(int i = 0; i < n; i ++)
            for(int k = 0; k < n; k ++) if(a[i][k])
                for(int j = 0; j < n; j ++) if(b.a[k][j])
                {
                    c.a[i][j] += (a[i][k] * b.a[k][j]) % MOD;
                    if(c.a[i][j] >= MOD) c.a[i][j] %= MOD;
                }
        return c;
    }
} A, G, E;

inline Matrix pow(Matrix a, int k)
{
    Matrix r = E;
    while(k)
    {
        if(k & 1) r = r * a;
        a = a * a, k >>= 1;
    }
    return r;
}

int main(int argc, char **argv)
{
    freopen("monster.in", "r", stdin);
    freopen("monster.out", "w", stdout);

    scanf("%d%d", &m, &T);
    n = (1 << m);

    for(int i = 0; i < n; i ++)
        E.a[i][i] = 1LL;
    for(int i = 0; i < n; i ++)
        scanf("%I64d", &A.a[0][i]);
    
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(Count(i ^ j) == 1)
                G.a[i][j] = 1LL;
    for(int i = 0; i < n; i ++)
        G.a[i][i] = 1LL;

    A = A * pow(G, T);

    for(int i = 0; i < n; i ++)
        printf("%I64d ", A.a[0][i]);

    return 0;
}
