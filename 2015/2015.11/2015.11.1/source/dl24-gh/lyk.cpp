#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int A[100009];

int count(int *a, int N){
	int cnt = 0;
	int i, j;
	for (i = 0; i < N - 1; ++i)
		for (j = i + 1; j < N; ++j){
			if (a[i] > a[j]) ++cnt;
			if (cnt > 2) cnt -= 2;
		}
	return cnt;
}

int main(){
	freopen("lyk.in", "r", stdin);
	freopen("lyk.out", "w", stdout);
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	if (n <= 1000){
		for (int t = 1; t <= m; ++t){
			int x, y;
			scanf("%d%d", &x, &y);
			swap(A[x], A[y]);
			int ans = count(A + 1, n) % 2;
			printf("%d\n", ans);
		}
	}
	else {
		int ans = 0;
		for (int t = 1; t <= m; ++t){
			int x, y;
			scanf("%d%d", &x, &y);
			if (x != y) ans ^= 1;
			printf("%d\n", ans);
		}
	}
	return 0;
}
