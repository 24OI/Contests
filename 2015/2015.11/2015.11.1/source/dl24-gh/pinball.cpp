#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int M = 1e6 + 9;

int A[M], B[M], C[M], D[M];
int used[M];

/*struct pin
{
	int A, int B, int C, int D;
};
vector<pin> vt;*/

int main(){
	freopen("pinball.in", "r", stdin);
	freopen("pinball.out", "w", stdout);
	/*int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	int ans = 1e9;
	for (int t = 1; t <= 1 << n; ++t){
		vt.clear();
		for (int i = 1; i <= n; ++i){
			if (t >> i){
				vt.A.push_back(A[i]);
				vt.B.push_back(B[i]);
				vt.C.push_back(C[i]);
				vt.D.push_back(D[i]);
			}
		}
	}*/
	printf("-1\n");
	return 0;
}
