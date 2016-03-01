#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define INF 0x3F3F3F3F
#define MAX_SIZE 1005
#define Eps 1e-6
#define Mod 1000000007

inline int Read()
{
	int Num = 0, Flag = 1;
	char ch;
	do
	{
		ch = getchar();
		if(ch == '-')
			Flag = -1;
	}
	while(ch < '0' || ch > '9');
	do
	{
		Num = Num * 10 + ch - '0';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9');
	return Num * Flag;
} 

struct Point
{
	double x, y;
};

int N, Max, Num;
long long A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];

inline Point Calc(int i, int j)
{
	Point P;
	P.x = 1.0 * (C[j] * B[i] - C[i] * B[j]) / (A[i] * B[j] - A[j] * B[i]);
	P.y = 1.0 * (A[i] * C[j] - A[j] * C[i]) / (A[j] * B[i] - A[i] * B[j]);
	return P;
}

inline double Dis(Point P, int x)
{
	return fabs(A[x] * P.x + B[x] * P.y + C[x]) / sqrt(A[x] * A[x] + B[x] * B[x]);
}

int main()
{
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	cin >> N;
	for(int i = 1; i <= N; ++i)
		A[i] = Read(), B[i] = Read(), C[i] = Read();
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j < i; ++j)
		{
			Point P = Calc(i, j);
			int temp = 0;
			for(int k = 1; k <= N; ++k)
				if(Dis(P, k) <= Eps)
					++temp;
			if(temp > Max)
				Max = temp, Num = 1;
			else if(temp == Max)
				++Num;
		}
	cout << Max << " " << Num << endl;
	return 0;
}
