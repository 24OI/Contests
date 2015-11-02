#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define x1 x11
#define y1 y11
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
 
#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
 
typedef long long LL;
typedef long double real;

double st,ed;
int m,n;
std::vector<int> V;
std::map<int,int> M;
struct node{
	int a,b,c,d,p;
	inline void read(){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		V.push_back(a);
		V.push_back(b);
		V.push_back(c);
		// V.push_back(d);
	}
	inline bool operator < (const node& T)const {
		return d > T.d;
	}
} s[1000033];
int mx;
bool C(int id){
	int cur,tee = s[id].c;
	g(j,id + 1,m){
		if (tee >= s[j].a & tee <= s[j].b)tee = s[j].c;
	}
	g(i,s[id].a,s[id].b){
		cur = i;
		g(j,id + 1,m){
			if (cur >= s[j].a & cur <= s[j].b)cur = s[j].c;
		}
		if (cur != tee)return 0;
	}
	return 1;
}
int ll,rr;
bool wtf(){
	int pre = 0,cur;
	g(i,ll,rr){
		cur = i;
		g(j,1,m){
			if (cur >= s[j].a && cur <= s[j].b)cur = s[j].c;
		}
		if (!pre)pre = cur;
		if (pre != cur)return 1;
	}
	return 0;
}
void solve(){
	V.push_back(1);
	V.push_back(n);
	std::sort(V.begin(),V.end());
	V.erase(std::unique(V.begin(),V.end()),V.end());
	f(i,0,V.size())M[ V[i] ] = i + 1;
	mx = V.size();
	// node* root = new node(1,mx + 1);
	int ans = 0;
	ll = V[0];rr = V[mx - 1];
	g(i,1,m){
		s[i].a = M[ s[i].a ];
		if (s[i].a < ll)ll = s[i].a;
		s[i].b = M[ s[i].b ];
		if (s[i].b > rr)rr = s[i].b;
		s[i].c = M[ s[i].c ];
		ans += s[i].d;
		// s[i].d = M[ s[i].d ];
		// root->upd(a,b);
	}
	std::sort(s + 1,s + m + 1);
	if (wtf()){
		puts("-1");
		return;
	}
	g(i,1,m)if (C(i)){
		ans -= s[i].d;
		// printf("%d\n",s[i].d);
	}
	printf("%d\n",ans);
}
int main(){
#ifndef LOCAL
	freopen("pinball.in","r",stdin);
	freopen("pinball.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d%d",&m,&n);
	g(i,1,m){
		s[i].read();
		s[i].p = i;
	}
	solve();

#ifdef TI
	ed = clock();
	printf("%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
// 5 6 2 4 3 5 1 2 2 8 3 6 5 2 4 6 4 7 2 4 3 10
// 3 5 2 4 3 10 1 3 1 20 2 5 4 30