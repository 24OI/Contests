#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<iostream>
#include<algorithm>
using namespace std;

const int _N=1010;
const int _S=_N*_N>>1;

class Number
{
public:
    long long p,q;
    Number(){}
    Number(long long _p,long long _q)
    {
        static long long _gcd;
        _gcd=__gcd(_p,_q);
        p=_p/_gcd,q=_q/_gcd;
    }
    void Print()
    {
        printf("%I64d/%I64d ",p,q);
    }
}x[_S],y[_S];
inline bool operator == (const Number &i,const Number &j)
{
    return (long double)i.p*j.q==(long double)i.q*j.p;
}
inline bool operator < (const Number &i,const Number &j)
{
    if((long double)i.p*i.q<=0&&(long double)j.p*j.q>=0)
        return 1;
    if((long double)i.p*i.q>=0&&(long double)j.p*j.q<=0)
        return 0;
    if((long double)i.p*i.q>0)
        return (long double)i.p*j.q<(long double)i.q*j.p;
    else
        return (long double)i.p*j.q>(long double)i.q*j.p;
}
int a[_N],b[_N],c[_N];
int n,Size,pla[_S];

inline bool see(const int &i,const int &j)
{
    if(x[i]==x[j])
        return y[i]<y[j];
    return x[i]<x[j];
}

int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",a+i,b+i,c+i);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]*b[j]==a[j]*b[i])
                continue;
            pla[++Size]=Size;
            x[Size]=Number((long long)c[j]*b[i]-(long long)c[i]*b[j],a[i]*b[j]-a[j]*b[i]);
            y[Size]=Number((long long)c[j]*a[i]-(long long)c[i]*a[j],a[j]*b[i]-a[i]*b[j]);
        }
    sort(pla+1,pla+Size+1,see);
   // for(int i=1;i<=Size;i++)
       // x[pla[i]].Print(),y[pla[i]].Print(),puts("");
    static int now,num,re;
    for(int i=1;i<=Size;i++)
    {
        if(i>1&&x[pla[i]]==x[pla[i-1]]&&y[pla[i]]==y[pla[i-1]])
            ++now;
        else
            now=1;
        if(now>re)
            re=now,num=1;
        else if(now==re)
            ++num;
    }
    printf("%d %d\n",(int)sqrt(re<<1)+1,num);
    return 0;
}
