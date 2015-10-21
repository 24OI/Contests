#include <cstdio>  
using namespace std;  
int dp1[100000] = {0};  
int dp2[100000] = {0};  
int a[100000];  
int n=0;  
int main()  
{  	
freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++) scanf("%d",&a[i]);
  dp1[1] = 1;  
  int max;  
  int ans1 = 1;  
  for(int i=2; i<=n; i++)  
  {  
    max = 0;  
    for(int j=1; j<i; j++)  
    {  
      if(max<dp1[j] && a[j]>a[i]) max=dp1[j];  
    }  
    dp1[i] = max+1;  
    if(dp1[i]>ans1) ans1 = dp1[i];  
  }  
  
  int ans2 = 1;  
  dp2[1] = 1;  
  for(int i=2; i<=n; i++)  
  {  
    max = 0;  
    for(int j=1; j<i; j++)  
    {  
      if(max<dp2[j] && a[j]<a[i]) max = dp2[j];  
    }  
    dp2[i] = max + 1;  
    if(dp2[i] > ans2) ans2 = dp2[i];  
  }  
  printf("%d   %d",ans1,ans2);
	/* if (ans1+ans2==n) printf("%d",ans2);
	else printf("%d",ans2-1); */
  return 0;  
}  