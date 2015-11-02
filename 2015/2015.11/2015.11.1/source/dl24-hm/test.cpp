#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define f(i,j,k) for(i=j;i<=k;++i)
#define ln printf("\n")

int n, m;
int a[100];

int main()
{
	freopen("test.out", "w", stdout);
	srand(time(NULL));
	scanf("%d", &n);
	
	int i, j, k, x, y, z, sum;
	f(i, 1, n) a[i] = i;
	scanf("%d", &m);
	f(i, 1, m)
	{
		x = rand() % n + 1;
		y = rand() % n + 1;
		while (x == y) y = rand() % n + 1;
		if (x > y)
		{
			z = x; x = y; y = z;
		}
		z = a[x]; a[x] = a[y]; a[y] = z;
		// f(j, 1, n) printf("%d ", a[j]); ln;
		sum = 0;
		f(j, 1, n - 1) f(k, j + 1, n) if (a[j] > a[k]) ++sum;
		printf("%d\n", sum % 2);
	}
	
	
	return 0;
}