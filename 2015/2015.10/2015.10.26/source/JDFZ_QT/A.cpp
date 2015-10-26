#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
int n,maxn;
ll ans;
int a[N];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)scanf("%d",&a[i]);
	int x=n-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxn+2)
		{
			puts("0");
			return 0;
		}else if(a[i]>maxn+1)
		{
			puts("1");
			return 0;
		}
		ans+=(ll)(maxn+1);
		maxn=max(maxn,a[i]);
	}
	cout<<ans-(ll)x<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
