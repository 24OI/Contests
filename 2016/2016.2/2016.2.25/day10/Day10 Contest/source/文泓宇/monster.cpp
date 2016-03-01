#include <cstdio>
#include <cstring>
using namespace std;


const int maxn = (1<<18)+10;
const int Mod = 593119681;
long long sum[2][maxn];
int N, T, cur = 1, pre = 0;

inline long long read()
{
	char ch = getchar(); long long sum = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') sum = sum*10 + ch - '0', ch = getchar();
	return sum;
}

int main()
{
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	N = read(), T = read();
	for(int i = 0; i < (1<<N); i++) sum[pre][i] = read()%Mod;
	for(int i = 1; i <= T; i++)	
	{
		for(int j = 0; j < (1<<N); j++)
		{
			sum[cur][j] += sum[pre][j];
			for(int k = 0; k < N; k++)
				(sum[cur][j^(1<<k)] += sum[pre][j]) %= Mod;
		}
		pre ^= 1, cur ^= 1;
		for(int j = 0; j < (1<<N); j++) sum[cur][j] = 0;
	}
	for(int i = 0; i < (1<<N); i++)
		printf("%lld ", sum[pre][i]%Mod);
	return 0;
}
