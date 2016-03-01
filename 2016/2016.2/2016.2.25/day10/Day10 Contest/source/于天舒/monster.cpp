#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const long long mod = 593119681ll;

struct Edge {
    int y;
    Edge *next;
};

Edge *b[1000010];
long long a[1000010],tmp[1000010];
int dfn[1000010];
int id;

bool check(int a,int b) {
    int x = a ^ b;
    int cnt = 0;
    for (; x > 0; x >>= 1)
        if (x & 1) {
            cnt++;
            if (cnt > 1)
                return 0;
        }
    return cnt == 1;
}

void addedge(int x,int y) {
    Edge *p = new Edge;
    p->y = y;
    p->next = b[x];
    b[x] = p;
}

void extend(int x) {
    for (Edge *i = b[x]; i != NULL; i = i->next)
        if (dfn[i->y] == id)
            tmp[i->y] = (tmp[i->y] + a[x]) % mod;
        else {
            dfn[i->y] = id;
            tmp[i->y] = a[x] % mod;
        }
}

int main() {
    freopen("monster.in","r",stdin);
    freopen("monster.out","w",stdout);
    int n,t;
    scanf("%d%d",&n,&t);
    n = (1 << n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
        a[i] %= mod;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (check(i,j)) {
                addedge(i,j);
                addedge(j,i);
            }
    for (; t--;) {
        id++;
        for (int i = 0; i < n; i++)
            if (a[i])
                extend(i);
        for (int i = 0; i < n; i++)
            if (dfn[i] == id)
                a[i] = (a[i] + tmp[i]) % mod;
    }
    for (int i = 0; i < n - 1; i++)
        printf("%lld ",a[i]);
    printf("%lld\n",a[n - 1]);
    return 0;
}

