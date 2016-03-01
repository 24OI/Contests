#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long int LL;
typedef long double LDB;
const int MAXN = 1005;

LL gcd(LL a, LL b){return b ? gcd(b, a % b) : a;}
inline LL abs(LL x){return x >= 0LL ? x : -x;}
struct Rational{
	LL a, b;
	Rational(int x){a = x, b = 1LL;}
	Rational(LL a_ = 0LL, LL b_ = 1LL){
		if(a_ < 0LL && b_ < 0LL) a = -a_, b = -b_;
		else if(a_ < 0LL || b_ < 0LL) a = -abs(a_), b = abs(b_);
		else a = a_, b = b_;
		LL g = gcd(abs(a), b); a /= g, b /= g;
	}
	bool operator < (const Rational &rhs) const{
		return LDB(a) * rhs.b < LDB(rhs.a) * b;
	}
	Rational operator + (const Rational &rhs) const{
		LL g = gcd(b, rhs.b), l = b / g * rhs.b;
		Rational ret(a * (rhs.b / g) + rhs.a * (b / g), l);
		g = gcd(abs(ret.a), ret.b);
		ret.a /= g, ret.b /= g;
		return ret;
	}
	Rational operator - (const Rational &rhs) const{
		Rational tmp(- rhs.a, rhs.b);
		return *this + tmp;
	}
	Rational operator * (const Rational &rhs) const{
		Rational ret(a * rhs.a, b * rhs.b);
		LL g = gcd(abs(ret.a), ret.b);
		ret.a /= g, ret.b /= g;
		return ret;
	}
	Rational operator / (const Rational &rhs) const{
		return (*this) * Rational(rhs.b * (rhs.a < 0LL ? -1LL : 1LL), abs(rhs.a));
	}
}y;
typedef pair <Rational, int> pri;
map <Rational, int> light;
map <Rational, int> :: iterator it;
int n, a[MAXN], b[MAXN], c[MAXN];

inline bool co(int i, int j){
	if(!a[i] && !a[j]) return LL(c[i]) * b[j] == LL(c[j]) * b[i];
	if(!b[i] && !b[j]) return LL(c[i]) * a[j] == LL(c[j]) * a[i];
	return LL(a[i]) * c[j] == LL(a[j]) * c[i];
}
int main(){
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	int i, j, tag, maxans = 0, cnt;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for(i = 1; i <= n; ++ i){
		//scanf("%d%d%d", &a[i], &b[i], &c[i]);
		light.clear();
		tag = 1;
		//for(j = 1; j <= n; ++ j) if(a[i] * b[j] == a[j] * b[i] && a[i] * c[j] == a[j] * c[i] && b[i] * c[j] == b[j] * c[i]) ++ tag;
		for(j = 1; j < i; ++ j){
			if(a[i] * b[j] != a[j] * b[i]){//@ some point
				if(a[i]){
					Rational k(a[j], a[i]);
					y = (k * Rational(c[i]) - Rational(c[j])) / (Rational(b[j]) - k * Rational(b[i]));
				}else{
					Rational k(c[i], b[i]);
					y = (k * Rational(b[j]) - Rational(c[j])) / Rational(a[j]);
					//swap(i, j);
					//Rational k(a[j], a[i]);
					//y = (k * Rational(c[i]) - Rational(c[j])) / (Rational(b[j]) - k * Rational(b[i]));
					//swap(i, j);
				}
				//printf("line %d & %d, intersect @ %lld / %lld\n", i, j, y.a, y.b);
				if(light.find(y) != light.end()) ++ light[y];
				else light.insert(pri(y, 1));
			}else if(co(i, j)) ++ tag;
		}
		//printf("line %d %d %d:\n", a[i], b[i], c[i]);
		for(it = light.begin(); it != light.end(); ++ it)
			if(it -> se + tag > maxans){
				//printf("%lld / %lld, %d + %d\n", it -> fi.a, it -> fi.b, it -> se, tag);
				maxans = it -> se + tag;
				cnt = 1;
			}else if(it -> se + tag == maxans){
				//printf("%lld / %lld, %d + %d\n", it -> fi.a, it -> fi.b, it -> se, tag);
				++ cnt;
			}
	}
	printf("%d %d\n", maxans, cnt);
	return 0;
}
