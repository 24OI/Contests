#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define yuki(x, y) for(int i = x; i < (y); ++i)
#define yukj(x, y) for(int j = x; j < (y); ++j)
#define yukii(x, y) for(int i = x; i <= (y); ++i)
#define yukji(x, y) for(int j = x; j <= (y); ++j)
#define yuk(x, y, z) for(int x = y; x < (z); ++x)
#define yui(x, y, z) for(int x = y; x >= (z); --x)
#define QAQ main
using namespace std;
bool G[610][610], isstart[610], isfin[610], vis[610];
int n, m, ans, p, fins[610], perm[610], fsiz;
vector<int> stlist;
void sread()
{
	memset(isstart, true, sizeof(isstart));
	memset(isfin, true, sizeof(isfin));
	scanf("%d%d%d", &n, &m, &p);
	while(m--)
	{
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		G[t1][t2] = true;
		isfin[t1] = false;
		isstart[t2] = false;		
	}
	int alc = 0;
	yukii(1, n)
	{
		if(isstart[i]) stlist.push_back(i);
		if(isfin[i]) fins[i] = ++alc;
	}
	fsiz = alc;
}
void calc()
{
	int cans = 0;
	yukii(1, fsiz)
		yukji(i+1, fsiz)
			if(perm[i] > perm[j]) ++cans;
	if(cans & 1) --ans;
	else ++ans;
}
void printans()
{
	ans %= p;
	if(ans < 0) ans += p;
	printf("%d\n", ans);
}
void dfs(int st, int cur)
{
	vis[cur] = true;
	if(isfin[cur])
	{
		perm[fins[cur]] = st;
		if(st == stlist.size()-1) {calc();vis[cur] = false;return;}
		dfs(st+1, stlist[st+1]);
		vis[cur] = false;
		return;
	}
	yukii(1, n)
		if(G[cur][i] && !vis[i])
			dfs(st, i);
	vis[cur] = false;
}
int QAQ(int argc, char **argv)
{
#ifndef snowoi
	freopen("bagua.in", "r", stdin);
	freopen("bagua.out", "w", stdout);
#endif
	sread();
	dfs(0, stlist[0]);
	printans();
	return 0;
}

