#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 2010;
int a[N], b[N], c[N];
const double eps = 1e-10;
typedef pair<double, double> point;

point t[N * N];
int s[N * N];
#define mp(a,b) make_pair(a,b)
int tl = 0;

double ab(double a){
	return a < 0 ? -a : a;
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	rep(i,1,n) rep(j,i + 1,n){
		int k = (b[i] * a[j] - b[j] * a[i]);
		double x = - double(c[i] * b[j] - c[j] * b[i]) / k, y = - double(c[i] * a[j] - c[j] * a[i]) / k;
		t[++tl] = mp(x, y);
	}
	sort(t + 1, t + tl + 1);
	int cnt, mx = 1;
	s[1] = 1;
	rep(i,2,tl) if (ab(t[i].first - t[i - 1].first) < eps && ab(t[i].second - t[i - 1].second) < eps){
		s[i] = s[i - 1] + 1;
		if (s[i] > mx) mx = s[i];
	} else s[i] = 1;
	
	int ans = 0;
	rep(i,2,n) if (((i * (i - 1)) >> 1) == mx) ans = i;
	
	cnt = 0;
	rep(i,1,tl) if (s[i] == mx) cnt++;
	printf("%d %d\n",ans, cnt);
	return 0;
}
