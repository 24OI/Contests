#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int va[maxn];
int a[maxn];
const int mod = 1e9 + 1;
int n, m;
int op, l, r;
int main() {
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= 10001; i++) {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= mod;
    }
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &va[i]);
    }
    while(m--) {
        scanf("%d %d %d", &op, &l, &r);
        if(op == 1) {
            for(int i = l ; i <= r; i++) {
                va[i] += a[i - l + 1];
                while(va[i] > mod) {
                    va[i] -= mod;
                }
            }
        } else {
            long long ans = 0;
            for(int i = l; i <= r; i++) {
                ans += va[i];
                while(ans > mod) {
                    ans -= mod;
                }
            }
            printf("%I64d\n", ans);
        }
    }
}
