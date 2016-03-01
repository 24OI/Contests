#include <cstdio>
using namespace std;

const int maxn = 1e5+10;
const int Mod = 1e9+1;
int N, Q, s[maxn], f[maxn], check[maxn], far[maxn], w[maxn];

inline long long read()
{
	char ch = getchar(); long long sum = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') sum = sum*10 + ch - '0', ch = getchar();
	return sum;
}

void Modify(int l, int r)
{
	for(int i = l, j = 1; i <= r; i++, j++)
	s[i] = (long long)(s[i]+f[j])%Mod;
}

int query(int l, int r)
{
	int sum = 0;
	for(int i = l; i <= r; i++)
		sum = (long long)(sum+s[i])%Mod;
	return sum%Mod;
}

void MakeFib()
{
	f[1] = 1;
	for(int i = 2; i <= N; i++) f[i] = (long long)(f[i-1]+f[i-2])%Mod;
}

int main()
{
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	N = read(), Q = read();
	MakeFib();
	for(int i = 1; i <= N; i++) s[i] = read();
	for(int i = 1, op, l, r; i <= Q; i++)
	{
		op = read(), l = read(), r = read();
		if(op == 1) Modify(l, r);
		else printf("%d\n", query(l, r));
	}
	return 0;
}
