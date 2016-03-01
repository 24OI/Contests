#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[10001000], ans, k, n;
inline int getint()
{
	char ch = getchar();
	int ret = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	do
	{
		ret = ret*10+(ch-'0');
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return ret;
}
int main()
{
#ifndef O233
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
#endif
	n = getint();
	for(int i = 1; i <= n; ++i)
	{
		b[i] = getint();
		k = i;
		int smin = b[i];
		for(int j = i-1; j > 0; --j)
		{
			if(b[j] <= smin)
			{
				k = j;
				smin = b[j];
 			}else if(b[j] > b[i]) break;
		}
		ans = max(ans, i-k+1);
	}
	printf("%d\n", ans);
	return 0;
}

