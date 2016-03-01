#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;
#define rep(i,a,b) for (int i = a;i <= b;i ++)
#define per(i,a,b) for (int i = a;i >= b;i --)
#define maxn 1001
#define maxm 1000007

inline int rd() {
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar() ; int x = 0 , f = 1;
	if (c == '-') f = -1 ; else x = c - '0';
	while (isdigit(c = getchar())) x = x * 10 + c - '0';
	return x * f;
}

typedef long long ll;

ll gcd(ll a , ll b) { return b ? gcd(b , a % b) : a ; }

struct frac {
	ll a , b;
	frac(ll _a = 0 , ll _b = 0) {
		ll g = abs(gcd(_a , _b));
		if (g)
			a = _a / g , b = _b / g;
		else
			a = _a , b = _b;
		if (_b < 0) a = -a , b = -b;
	}
	friend bool operator==(frac a , frac b) {
		return a.a == b.a && a.b == b.b;
	}
	friend bool operator< (frac a , frac b) {
		return a.a * b.b < a.b * b.a;
	}
};

struct node{
	frac x , y;
	node() { x = y = frac(0 , 0); }
	node(frac x , frac y):x(x) , y(y) { }
	friend bool operator == (node a , node b) {
		return a.x == b.x && a.y == b.y;
	}
}point[maxm];

bool cmp(const node a , const node b) {
	return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}

int n , tot;

int a[maxn] , b[maxn] , c[maxn];

void input() {
	n = rd();
	rep (i , 1 , n) a[i] = rd() , b[i] = rd() , c[i] = rd();
}

void solve() {
	rep (i , 1 , n) rep (j , 1 , n) {
		ll a1 = a[i] , b1 = b[i] , c1 = c[i];
		ll a2 = a[j] , b2 = b[j] , c2 = c[j];
		if (a1 * b2 == a2 * b1) continue;
		frac x = frac(c2 * b1 - c1 * b2 , a1 * b2 - a2 * b1);
		frac y = frac(c2 * a1 - c1 * a2 , b1 * a2 - b2 * a1);
		point[++ tot] = node(x , y);
	}
	sort(point + 1 , point + tot + 1 , cmp);
	int ans = 1 , ans_2 = 1 , cnt = 1;
	rep (i , 2 , tot) {
		if (point[i] == point[i - 1]) {
			cnt ++;
			if (cnt > ans)
				ans = cnt , ans_2 = 1;
			else if (cnt == ans)
				ans_2 ++;
		} else
			cnt = 1;
	}
	printf("%d %d\n" , ans , ans_2);
}

int main() {
	freopen("star.in" , "r" , stdin);
	freopen("star.out" , "w" , stdout);
	input();
	solve();
	return 0;
}