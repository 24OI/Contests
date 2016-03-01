#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define P 593119681
#define N 10008

int n,t;
long long sum[N][2];
struct road
{
	int to,next;
}r[5*N];
int f[N],top;

void build(int from,int to)
{
	r[++top].to = to;
	r[top].next = f[from];
	f[from] = top;
}

int dis(int i ,int j)
{
	int k = i^j,cnt = 0;
	while (k)
	{
		if (k&1)
			cnt++;
		k/=2;
	}
	return cnt;
}

void init()
{
	scanf("%d%d", &n, &t);
	n = (int)pow(2.0,n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &sum[i][0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dis(i,j) == 1)
			{
				build(i,j);
			}
		}
	}
}

void work()
{
	for (int k = 1; k <= t; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = f[i]; j; j = r[j].next)
			{
				sum[r[j].to][1] = (sum[r[j].to][1] + sum[i][0]) % P;
			}
		}
		for (int i = 0; i < n; i++)
		{
			sum[i][0] = (sum[i][0] + sum[i][1]) % P;
			sum[i][1] = 0;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", sum[i][0] % P);
}

int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	init();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}