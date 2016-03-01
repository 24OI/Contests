#include <cstdio>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

int n,a,b,c,cnt1,cnt2;

int main()
{
    freopen("star.in","r",stdin);
    for (scanf("%d",&n); n--;)
    {
        scanf("%d%d%d",&a,&b,&c);
        if (-b+c==0)
            ++cnt1;
        if (-a-b+c==0)
            ++cnt2;
    }
    printf("%d %d\n",cnt1,cnt2);
    return 0;
}
