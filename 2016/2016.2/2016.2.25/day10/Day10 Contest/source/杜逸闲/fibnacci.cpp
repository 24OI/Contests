#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define INF 0x3F3F3F3F
#define MAX_SIZE 100005
#define Eps
#define Mod 1000000007

inline int Read()
{
	int Num = 0;
	char ch;
	do
		ch = getchar();
	while(ch < '0' || ch > '9');
	do
	{
		Num = Num * 10 + ch - '0';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9');
	return Num;
} 

int N, M;
int A[MAX_SIZE], F[MAX_SIZE];

int main()
{
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	F[0] = 0;
	F[1] = 1;
	for(int i = 2; i <= 100000; ++i)
		F[i] = (F[i - 1] + F[i - 2]) % Mod;
	cin >> N >> M;
	for(int i = 1; i <= N; ++i)
		A[i] = Read();
	while(M--)
	{
		int O = Read(), L = Read(), R = Read();
		if(O == 1)
			for(int i = L; i <= R; ++i)
				A[i] += F[i - L + 1];
		else
		{
			int Ans = 0;
			for(int i = L; i <= R; ++i)
				Ans = (Ans + A[i]) % Mod;
			printf("%d\n", Ans);
		}
	}
	return 0;
}
