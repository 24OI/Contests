#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int p,n,m,t; 
bool als[500007];
int tt,ans;

int main()
{
	freopen("field.in","r",stdin);
	freopen("field.out","w",stdout);

	scanf("%d",&t);
//预处理筛
	for (int i=1;i<=500000;i++)
		for (int j=1;j<=500000/i;j++)
			{
				als[i*j]=1;	
			}

	for (int y=0;y<t;y++)
	{
		scanf("%d %d %d",&n,&m,&p);
		for (int i=1;i<=n;i++)
			if (als[i]=0) ans++;
		for (int i=1;i<=m;i++)
			if (als[i]=0) tt++;
		printf("%d\n",tt*ans);
	}

	return 0;
}