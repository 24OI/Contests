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
/*const int snow[][4] = {{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}, 
	{1, 0, 2, 3}, {1, 0, 3, 2}, {1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0}, 
	{2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3}, {2, 1, 3, 0}, {2, 3, 0, 1}, {2, 3, 1, 0},
	{3, 0, 1, 2}, {3, 0, 2, 1}, {3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0}};*/
int n, d, ans;
char sno[50010][6];
void sread()
{
	scanf("%d%d", &n, &d);
	yuki(0, n)
		scanf("%s", sno[i]);
}
int scmp(char *a, char *b)
{
	int res = 0;
	yuki(0, 4)
		if(a[i] != b[i]) ++res;
	return res;
}
int main(int argc, char **argv)
{
#ifndef snowoi
	freopen("idioms.in", "r", stdin);
	freopen("idioms.out", "w", stdout);
#endif
	sread();
	yuki(0, n)
		yukj(i+1, n)
			if(scmp(sno[i], sno[j]) == d) ++ans;
	printf("%d\n", ans);
	return 0;
}
