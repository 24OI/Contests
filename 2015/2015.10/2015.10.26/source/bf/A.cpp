#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 330
using namespace std;
int n,ans;
int a[M],b[M];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,k;
	cin>>n;
	for(i=1;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(j!=a[i])
			{
				int temp=0;
				for(k=1;k<i;k++)
					b[++temp]=a[k];
				b[++temp]=j;
				for(k=i;k<n;k++)
					b[++temp]=a[k];
				temp=0;
				for(k=1;k<=n;k++)
				{
					if(b[k]>temp+1)
						break;
					temp=max(temp,b[k]);
				}
				if(k==n+1) ++ans;
			}
	cout<<ans<<endl;
	return 0;
}
