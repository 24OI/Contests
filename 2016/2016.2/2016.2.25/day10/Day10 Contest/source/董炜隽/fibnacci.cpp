#include <cstdio>
#include <cctype>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define lc x<<1
#define rc x<<1|1
#define mid (l+r>>1)
using namespace std;

typedef long long LL;
const LL mod=1000000001;
int n,m,ql,qr;
LL a[100100][2],sum[100100][2],tag[262144][2],s[262144],ans;
char ch;

inline int getint()
{
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

void add(int x,LL w0,LL w1,int len)
{
    tag[x][0]=(tag[x][0]+w0)%mod,tag[x][1]=(tag[x][1]+w1)%mod;
    s[x]=(s[x]+sum[len][0]*w0+sum[len][1]*w1)%mod;
}

void push_down(int x,int l,int r)
{
    if (!tag[x][0] && !tag[x][1])
        return;
    add(lc,tag[x][0],tag[x][1],mid-l+1);
    add(rc,(a[mid-l+1][0]*tag[x][0]+a[mid-l+1][1]*tag[x][1])%mod,(a[mid-l+2][0]*tag[x][0]+a[mid-l+2][1]*tag[x][1])%mod,r-mid);
    tag[x][0]=tag[x][1]=0;
}

void modify(int x,int l,int r,LL w)
{
    if (ql<=l && qr>=r)
    {
        add(x,w*a[l-ql][1]%mod,w*a[l-ql+1][1]%mod,r-l+1);
        return;
    }
    push_down(x,l,r);
    if (ql<=mid)
        modify(lc,l,mid,w);
    if (qr>mid)
        modify(rc,mid+1,r,w);
    s[x]=(s[lc]+s[rc])%mod;
}

void query(int x,int l,int r)
{
    if (ql<=l && qr>=r)
    {
        ans=(ans+s[x])%mod;
        return;
    }
    push_down(x,l,r);
    if (ql<=mid)
        query(lc,l,mid);
    if (qr>mid)
        query(rc,mid+1,r);
}

int main()
{
    freopen("fibnacci.in","r",stdin);
    freopen("fibnacci.out","w",stdout);
    scanf("%d%d",&n,&m);
    a[0][0]=a[1][1]=sum[1][1]=1;
    repu(i,2,n)
    {
        a[i][0]=(a[i-1][0]+a[i-2][0])%mod,a[i][1]=(a[i-1][1]+a[i-2][1])%mod;
        sum[i][0]=(a[i][0]+sum[i-1][0])%mod,sum[i][1]=(a[i][1]+sum[i-1][1])%mod;
    }
    repu(i,1,n)
        ql=qr=i,modify(1,1,n,getint()%mod);
    while (m--)
        if (getint()==1)
            ql=getint(),qr=getint(),modify(1,1,n,1);
        else
            ql=getint(),qr=getint(),ans=0,query(1,1,n),printf("%I64d\n",ans);
    return 0;
}
