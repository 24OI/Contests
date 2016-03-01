#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b) {
    return b == 0?a:gcd(b,a % b);
}

struct Frac {
    long long a,b;
    Frac() {}
    Frac(long long ta,long long tb) {
        a = ta;
        b = tb;
        if (a == 0)
            b = 1;
        else {
            long long g = gcd(a,b);
            a /= g;
            b /= g;
        }
    }
    bool operator == (Frac y) {
        return a == y.a && b == y.b;
    }
    bool operator < (Frac y) {
        return a * y.b < y.a * b;
    }
    Frac operator - (Frac y) {
        long long k = b * y.b / gcd(b,y.b);
        long long xx = a * (k / b) - y.a * (k / y.b);
        return Frac(xx,k);
    }
    Frac operator * (Frac y) {
        return Frac(a * y.a,b * y.b);
    }
    Frac operator / (Frac y) {
        return Frac(a * y.b,b * y.a);
    }
};

struct Line {
    long long A,B,C;
};

struct Dat {
    Frac x,y;
    bool operator == (Dat b) {
        return x == b.x && y == b.y;
    }
};

Line l[1010];
int C[1010][4];
Dat a[1000010];
int mp[1000010];

bool cmp(Dat a,Dat b) {
    return a.x == b.x?a.y < b.y:a.x < b.x;
}

int main() {
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    int n;
    scanf("%d",&n);
    C[1][0] = C[1][1] = 1;
    C[2][0] = C[2][2] = 1;
    C[2][1] = 2;
    mp[C[2][2]] = 2;
    for (int i = 3; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= 2; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        mp[C[i][2]] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld",&l[i].A,&l[i].B,&l[i].C);
    int tot = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (l[i].A * l[j].B != l[i].B * l[j].A) {
                tot++;
                if (l[i].A == 0) {
                    a[tot].y = Frac(-l[i].C,l[i].B);
                    if (l[j].B == 0)
                        a[tot].x = Frac(-l[j].C,l[j].A);
                    else
                        a[tot].x = (Frac(l[i].C,1) - Frac(l[i].B * l[j].C,l[j].B)) / Frac(l[j].A * l[i].B,l[j].B);
                }
                else
                    if (l[j].A == 0) {
                        a[tot].y = Frac(-l[j].C,l[j].B);
                        if (l[i].B == 0)
                            a[tot].x = Frac(-l[i].C,l[i].A);
                        else
                            a[tot].x = (Frac(l[j].C,1) - Frac(l[j].B * l[i].C,l[i].B)) / Frac(l[i].A * l[j].B,l[i].B);
                    }
                    else
                        if (l[i].B == 0) {
                            a[tot].x = Frac(-l[i].C,l[i].A);
                            a[tot].y = (Frac(l[i].C,1) - Frac(l[i].A * l[j].C,l[j].A)) / Frac(l[j].B * l[i].A,l[j].A);
                        }
                        else
                            if (l[j].B == 0) {
                                a[tot].x = Frac(-l[j].C,l[j].A);
                                a[tot].y = (Frac(l[j].C,1) - Frac(l[j].A * l[i].C,l[i].A)) / Frac(l[i].B * l[j].A,l[i].A);
                            }
                            else {
                                a[tot].x = (Frac(l[i].B * l[j].C,l[j].B) - Frac(l[i].C,1)) / (Frac(l[i].A,1) - Frac(l[i].B * l[j].A,l[j].B));
                                a[tot].y = (Frac(l[i].A * l[j].C,l[j].A) - Frac(l[i].C,1)) / (Frac(l[i].B,1) - Frac(l[i].A * l[j].B,l[j].A));
                            }
            }
    sort(a + 1,a + tot + 1,cmp);
    int ans = 0,cnt = 0;
    for (int i = 1; i <= tot; i++) {
        int j = i;
        for (; j < tot && a[j + 1] == a[i]; j++);
        if (j - i + 1 > ans) {
            ans = j - i + 1;
            cnt = 1;
        }
        else
            if (j - i + 1 == ans)
                cnt++;
        i = j;
    }
    printf("%d %d\n",mp[ans],cnt);
    return 0;
}

