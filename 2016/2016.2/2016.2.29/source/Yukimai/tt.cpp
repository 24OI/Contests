#include <cstdio>
#include <cstring>
#include <algorithm>
#define yuki(x, y) for(int i = x; i < (y); ++i)
#define yukj(x, y) for(int j = x; j < (y); ++j)
#define yukii(x, y) for(int i = x; i <= (y); ++i)
#define yukji(x, y) for(int j = x; j <= (y); ++j)
#define yuk(x, y, z) for(int x = y; x < (z); ++x)
#define yui(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int destroy(int x)
{
	int ans = 0;
	for(int i = 2; x > 1; ++i)
		while(!(x%i)) x /= i, ++ans;
	return ans;
}
int m, n, k;
int main(int argc, char **argv)
{
	scanf("%d%d%d", &n, &m, &k);
//	freopen("D:\\a.cpp", "w", stdout);
//	printf("const int snow0[][100][100] = {");
//	yuk(k, 0, 11)
//	{
//		if(k > 1) putchar(',');
//		putchar('{');
//		for(int n = 10; n <= 1000; n += 10)
//		{
//			if(n > 10) putchar(',');
//			putchar('{');
//			for(int m = 10; m <= 1000; m += 10)
//			{
				int ans = 0;
				yukii(1, n)
					yukji(1, m)
						if(destroy(gcd(i, j)) <= k) ++ans;
//				if(m > 10) putchar(',');
				printf("%d", ans);
//			}
//			putchar('}');
//		}
//		putchar('}');
//	}
//	puts("};");
	return 0;
}

