#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

long long l,r;
int prime[2000001];
bool isprime[2000001];
int sum;
int num=0;

void Eula(long long n)
{
	memset(isprime,true,sizeof(isprime));
	for (int i=2;i<=n;++i)
	{
		if (isprime[i]) prime[++num]=i;
		for (int j=1;j<=num&&i*prime[j]<=n;++j)
		{
			isprime[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
	return;
}

void solve1()
{
	Eula(r);
	for (int i=l;i<=r;++i)
	{
		if (isprime[i])s
		{
			printf("%d\n", i);
			continue;
		}

		for (int j=1;;++j)
		{
			if (i%prime[j]==0)
			{
				printf("%d\n",prime[j]);
				break;
			}
		}
	}
	return;
}

int main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	cin >>l>>r;

	if (l==2&&r<=1000000)
	{
		solve1();
		return 0;
	}
	return 0;
}
