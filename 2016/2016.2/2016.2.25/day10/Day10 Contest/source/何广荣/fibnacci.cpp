#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
#define rep(i,a,b) for (int i = a;i <= b;i ++)
#define per(i,a,b) for (int i = a;i >= b;i --)
#define maxn 100007
#define maxb 2001

inline int rd() {
	char c = getchar();
	while (!isdigit(c)) c = getchar() ; int x = c - '0';
	while (isdigit(c = getchar())) x = x * 10 + c - '0';
	return x;
}

const int mod = 1000000001;
const int len = 2;

typedef int arr[maxn];
typedef int blk[maxb];

inline void upd(int&a , int b) { a += b ; if (a >= mod) a -= mod; }

int n , m , tot;

arr f , belong , a;
blk st , ed , sum;

queue<int> tag[maxb];

void input() {
	n = rd() , m = rd();
	f[0] = 0 , f[1] = 1;
	rep (i , 1 , n) a[i] = rd();
	rep (i , 2 , n) f[i] = (f[i - 1] + f[i - 2]) % mod;

	rep (i , 1 , n)
		belong[i] = i / n + 1 , upd(sum[belong[i]] , a[i]);
	tot = belong[n];
	rep (i , 1 , tot)
		st[i] = (i - 1) * len + 1 , ed[i] = i * len;
	ed[tot] = n;
}

inline int calc(int l , int r) {
	return (f[r + 2] - f[l + 1] + mod) % mod;
}

void modify(int l , int r) {
	int L = belong[l] , R = belong[r];
	if (L == R) {
		rep (i , l , r)
			upd(a[i] , f[i - l + 1]) , upd(sum[L] , f[i - l + 1]);
		return;
	}

	if (L + 1 != R) {
		rep (i , L + 1 , R - 1)
			tag[i].push(l) , upd(sum[i] , calc(st[i] - l + 1 , ed[i] - l + 1));
	}

	rep (i , l , ed[L])
		upd(a[i] , f[i - l + 1]) , upd(sum[L] , f[i - l + 1]);

	rep (i , st[R] , r)
		upd(a[i] , f[i - l + 1]) , upd(sum[R] , f[i - l + 1]);
}

void push_tag(int x) {
	while (!tag[x].empty()) {
		int l = tag[x].front() ; tag[x].pop();
		rep (i , st[x] , ed[x])
			upd(a[i] , f[i - l + 1]);
	}
}

void query(int l , int r) {
	int L = belong[l] , R = belong[r] , ret = 0;
	push_tag(L) , push_tag(R);

	if (L == R) {
		rep (i , l , r)
			upd(ret , a[i]);
		printf("%d\n" , ret);
		return;
	}

	if (L + 1 != R) {
		rep (i , L + 1 , R - 1)
			upd(ret , sum[i]);
	}

	rep (i , l , ed[L])
		upd(ret , a[i]);
	rep (i , st[R] , r)
		upd(ret , a[i]);
	printf("%d\n" , ret);
}

void solve() {
	rep (i , 1 , m) {
		int t = rd() , l = rd() , r = rd();
		if (t == 1)
			modify(l , r);
		else
			query(l , r);
	}
}

int main() {
	freopen("fibnacci.in" , "r" , stdin);
	freopen("fibnacci.out" , "w" , stdout);
	input();
	solve();
	return 0;
}