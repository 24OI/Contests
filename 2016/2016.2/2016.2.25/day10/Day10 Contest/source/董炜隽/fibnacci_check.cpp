#include <cstdio>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

const int mod=1000000001;

int n,m,w[100100],f[100100],ans,l,r,opt;

int main()
{
    freopen("fibnacci.in","r",stdin);
    freopen("fibnacci_check.out","w",stdout);
    scanf("%d%d",&n,&m);
    repu(i,1,n)
        scanf("%d",&w[i]),w[i]%=mod;
    f[1]=1;
    repu(i,2,n)
        f[i]=(f[i-1]+f[i-2])%mod;
    while (m--)
    {
        scanf("%d%d%d",&opt,&l,&r),ans=0;
        repu(i,l,r)
            if (opt==1)
                w[i]=(w[i]+f[i-l+1])%mod;
            else
                ans=(ans+w[i])%mod;
        if (opt==2)
            printf("%d\n",ans);
    }
    return 0;
}
