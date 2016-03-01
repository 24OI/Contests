#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define RD rand()/(double)RAND_MAX
using namespace std;
int rando(int b, int e)
{
	int r = RD*(e-b);
	return r+b;
}
int main(int argc, char **argv)
{
#ifndef snowoi
	srand(time(0));
	freopen("fibnacci.in", "w", stdout);
#endif
#ifdef snowoi
	srand(time(0)+atoi(argv[1]));
#endif
	puts("1000 1000");
	for(int i = 0; i < 1000; ++i)
		printf("%d ", rand());
	puts("");
	for(int i = 0; i < 1000; ++i)
		printf("%d %d %d\n", RD<0.5 ? 1 : 2, rando(1, 500), rando(501, 1000));
	return 0;
}

