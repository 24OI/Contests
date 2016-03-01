#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;
#define rep(i,a,b) for (int i = a;i <= b;i ++)
#define per(i,a,b) for (int i = a;i >= b;i --)
#define For(i,a,b) for (int i = a;i <  b;i ++)
#define maxs (1 << 10)

inline int rd() {
	char c = getchar();
	while (!isdigit(c)) c = getchar() ; int x = c - '0';
	while (isdigit(c = getchar())) x = x * 10 + c - '0';
	return x;
}

const int mod = 593119681;

typedef long long ll;

int n , all , m;

int s[maxs];

namespace work1 {

	struct mat {
		int a[128][128];
		mat(){ memset(a , 0 , sizeof a); }
		friend mat operator*(mat a , mat b) {
			mat c = mat();
			For (i , 0 , all) For (j , 0 , all) For (k , 0 , all)
				(c.a[i][j] += (ll) a.a[i][k] * b.a[k][j] % mod) %= mod;
			return c;
		}
	}g , A , I , B;

	mat Pow(mat a , int b) {
		mat ret = I;
		while (b) {
			if (b & 1) ret = ret * a;
			b >>= 1 , a = a * a;
		}
		return ret;		
	}

	void solve() {
		For (i , 0 , all) I.a[i][i] = 1;
		rep (i , 0 , all - 1) {
			g.a[i][i] = 1;
			rep (j , 0 , n - 1) g.a[i][i ^ (1 << j)] = g.a[i ^ (1 << j)][i] = 1;
		}

		A = Pow(g , m);
		For (i , 0 , all) B.a[0][i] = s[i];

		A = B * A;
		For (i , 0 , all)
			printf("%d%c" , A.a[0][i] , i == all - 1 ? '\n' : ' ');
	}

}

namespace work2 {
	#define pb push_back

	int a[2][maxs];

	vector<int> trans[maxs];

	void solve() {
		For (i , 0 , all) a[0][i] = s[i];

		For (i , 0 , all) {
			trans[i].pb(i);
			For (j , 0 , n) trans[i].pb(i ^ (1 << j));
		}

		int cur = 0 , pre = 1;

		For (T , 0 , m) {
			cur ^= 1 , pre ^= 1;
			For (i , 0 , all) {
				int t = 0;
				For (j , 0 , trans[i].size())
					(t += a[pre][trans[i][j]]) %= mod;
				a[cur][i] = t;
			}
		}

		For (i , 0 , all)
			printf("%d%c" , a[cur][i] , i == all - 1 ? '\n' : ' ');
	}
}

void input() {
	n = rd() , m = rd();
	all = 1 << n;
	For (i , 0 , all) s[i] = rd();
}

void solve() {
	if (n <= 6 && m <= 10000000)
		work1::solve();
	else if (n <= 10 && m <= 1000)
		work2::solve();
}

int main() {
	freopen("monster.in" , "r" , stdin);
	freopen("monster.out" , "w" , stdout);
	input();
	solve();
	return 0;
}