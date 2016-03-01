#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<iostream>
#include<algorithm>
using namespace std;

const int _N=100010;
const int MOD=1000000001;

int f[_N],s[_N];
int n,m,sum[_N];

namespace Segment_Tree
{
    const int _S=_N<<2;
    
    int flag[_S],v[_S];
    
    void pushdown(int pla,int L,int R)
    {
        if(L==R)
            return;
        int M=L+R>>1,val=flag[pla];
        flag[pla]=0;
        if(flag[pla<<1])
            pushdown(pla<<1,L,M);
        flag[pla<<1]=val,v[pla<<1]+=(sum[val+M-L]-sum[val-1]+MOD)%MOD;
        if(v[pla<<1]>MOD)
            v[pla<<1]-=MOD;
        if(flag[pla<<1|1])
            pushdown(pla<<1|1,M+1,R);
        flag[pla<<1|1]=val+M+1-L,v[pla<<1|1]+=(sum[val+R-L]-sum[val+M-L]+MOD)%MOD;
        if(v[pla<<1|1]>MOD)
            v[pla<<1|1]-=MOD;
    }
    
    void Build(int pla,int L,int R)
    {
        int M=L+R>>1;
        if(L==R)
        {
            v[pla]=s[M]%MOD;
            return;
        }
        Build(pla<<1,L,M);
        Build(pla<<1|1,M+1,R);
        v[pla]=(v[pla<<1]+v[pla<<1|1])%MOD;
    }
    
    void Add(int pla,int L,int R,int qL,int qR,int p0)
    {
        int M=L+R>>1;
        if(flag[pla])
            pushdown(pla,L,R);
        if(L==qL&&R==qR)
        {
            v[pla]+=(sum[p0+R-L]-sum[p0-1]+MOD)%MOD;
            if(v[pla]>MOD)
                v[pla]-=MOD;
            flag[pla]=p0;
            return;
        }
        if(qR<=M)
            Add(pla<<1,L,M,qL,qR,p0);
        else if(qL>M)
            Add(pla<<1|1,M+1,R,qL,qR,p0);
        else
            Add(pla<<1,L,M,qL,M,p0),Add(pla<<1|1,M+1,R,M+1,qR,p0+M+1-qL);
        v[pla]=(v[pla<<1]+v[pla<<1|1])%MOD;
    }
    
    int Ask(int pla,int L,int R,int qL,int qR)
    {
        int M=L+R>>1;
        if(flag[pla])
            pushdown(pla,L,R);
        if(L==qL&&R==qR)
            return v[pla];
        if(qR<=M)
            return Ask(pla<<1,L,M,qL,qR);
        if(qL>M)
            return Ask(pla<<1|1,M+1,R,qL,qR);
        return (Ask(pla<<1,L,M,qL,M)+Ask(pla<<1|1,M+1,R,M+1,qR))%MOD;
    }
    
    void Init()
    {
        Build(1,1,n);
    }
}

int main()
{
    freopen("fibnacci.in","r",stdin);
    freopen("fibnacci.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",s+i);
    f[1]=f[2]=sum[1]=1,sum[2]=2;
    for(int i=3;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%MOD,sum[i]=(sum[i-1]+f[i])%MOD;
    Segment_Tree::Init();
    static int t,l,r;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t,&l,&r);
        if(t==1)
            Segment_Tree::Add(1,1,n,l,r,1);
        else
            printf("%d\n",Segment_Tree::Ask(1,1,n,l,r));
    }
    return 0;
}
