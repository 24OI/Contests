#include <cstdio>
#include <map>
using namespace std;

const int maxn = 1e3+5;
struct Str { int a, b, c; } str[maxn];
struct Node 
{ 
	float x, y; 
	bool operator <(const Node &b) const
	{ return b.x != x ? x < b.x : y < b.y; }
};
map <Node, int> M;
int N, Max, ans;

inline long long read()
{
	char ch = getchar(); long long sum = 0, t = 1;
	while(ch < '0' || ch > '9') { if(ch == '-') t = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') sum = sum*10 + ch - '0', ch = getchar();
	return sum*t;
}

Node Union(int i, int j)
{
	float x, y;
	if(str[i].b == 0) x = str[i].c*1.0/str[i].a, y = -(str[j].a*x+str[j].c)/str[j].b*1.0;
	else if(str[j].b == 0) x = str[j].c*1.0/str[j].a, y = -(str[i].a*x+str[i].c)/str[i].b*1.0;
	else 
	{
		x = (str[j].c*str[i].b-str[i].c*str[j].b)*1.0/(str[i].a*str[j].b*1.0-str[j].a*str[i].b*1.0);
		y = -(str[i].a*x+str[i].c)/str[i].b*1.0;
	}
	return (Node){x, y};
}

int main()
{
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	N = read();
	for(int i = 1; i <= N; i++)
	str[i].a = read(), str[i].b = read(), str[i].c = read();
	for(int i = 1; i <= N; i++)
	for(int j = i+1; j <= N; j++)
		if(str[i].a*1.0/str[i].b != str[j].a*1.0/str[j].b) M[Union(i, j)]++;
	for(int i = 1; i <= N; i++)
	for(int j = i+1; j <= N; j++)
	{
		int tot = M[Union(i, j)];
		if(tot > Max) Max = tot, ans = 1;
		else if(tot == Max) ans++;
	}
	printf("%d %d", Max+1, ans);
	return 0;
}
