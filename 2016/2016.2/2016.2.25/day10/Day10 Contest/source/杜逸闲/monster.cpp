#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define INF 0x3F3F3F3F
#define MAX_SIZE
#define Eps
#define Mod 593119681

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

class Matrix1
{
public:
	int N, M;
	long long A[70][70];
	
	inline Matrix1 operator * (Matrix1 const &a) const
	{
		Matrix1 temp;
		temp.N = N, temp.M = a.M;
		for(int i = 0; i < temp.N; ++i)
			for(int j = 0; j < temp.M; ++j)
			{
				temp.A[i][j] = 0;
				for(int k = 0; k < M; ++k)
					temp.A[i][j] = (temp.A[i][j] + A[i][k] * a.A[k][j]) % Mod;
			}
		return temp;
	}
	
	inline Matrix1 operator ^ (int k) const
	{
		Matrix1 temp, B = *this;
		temp.N = temp.M = N;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				temp.A[i][j] = 0;
		for(int i = 0; i < N; ++i)
			temp.A[i][i] = 1;
		while(k)
		{
			if(k & 1)
				temp = temp * B;
			k >>= 1;
			B = B * B;
		}
		return temp;
	}
};

int N, T;
long long A[1005][1025];

int main()
{
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	cin >> N >> T;
	if(N <= 6)
	{
		int M = pow(2, N);
		Matrix1 Ans1 = {0}, A1 = {0};
		Ans1.N = 1, Ans1.M = M;
		A1.N = A1.M = M;
		for(int i = 0; i < M; ++i)
			Ans1.A[0][i] = Read();
		for(int i = 0; i < M; ++i)
		{
			A1.A[i][i] = 1;
			for(int k = 1; k < M; k <<= 1)
				++A1.A[i ^ k][i];
		}
		Ans1 = Ans1 * (A1 ^ T);
		for(int i = 0; i < M; ++i)
			printf("%lld ", Ans1.A[0][i]);
	}
	else
	{
		int M = pow(2, N);
		for(int i = 0; i < M; ++i)
			A[0][i] = Read();
		for(int i = 1; i <= T; ++i)
			for(int j = 0; j < M; ++j)
			{
				A[i][j] = A[i - 1][j];
				for(int k = 1; k < M; k <<= 1)
					A[i][j] = (A[i][j] + A[i - 1][j ^ k]) % Mod;
			}
		for(int i = 0; i < M; ++i)
			printf("%lld ", A[T][i]);
	}
	return 0;
}
