#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int a[100001],k;

void find(int x,int y, int b)
{
	int mid;
	int f;
	while (x<y)
	{
		mid=(x+y)/2;
		if (a[mid]>=b)
		{
			f=mid;
			y=mid;
			}
			else x=mid+1;
		}
		if (a[x]>=b) f=x;
			a[f]=b;
	}
int i,n,b;

int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	k=0;
	for (i=1;i<=n;i++)
	{	
		scanf("%d",&b);
		if (b>=a[k]) a[++k]=b;
			else find(1,k,b);
		}
	k=n-k;
	printf("%d",k);
	return 0;
	}