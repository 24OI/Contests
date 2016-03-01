#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define M 1050
#define MOD 593119681
using namespace std;
int n,t;
struct xing
{
	int next,now;
}
a[M];
int du[M];
struct node
{
	int a,b,next;
}e[M*2];
int p[M*2];
int num;
int numm;
void add(int x,int y)
{
	numm++;
	e[numm].next=p[x];
	p[x]=numm;
	e[numm].a=x;
	e[numm].b=y;
}

int fresh(int x)
{
	int tmp=1;
	for(int i=1;i<=x;i++)
	{
		tmp*=2;
	}
	return tmp;
}
bool judge(int x)
{
	int nummm=0;
	while(x>0)
	{
		if(x%2==1)
		{
			nummm++;
		}
		x/=2;
	}
	if(nummm!=1)return false;
	return true;
}

void yu()
{
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(i!=j)
			{
				int q=i^j;
				if(judge(q))
				{
					add(i,j);
				}
			}
		}
	}
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	num=fresh(n);
	for(int i=0;i<num;i++)
		scanf("%d",&a[i].now);
	yu();
	for(int i=1;i<=t;i++)
	{
		for(int i=0;i<num;i++)
		{
			for(int j=p[i];j;j=e[j].next)
			{
				int v=e[j].b;
				a[i].next+=a[v].now%MOD;
			}
		}
		for(int i=0;i<num;i++)a[i].now+=a[i].next%MOD,a[i].next=0;
		
	}
	for(int i=0;i<num;i++)
	{
		printf("%d ",a[i].now%MOD);
	}
	printf("\n");
	return 0;
	
}
