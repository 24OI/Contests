#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define RD rand()/(double)RAND_MAX
using namespace std;
int main()
{
	srand(time(0));
	freopen("monster.in", "w", stdout);
	puts("10 1000");
	for(int i = 0; i < 1024; ++i)
		printf("%d ", rand());
	puts("");
	return 0;
}

