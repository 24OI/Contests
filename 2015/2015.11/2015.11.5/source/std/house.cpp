#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,c,ans,p[101000],d[101000];
bool check(int x)
{
    int i,last,num;
    last=p[1];
    num=c-1;
    for (i=2;i<=n;i++)
    if (p[i]-last>=x)
    {
        last=p[i];
        num--;
        if (num<=0)
        return true;
    }
    return false;
}
int main()
{
    int i,l,r,mid;
    freopen("house.in","r",stdin);
    freopen("house.out","w",stdout);
    cin>>n>>c;
    for (i=1;i<=n;i++)
    scanf("%d",&p[i]);
    sort(p+1,p+1+n);
    l=0;r=(p[n]-p[1])/(c-1);mid=(l+r)/2;
    while (l<r)
    {
      if (check(mid))
      {
       l=mid+1;
       ans=mid;
      }
      else
          r=mid-1;
      mid=(l+r)/2;
    }
    if (check(mid))
    ans=mid;
    cout<<ans<<endl;
}

