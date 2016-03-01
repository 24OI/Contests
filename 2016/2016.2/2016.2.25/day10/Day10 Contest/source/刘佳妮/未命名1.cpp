#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define N 1008

int n,cnt;
int A[N],B[N],C[N];
struct node
{
	long long xz,xm;
	long long yz,ym;
}point[N*N];
int ff[N],flag[N*N];

void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
	}
	ff[1] = 0;
	ff[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		ff[i] = ff[i-1]+i-1;
	}
	for (int i = 1; i <= n; i++)
	{
		flag[ff[i]] = i;
	}
}

int check(int a1,int b1,int a2,int b2)
{
	int t1 = a1*b2 ,t2 = a2*b1;
	if (t1 < t2)
		return 1;
	else if (t1 == t2)
		return 0;
	return -1;
}

bool cmp(const node &k1, const node &k2)
{
	int t = check(k1.xz, k2.xm,k2.xz,k2.xm);
	if (t == 1)
		return true;
	else if (t == 0)
		if (check(k1.yz, k2.ym,k2.yz,k2.ym) != -1)
			return true;
	return false;
}

void work()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			cnt ++;
			if (A[i] == 0)
			{
				point[cnt].yz = C[i];
				point[cnt].ym = B[i];
				point[cnt].xz = point[cnt].yz*B[j] + point[cnt].ym*C[j];
				point[cnt].xm = -A[j] * point[cnt].ym;
			}
			else if (A[j] == 0)
			{
				point[cnt].yz = C[j];
				point[cnt].ym = B[j];
				point[cnt].xz = point[cnt].yz*B[i] + point[cnt].ym*C[i];
				point[cnt].xm = -A[i] * point[cnt].ym;
			}
			else if (B[i] == 0)
			{
				point[cnt].xz = C[i];
				point[cnt].xm = A[i];
				point[cnt].yz = -A[j] * point[cnt].xz - C[j]*point[cnt].xm;
				point[cnt].ym = B[j] * point[cnt].xm;
			}
			else if (B[j] == 0)
			{
				point[cnt].xz = C[i];
				point[cnt].xm = A[i];
				point[cnt].yz = -A[i] * point[cnt].xz - C[i]*point[cnt].xm;
				point[cnt].ym = B[i] * point[cnt].xm;
			}
			else
			{
				point[cnt].xz = C[j]*B[i] - B[j]*C[i];
				point[cnt].xm = A[i]*B[j]-A[j]*B[i];
				point[cnt].yz = -A[i] * point[cnt].xz - C[i]*point[cnt].xm;
				point[cnt].ym = B[i] * point[cnt].xm;
			}
		}
	}
	sort(point+1,point+1+cnt,cmp);
	int maxn = 0,cont = 0,ans = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (check(point[i].xz,point[i].xm,point[i-1].xz,point[i-1].xm) == 0 && check(point[i].yz,point[i].ym,point[i-1].yz,point[i-1].ym) == 0)
		{
			cont++;
		}
		if (flag[cont+1] > maxn)
		{
			maxn = flag[cont+1];
			ans = 1;
		}
		else if (flag[cont+1]  == maxn)
		{
			ans++;
		}
		cont = 0;
	}
	printf("%d %d\n", maxn, ans);
}

int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	init();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
