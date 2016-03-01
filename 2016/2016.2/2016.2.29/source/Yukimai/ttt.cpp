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
int shai[1010], num[1010];
int main(int argc, char **argv)
{
	freopen("D:\\b.cpp", "w", stdout);
	yukii(2, 1000) num[i] = i;
	printf("{0,0");
	yukii(2, 1000)
	{
		if(!shai[i])
			for(int j = i; j <= 1000; j += i)
				while(!(num[j] % i))num[j] /= i, ++shai[j];
		printf(",%d", shai[i]);
	}
	return 0;
}

