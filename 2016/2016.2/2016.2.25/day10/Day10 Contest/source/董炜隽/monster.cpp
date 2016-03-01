#include <cstdio>
#include <cstring>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

const int mod=593119681;
int n,m,t,f[1100][1024];

int main()
{
    freopen("monster.in","r",stdin);
    freopen("monster.out","w",stdout);
    scanf("%d%d",&n,&t),m=(1<<n)-1;
    repu(i,0,m)
        scanf("%d",&f[0][i]);
    repu(i,1,t)
    {
        memcpy(f[i],f[i-1],sizeof(f[i]));
        repu(j,0,m)
            for (int k=1; k<m; k<<=1)
                f[i][j]=(f[i][j]+f[i-1][j^k])%mod;
    }
    repu(i,0,m)
        printf("%d\n",f[t][i]);
    return 0;
}
