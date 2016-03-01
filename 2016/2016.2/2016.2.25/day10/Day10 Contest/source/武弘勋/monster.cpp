#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
const int N = 262154, mod = 593119681;
int a[N], n, m;
struct mat{
	int a[19][19];
}A;

mat c;
mat operator * (const mat &a, const mat &b){
	Rep(i,n + 1) Rep(j,n + 1){
		c.a[i][j] = 0;
		Rep(k,n + 1) c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % mod;	
	}
	return c;
}

mat w;
mat pow(mat A, int b){
	Rep(i,n + 1) Rep(j,n + 1) w.a[i][j] = (int)(i == j);
	for(;b;b >>= 1, A = A * A) if (b & 1) w = w * A;
	return w;
}

typedef long long LL;
int ans[N], cnt[N];
LL s[N][19], t[N][19];

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int T; scanf("%d%d",&n,&T); 
	m = 1 << n;
	Rep(i,m) scanf("%d",&a[i]);	

	rep(i,0,n){
		if (i < n) A.a[i][i + 1] = n - i;
		if (i) A.a[i][i - 1] = i;
		A.a[i][i] = 1;
	}
	
	A = pow(A, T);	
	
	cnt[0] = 0;
	rep(i,1,m - 1) cnt[i] = cnt[i - (i & (-i))] + 1;
	
	Rep(i,m) s[i][0] = a[i], t[i][0] = a[i];
	rep(j,1,n)
		Rep(i,m){
			s[i][j] = 0;
			if (j > 1) t[i][j] = t[i][j - 2]; else t[i][j] = 0;
			Rep(k,n){
				int t1 = i ^ (1 << k);
				s[i][j] += t[t1][j - 1] - t[i][j - 2];
			}
			s[i][j] = s[i][j] / j;
			t[i][j] += s[i][j];
		}
		
	Rep(i,m) {
		ans[i] = 0;
		rep(j,0,n) ans[i] = (ans[i] + 1LL * s[i][j] % mod * A.a[j][0]) % mod;
		if (ans[i] < 0) ans[i] += mod;
	}
	
	Rep(i,m) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
