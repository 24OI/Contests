#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define x1 x11
#define y1 y11

#ifdef LOCAL
    #define LLD "%lld"
    #define LLU "%llu"
#else
    #define LLD "%lld"
    #define LLU "%llu"
#endif

#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)

typedef long long LL;
typedef std::pair<int,int> PII;
typedef std::pair<PII,int> P;

const int MAXN = 1000033;
const double INF = 1e100;
const int inf = ~0u >> 2;
const double EPS = 1e-8;
const double delta = 0.85;

double st,ed;

void read();

void solve();

int main(){
#ifndef LOCAL
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif

#ifdef TI
    st = clock();
#endif

    read();
    solve();

#ifdef TI
    ed = clock();
    fpritnf(stderr,"%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif
    
#ifndef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}

int n;

int b[MAXN];

void read(){
    scanf("%d",&n);
    f(i,0,n - 1)scanf("%d",b + i);
}

LL res = 0;

bool ctf,notAble;

int val,pos,max;

int met[MAXN],pre;

void solve(){
    int mx;
    int ans = 0;

    memset(met,0,sizeof met);
    met[0] = 1;
    f(i,0,n - 1){
        if (!met[ b[i] - 1 ]){
            if ((b[i] >= 2 && !met[ b[i] - 2 ]) || (ctf && val != b[i] - 1)){
                notAble = 1;
            }
            if (!ctf){
                ctf = 1;
                val = b[i] - 1;
                pos = i;
            }
        }
        met[ b[i] ] = 1;
        res += max + 1;
        max = std::max(b[i],max);
    }
    res += max + 1;
    res -= n - 1;

    if (notAble){
        puts("0");
        return;
    }

    if (ctf){
        pre = -1;
        if (val == 1)pre = 0;
        f(i,0,n - 1){
            if (b[i] == val - 1){
                pos = i;
                break;
            }
        }
        printf("%d\n",pos - pre);
        return;
    }

    printf(LLD,res);

}

