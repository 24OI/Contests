#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <map>
using namespace std;
struct node
{
    int l;
    int r;
    int cost;
    friend bool operator <(const node &a,const node &b)
    {
        return a.cost<b.cost;
    }
}a[2010];
int g[4010];
int cnt=0;
int ct=0;
int left[4010];
int v[4010];
map <int ,int >use;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ans=m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        left[++ct]=a[i].l;
        if(use[a[i].l]==0)
        {
            use[a[i].l]=1;
            g[++cnt]=a[i].l;
        }
        if(use[a[i].r]==0)
        {
            use[a[i].r]=1;
            g[++cnt]=a[i].r;
        }
    }
    sort(g+1,g+1+cnt);
    for(int i=1;i<=cnt;i++)
    {
        use[g[i]]=i;
    }
    for(int i=1;i<=ct;i++)
    {
    	left[i]=use[left[i]];
    	v[left[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int le=use[a[i].l];
        int ri=use[a[i].r];
        le++;
        ri--;
        a[i].cost=g[le]-a[i].l+a[i].r-g[ri];
        if(le>ri)
        {
            a[i].cost/=2;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-k;i++)
    {
        ans-=a[i].cost;
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
}

