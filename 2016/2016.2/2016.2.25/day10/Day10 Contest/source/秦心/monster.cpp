#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<iostream>
#include<algorithm>
using namespace std;

const int _S=1<<18;
const int MOD=593119681;

int n,t,s[_S];

namespace Solve1
{
    const int _N=1<<6;
    
    class Matrix
    {
    public:
        int f[_N][_N];
        void Zero()
        {
            for(int i=0;i<1<<n;i++)
                for(int j=0;j<1<<n;j++)
                    f[i][j]=0;
        }
        void One()
        {
            Zero();
            for(int i=0;i<1<<n;i++)
                f[i][i]=1;
        }
    }Base;
    
    inline Matrix operator * (const Matrix &a,const Matrix &b)
    {
        static Matrix c;
        c.Zero();
        for(int i=0;i<1<<n;i++)
            for(int j=0;j<1<<n;j++)
                for(int k=0;k<1<<n;k++)
                {
                    c.f[i][j]+=(long long)a.f[i][k]*b.f[k][j]%MOD;
                    if(c.f[i][j]>MOD)
                        c.f[i][j]-=MOD;
                }
        return c;
    }
    
    inline Matrix operator ^ (Matrix d,int p)
    {
        static Matrix re;
        re.One();
        while(p)
        {
            if(p&1)
                re=re*d;
            d=d*d;
            p>>=1;
        }
        return re;
    }
    
    int main()
    {
        for(int i=0;i<1<<n;i++)
        {
            for(int j=0;j<n;j++)
                Base.f[i][i^1<<j]=1;
            Base.f[i][i]=1;
        }
        Base=Base^t;
        for(int i=0;i<1<<n;i++)
        {
            static int re;
            re=0;
            for(int j=0;j<1<<n;j++)
            {
                re+=(long long)Base.f[j][i]*s[j]%MOD;
                if(re>MOD)
                    re-=MOD;
            }
            printf("%d%c",re,i+1^1<<n?' ':'\n');
        }
    }
}

namespace Solve2
{
    const int _N=1<<10;
    
    int f[_N][2];
    
    int main()
    {
        for(int i=0;i<1<<n;i++)
            f[i][0]=f[i][1]=s[i];
        static int now,last;
        now=1,last=0;
        for(int i=1;i<=t;i++,swap(now,last))
        {
            for(int j=0;j<1<<n;j++)
                for(int k=0;k<n;k++)
                {
                    f[j][now]+=f[j^1<<k][last];
                    if(f[j][now]>MOD)
                        f[j][now]-=MOD;
                }
            for(int j=0;j<1<<n;j++)
                f[j][last]=f[j][now];
        }
        for(int i=0;i<1<<n;i++)
            printf("%d%c",f[i][last],i+1^1<<n?' ':'\n');
    }
}

namespace Solve3
{
    int main()
    {
        return 0;
    }
}

int main()
{
    freopen("monster.in","r",stdin);
    freopen("monster.out","w",stdout);
    scanf("%d%d",&n,&t);
    for(int i=0;i<1<<n;i++)
        scanf("%d",s+i),s[i]%=MOD;
    if(n<=6)
        return Solve1::main();
    if(n<=10&&t<=1000)
        return Solve2::main();
    return Solve3::main();
}
