#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long ll;
int a[1000010];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
    int n;
    scanf("%d",&n);
    ll ans=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
	if(a[1]==2)
	{
		printf("1\n");
		return 0;
	}else if(a[1]>2)
	{
		printf("0\n");
		return 0;
	}
    int ma=-1;
    for(int i=1;i<n;i++)
    {
        ma=max(ma,a[i]);
		if(ma>i)
		{
			printf("0\n");
			return 0;
		}
        ans+=ma;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
}

