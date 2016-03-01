#include <map>
#include <cstdio>
using namespace std;
typedef pair<double, double> zb_type;
map<zb_type, int> m;
int n;
int A[1005], B[1005], C[1005];
inline int read() {
	int ret = 0, k = 1; char c = getchar();
	while ( c < '0' || '9' < c ) { if (c == '-') k = -1; c = getchar();}
	while ('0' <= c && c <= '9') { ret = ret * 10 - '0' + c; c = getchar(); }
	return ret;
}
bool qjd(double A1, double A2, double B1, double B2, double C1, double C2, double &x, double &y)
{
	x = y = 233.233;
	if (A1 == 0 && A2 == 0) return false;
	if (B1 == 0 && B2 == 0) return false;
	if (A2 == 0 && B1 == 0) {
		y = -C2/B2;
		x = -C1/A1;
		return true;
	}
	if (A1 == 0 && B2 == 0) {
		y = -C1/B1;
		x = -C2/A2;
		return true;
	}
	if (B1 != 0 && B2 != 0 && A1 / B1 == A2 / B2) return false;
	if (A1 == 0 && y == 233.233) y = -C1/B1;
	if (A2 == 0 && y == 233.233) y = -C2/B2;
	if (B1 == 0 && x == 233.233) x = -C1/A1;
	if (B2 == 0 && x == 233.233) x = -C2/A2;
	if (y == 233.233) y = (C2*A1-C1*A2)/(A2*B1-B2*A1);
	if (x == 233.233) x = (C2*B1-C1*B2)/(B1*A2-B2*A1);
	if (x == -0) x = 0;
	if (y == -0) y = 0;
	return true;
}
int main() {
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	n = read();
	m.clear();
	double x, y, A1, A2, B1, B2, C1, C2;
	zb_type nowzb;
	for (int i = 0; i < n; ++i) {
		A[i] = read(); B[i] = read(); C[i] = read();
		A1 = double(A[i]); B1 = double(B[i]); C1 = double(C[i]);
		for (int j = 0; j < i; ++j) {
			A2 = double(A[j]); B2 = double(B[j]); C2 = double(C[j]);
			if (qjd(A1, A2, B1, B2, C1, C2, x, y)) {
				nowzb = make_pair(x, y);
				if (m.find(nowzb) == m.end())
					m.insert(make_pair(nowzb, 2));
				else m.at(nowzb)++;
			}
		}
	}
	int maxlight = 0, maxlighttimes = 0;
	for (map<zb_type, int>::iterator it = m.begin(); it != m.end(); ++it) {
//		printf("%lf %lf %d\n", it->first.first, it->first.second, it->second);
		if (maxlight < it->second) {
			maxlight = it->second;
			maxlighttimes = 1;
		}
		else if (maxlight == it->second) ++maxlighttimes;
	}
	printf("%d %d\n", maxlight, maxlighttimes);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
