#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 593119681;
int n, rn, t, od[300000], ne[300000];
bool G[300000][30];
int splus(int lhs, int rhs){return (lhs%M+rhs%M)%M;}
int snow(int &lhs, int rhs){return lhs = splus(lhs, rhs);}
void raed()
{
	scanf("%d%d", &n, &t);
	rn = 1<<n;
	for(int i = 0; i < rn; ++i)
		scanf("%d", od+i);
}
void init()
{
	for(int i = 0; i < rn; ++i)
		for(int j = 0; j < n; ++j)
			if((i^(i+(1<<j))) == (1<<j)) G[i][j] = true;
}
void proces()
{
	for(int i = 0; i < rn; ++i)
		for(int j = 0; j < n; ++j)
		{
			if(G[i][j]) snow(ne[i+(1<<j)], od[i]);
			else snow(ne[i-(1<<j)], od[i]);
		}
	for(int i = 0; i < rn; ++i)
	{
		snow(od[i], ne[i]);
		ne[i] = 0;
	}
}
void printans()
{
	for(int i = 0; i < rn; ++i)
		printf("%d ", od[i]);
}
int main()
{
#ifndef snowoi
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
#endif
	raed();
	init();
	for(int i = 0; i < t; ++i)
		proces();
	printans();
	return 0;
}

