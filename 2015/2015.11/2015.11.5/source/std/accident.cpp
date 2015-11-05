#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std ;
const int INF=0xfffffff ;
int dp[2001][2001] ;
int sumA[2001] ;
typedef struct L{
    int a,b ;
    int temp ;
}L ;
L kk[2001] ;
bool cmp(L a,L b)
{
    return a.temp>b.temp ;
}
int main()
{
    int n ;
    freopen("accident.in","r",stdin);
    freopen("accident.out","w",stdout);
    scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&kk[i].a,&kk[i].b) ;
            kk[i].temp=kk[i].a+kk[i].b ;
        }
        int h ;
        scanf("%d",&h) ;
        sort(kk,kk+n,cmp) ;
        sumA[0]=kk[0].a ;
        for(int i=1;i<n;i++)
            sumA[i]=sumA[i-1]+kk[i].a ;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=INF ;
        dp[0][0]=0 ;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=i;j++)
            {
                if(j)
                    dp[i][j]=min(dp[i-1][j]-kk[i-1].a,max(dp[i-1][j-1],h-sumA[i-1]-kk[i-1].b)) ;
                else
                    dp[i][j]=min(dp[i-1][j]-kk[i-1].a,h-sumA[i-1]-kk[i-1].b) ;
            }
        int i ;
        for(i=n;i>=0;i--)
            if(dp[n][i]<=0)
                break ;
        printf("%d\n",i) ;
    return 0 ;
}
