#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,t,m,c;
int a[262147];
struct
{
	int to;
	int next;
	}	b[262147];
int next[262147];
int y,tt;
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	
	scanf("%d %d",&n,&t);
	m=1;
	while (n!=0)
	{
		m=m<<1;
		n=n>>1;
		}
	for (int i=0;i<m;i++)
		scanf("%d",&a[i]);
	tt=0;
	for (int i=0;i<=1024;i++)
		for (int j=0;j<=1024;j++)
		{
			y=i xor j;
			c=0;
			if (y=0) continue;
			while (y!=0)
			{
				if (y&1==1) c++;
				y=y>>1;
				}
			if (c==1) 
				{
					b[tt].to=j;
					b[tt].next=next[i];
					next[i]=tt;
					tt++;
					};
			}
	while (t!=0)
	{
		
		t--;
		}
	for (int i=0;i<m;i++)
		printf("%d ",a[i]);
	
	return 0;
	}