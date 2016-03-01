#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int raw[100010], n, f[100010], m;
const int M = (int)10e9+1;
int splus(int lhs, int rhs)
{
	return (lhs+rhs)%M;
}

void raed()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", raw+i);
	f[1] = f[2] = 1;
	for(int i = 3; i <= n+3; ++i)
		f[i] = splus(f[i-1], f[i-2]);
}
void snow()
{
	while(m--)
	{
		int t1, t2, t3;
		scanf("%d%d%d", &t1, &t2, &t3);
		if(t1 == 1)
			qplus(root, t2, t3, 1, t3-t2+1);
		else
			printf("%d\n", qsum(root, t2, t3));
	}
}
int main()
{
#ifndef snowoi
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
#endif
	raed();
	root = maketree(1, n);
	snow();
	return 0;
}

