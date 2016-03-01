#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define N 100010
#define Mod 1000000001

int n,m;
int Fi[N],A[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void Prepare()
{
	Fi[0]=0;Fi[1]=1;
	for(int i=2;i<=100000;i++)
		Fi[i]=(Fi[i-1]+Fi[i-2])%Mod;
}

int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	n=read();m=read();
	Prepare();
	for(int i=1;i<=n;i++)
		A[i]=read();
	if(n<=1000&&m<=1000)
	{
		for(int i=1;i<=m;i++)
		{
			int kind=read(),l=read(),r=read();
			if(kind==1)
			{
				for(int j=l;j<=r;j++)
				{
					int pos=j-l+1;
					A[j]=(A[j]+Fi[pos])%Mod;
				}
			}
			else 
			{
				int sum=0;
				for(int i=l;i<=r;i++)
					sum=(sum+A[i])%Mod;
				printf("%d\n",sum);
			}
		}
		return 0;
	}
	else 
	{
		for(int i=1;i<=m;i++)
		{
			int kind=read(),l=read(),r=read();
			printf("zy!\n");
		}
	}
	return 0;
}
