#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define P 1000000001
#define N 100008
#define M 320

int n,m,size;
long long a[M][N],b[M][N],F[N],preF[N];
int flag[M];
long long sum[N];
int L,R;

int get_peice(int x)
{
	return (x-1)/size+1;
}

void init()
{
	int x;
	scanf("%d%d", &n, &m);
	size = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		a[get_peice(x)][x%size] = x;
		sum[get_peice(x)] += x;
	}
}

void Fwork()
{
	F[0] = 0;
	F[1] = 1;
	preF[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		F[i] = (F[i-1] + F[i-2]) % P;
		preF[i] = (preF[i-1] + F[i]) % P;
	}
}

void change1(int l,int r,int ll)
{
	for (int i = (r-1)%size; i >= (l-1)%size; i--)
	{
		a[ll][i] = (a[ll][i] + F[r-L+1]) % P;
		r--;
	}
	if (flag[ll])
	{
		a[ll][0] += b[ll][0] % P;
		a[ll][1] += b[ll][1] % P;
		for (int i = 2; i < size; i++)
		{
			b[ll][i] = (b[ll][i-1] + b[ll][i-2]) % P;
			a[ll][i] += b[ll][i] % P;
		}
		for (int i = 0; i < size; i++)
		{
			b[ll][i] = 0;
		}
		flag[ll] = 0;
	}
	sum[ll] = 0;
	for (int i = 0; i < size; i++)
	{
		sum[ll] = (sum[ll] + a[ll][i]) % P;
	}
}

void change(int l,int r)
{
	int ll = get_peice(l),rr = get_peice(r);
	if (ll == rr)
	{
		change1(l,r,ll);
	}
	else
	{
		for (int i = ll; i <= rr ;i++)
		{
			if (i == ll)
				change1(l,size*i,ll);
			else if (i == rr)
				change1(size*(i-1)+1,r,rr);
			else
			{
				flag[i] = 1;
				b[i][0] += F[(i-1)*size+2-L];
				b[i][1] +=F[(i-1)*size+3-L] ;
				sum[i] += preF[i*size-L+1] - preF[(i-1)*size-L+1];
			}
		}
	}
}

long long find1(int l,int r,int ll)
{
	long long ans = 0;
	if (flag[ll])
	{
		for (int i = 2; i < size; i++)
		{
			b[ll][i] = (b[ll][i-1] + b[ll][i-2]) % P;
			a[ll][i] += b[ll][i] % P;
		}
		for (int i = 0; i < size; i++)
		{
			b[ll][i] = 0;
		}
		flag[ll] = 0;
	}
	for (int i = (l-1)%size; i <= (r-1)%size; i++)
	{
		ans = (ans + a[ll][i]) % P;
	}
	return ans;
}

long long find(int l,int r)
{
	int ll = get_peice(l),rr = get_peice(r);
	long long ans = 0;
	if (ll == rr)
	{
		ans = find1(l,r,ll);
	}
	else
	{
		for (int i = ll; i <= rr ;i++)
		{
			if (i == ll)
				ans += find1(l,size*i,ll) % P;
			else if (i == rr)
				ans += find1(size*(i-1)+1,r,rr) % P;
			else
				ans += sum[i] % P;
		}
	}
	return ans % P;
}

void work()
{
	int x,y,z;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (y > z)
			swap(y,z);
		L = y;
		R = z;
		if (x == 1)
		{
			change(y,z);
		}
		if (x == 2)
		{
			printf("%lld\n",find(y,z)% P);
		}
	}
}


int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	init();
	Fwork();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
