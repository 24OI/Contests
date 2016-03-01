#include <cstdio>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

typedef long long LL;
const LL mod=1009;
int n,tot,h[1100][1100],x,y,ans1,ans2;
LL a[1100],b[1100],c[1100],d;
struct point
{
    LL x,y,m;
    int cnt,hx,hy;
    inline bool operator==(const point t)
    {
        return x==t.x && y==t.y && m==t.m;
    }
} p[1100],t;
struct edge
{
    int v;
    edge *nxt;
} pool[1100],*tp=pool,*fst[1100][1100];

LL gcd(LL x,LL y)
{
    if (!x || !y)
        return x+y;
    LL t;
    for (; t=x%y; x=y,y=t);
    return y;
}

void add()
{
    t.hx=((t.x*233+t.y)%mod+mod)%mod,t.hy=(t.m%mod+mod)%mod;
    for (edge *i=fst[t.hx][t.hy]; i; i=i->nxt)
        if (p[i->v]==t)
        {
            ++p[i->v].cnt;
            return;
        }
    (p[++tot]=t).cnt=2;
    *tp=(edge){tot,fst[t.hx][t.hy]},fst[t.hx][t.hy]=tp++;
}

int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    repu(i,1,n)
        scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
    repu(i,1,n)
    {
        repu(j,i+1,n)
            if (t.m=a[i]*b[j]-a[j]*b[i])
            {
                t.x=b[i]*c[j]-b[j]*c[i];
                t.y=a[j]*c[i]-a[i]*c[j];
                d=gcd(gcd(t.x,t.y),t.m),t.x/=d,t.y/=d,t.m/=d;
                if (t.m<0)
                    t.x=-t.x,t.y=-t.y,t.m=-t.m;
                add();
            }
        repu(j,1,tot)
        {
            if (p[j].cnt>ans1)
                ans1=p[j].cnt,ans2=1;
            else
                if (p[j].cnt==ans1)
                    ++ans2;
            fst[p[j].hx][p[j].hy]=NULL;
        }
        tp=pool,tot=0;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
