#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std;
const int MAX=100000;
bool isprime[MAX+1],can;
int total,tt,n,m,i,t,t2,t1,sum,num[100000];
int prime[MAX+1];
void makePrime()
{
    int i,j;
    memset(isprime,true,sizeof(isprime));
    for (i=4; i<=MAX; i+=2)
        isprime[i]=false;
    int m=sqrt(MAX);
    for (i=3; i<=m; i+=2)
    {
        if (isprime[i])
        {
            for (j=i+i; j<=MAX; j+=i)
                isprime[j]=false;
        }
    }
    total=1;
    prime[1]=2;
    for (i=3; i<=MAX; i+=2)
        if (isprime[i])
        {
            total++;
            prime[total]=i;
        }

}

int main()
{
    makePrime();
    int cas;
    freopen("present.in","r",stdin);
    freopen("present.out","w",stdout);
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d%d",&n,&m);
        tt=m;
        t2=n;
        can=true;
        t1=total;
        if (m==0)
            can=false;
        if (n==0)
            n=1;
        memset(num,0,sizeof(num));
        for (i=1; i<=total; i++)
        {

            while (m%prime[i]==0&&can)
            {
                num[i]++;
                m/=prime[i];
            }
        }
        if (m>1)
        {
            t1++;
            prime[t1]=m;
            num[t1]++;
        }
        for (i=1; i<=t1; i++)
            if (num[i]&&can)
            {
                sum=0;
                t=n;
                while (t)
                {
                    sum+=t/prime[i];
                    t/=prime[i];
                }
                if (sum<num[i])
                {
                    can=false;
                    break;
                }
            }
        if (can)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
