#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#define MP make_pair
using namespace std;
typedef pair<int, int> pii;
int head[100], nxt[10000], tow[10000], alc, n, m, ptr, siz;
vector<int> meow[50];
bool vis[50];
pii ans[100], curr[100];
void add(int s, int t)
{
	nxt[++alc] = head[s];
	head[s] = alc;
	tow[alc] = t;
	nxt[++alc] = head[t];
	head[t] = alc;
	tow[alc] = s;
}
void mcopy()
{
	memset(ans, 0, sizeof(ans));
	for(int i = 0; i < ptr; ++i)
		ans[i] = curr[i];
}
void solve(int cur)
{
	if(cur > n)
	{
		if(ptr > siz) mcopy(), siz = ptr;
		return;
	}
	if(vis[cur]){solve(cur+1);return;}
	else
		for(int i = head[cur]; i; i = nxt[i])
		{
			bool ok = false;
			if(!vis[tow[i]])
			{
				ok = true;
				curr[ptr++] = MP(cur, tow[i]);
				vis[cur] = vis[tow[i]] = true;
			}
			solve(cur+1);
			if(ok) vis[cur] = vis[tow[i]] = false, --ptr;
		}
}
int main()
{
#ifndef O233
	freopen("pair.in", "r", stdin);
	freopen("pair.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i)
	{
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		meow[t1].push_back(i);
		meow[t2].push_back(i);
	}
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j < meow[i].size(); ++j)
			for(int k = j+1; k < meow[i].size(); ++k)
				add(meow[i][j], meow[i][k]);
	solve(1);
	printf("%d\n", siz);
	for(int i = 0; i < siz; ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}

