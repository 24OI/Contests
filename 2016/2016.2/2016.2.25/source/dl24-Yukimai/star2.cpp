#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
struct poi
{
	static const double eps = 1e-8;
	double x, y;
	bool operator<(const poi &rhs) const{return fabs(x-rhs.x) > eps ? x < rhs.x: rhs.y-y > eps;}
};
struct line{int a, b, c;} night[1100];
int n;
map<poi, int> light;
bool intersect(const line &lhs, const line &rhs, poi &ans)
{
	int delta = rhs.a*lhs.b-lhs.a*rhs.b;
	if(!delta) return false;
	int qy = lhs.a*rhs.c-rhs.a*lhs.c, qx = lhs.c*rhs.b-rhs.c*lhs.b;
	ans.x = (double)qx/delta;
	ans.y = (double)qy/delta;
	return true;
}
void snow()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &night[i].a, &night[i].b, &night[i].c);
		set<poi> st;
		for(int j = i-1; j >= 0; --j)
		{
			poi cur;
			if(intersect(night[i], night[j], cur) && !st.count(cur))
			{
					if(light.count(cur)) ++light[cur];
					else light[cur] = 2;
					st.insert(cur);
			}
		}
	}
}
void printans()
{
	int curm = 1, cura = 0;
	for(map<poi, int>::iterator itr = light.begin(); itr != light.end(); ++itr)
	{
		if(itr->second > curm)
		{
			curm = itr->second;
			cura = 1; 
		}else if(itr->second == curm) ++cura;
	}
	printf("%d %d\n", curm, cura);
}
int main()
{
#ifndef snowoi
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
#endif
	snow();
	printans();
	return 0;
}

