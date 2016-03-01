#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000001;

struct Treenode {
    pair<int,int> tag;
    int s;
};

Treenode t[400400];
pair<int,int> f[100100],s[100100];
int pre[100010];

int add(int a,int b) {
    return (((long long)a) + ((long long)b) + ((long long)mod)) % mod;
}

int mul(int a,int b) {
    return ((long long)a) * ((long long)b) % mod;
}

pair<int,int> add(pair<int,int> a,pair<int,int> b) {
    return make_pair(add(a.first,b.first),add(a.second,b.second));
}

pair<int,int> mul(pair<int,int> a,pair<int,int> b) {
    return make_pair(mul(a.first,b.first),mul(a.second,b.second));
}

void mutate(int k,int sz,pair<int,int> x) {
    pair<int,int> tmp = mul(s[sz],x);
    t[k].s = add(t[k].s,add(tmp.first,tmp.second));
}

void lazylabel(int k,int l,int r) {
    if (r - l <= 1)
        return;
    int mid = (l + r) >> 1;
    mutate(k << 1,mid - l,t[k].tag);
    t[k << 1].tag = add(t[k << 1].tag,t[k].tag);
    pair<int,int> t1 = mul(f[mid - l],t[k].tag),t2 = mul(f[mid - l + 1],t[k].tag);
    pair<int,int> tmp = make_pair(add(t1.first,t1.second),add(t2.first,t2.second));
    mutate(k << 1 | 1,r - mid,tmp);
    t[k << 1 | 1].tag = add(t[k << 1 | 1].tag,tmp);
    t[k].tag = make_pair(0,0);
}

void modify(int k,int l,int r,int ql,int qr) {
    if (l >= qr || r <= ql)
        return;
    if (l >= ql && r <= qr) {
        pair<int,int> tmp = make_pair(f[l - ql + 1].second,f[l - ql + 2].second);
        mutate(k,r - l,tmp);
        t[k].tag = add(t[k].tag,tmp);
        return;
    }
    lazylabel(k,l,r);
    int mid = (l + r) >> 1;
    modify(k << 1,l,mid,ql,qr);
    modify(k << 1 | 1,mid,r,ql,qr);
    t[k].s = add(t[k << 1].s,t[k << 1 | 1].s);
}

int query(int k,int l,int r,int ql,int qr) {
    if (l >= qr || r <= ql)
        return 0;
    if (l >= ql && r <= qr)
        return t[k].s;
    lazylabel(k,l,r);
    int mid = (l + r) >> 1;
    return add(query(k << 1,l,mid,ql,qr),query(k << 1 | 1,mid,r,ql,qr));
}

int main() {
    freopen("fibnacci.in","r",stdin);
    freopen("fibnacci.out","w",stdout);
    f[0] = make_pair(1,0);
    f[1] = make_pair(0,1);
    for (int i = 2; i < 100090; i++)
        f[i] = add(f[i - 1],f[i - 2]);
    for (int i = 0; i < 100089; i++)
        s[i + 1] = add(s[i],f[i]);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        pre[i + 1] = add(x,pre[i]);
    }
    for (int i = 0; i < m; i++) {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        l--;
        if (op == 2)
            printf("%d\n",add(query(1,0,n,l,r),add(pre[r],-pre[l])));
        else
            modify(1,0,n,l,r);
    }
    return 0;
}

