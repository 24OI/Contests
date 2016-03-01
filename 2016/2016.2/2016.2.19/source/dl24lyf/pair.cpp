#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 1111;
std::vector<int> tuan[maxn];
std::vector<int> ans1;
std::vector<int> ans2;
struct Edge {
	int to, next;
}edge[maxn * maxn];
int n, tot, m;
int h, t;
int q[maxn], bleg[maxn], head[maxn], match[maxn], pre[maxn];
bool vis[maxn], inblossom[maxn];
inline void add(int, int);
inline int pop();
inline void push(int i);
void init();
inline int findAncestor(int u, int v);
void reset(int u, int anc);
void contract(int u, int v);
int bfs(int start);
int Edmonds_BC();
int a, b;
int main() {
	freopen("pair.in", "r", stdin);
	freopen("pair.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a, &b);
		tuan[a].push_back(i);
		tuan[b].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < tuan[i].size(); ++j) {
			for (int l = j + 1; l < tuan[i].size(); ++l) {
				add(tuan[i][j], tuan[i][l]);
				add(tuan[i][l], tuan[i][j]);
			}
		}
	}
	cout << Edmonds_BC() << endl;
	for (int i = 0; i < ans1.size(); ++i) {
		printf("%d %d\n", ans1[i], ans2[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline void add(int a, int b) {
	edge[tot].to = b;
	edge[tot].next = head[a];
	head[a] = tot++;
}
inline int pop() {
	return q[h++];
}
inline void push(int i) {
	if (!vis[i]) {
		q[++t] = i;
		vis[i] = true;
	}
}
void init() {
	h = t = 0;
	memset(vis, 0, sizeof vis);
	memset(pre, -1, sizeof pre);
	for (int i = 1; i <= n; ++i) bleg[i] = i;
}
inline int findAncestor(int u, int v) {
	bool inpath[maxn];
	memset(inpath, 0, sizeof inpath);
	while (1) {
		u = bleg[u];
		inpath[u] = true;
		if (match[u] == -1) break;
	}
	u = pre[match[u]];
	while (233) {
		v = bleg[v];
		if (inpath[v]) return v;
		v = pre[match[v]];
	}
}
void reset(int u, int anc) {
	while (u != anc) {
		int v = match[u];
		inblossom[bleg[u]] = true;
		inblossom[bleg[v]] = true;
		v = pre[v];
		if (bleg[v] != anc) pre[v] = match[u];
		u = v;
	}
}
void contract(int u, int v) {
	int anc = findAncestor(u, v);
	memset(inblossom, 0, sizeof inblossom);
	reset(u, anc);
	reset(v, anc);
	if (bleg[u] != anc) pre[u] = v;
	if (bleg[v] != anc) pre[v] = u;
	for (int i = 1; i <= n; ++i) {
		if (inblossom[bleg[i]]) {
			bleg[i] = anc;
			push(i);
		}
	}
}
int bfs(int start) {
	init();
	q[0] = start;
	vis[start] = true;
	while (h <= t) {
		int u = pop();
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (bleg[v] != bleg[u] && match[v] != u) {
				if (v == start || (match[v] != -1 && pre[match[v]] != -1)) {
					contract(u, v);
				} else if (pre[v] == -1) {
					pre[v] = u;
					if (match[v] != -1) push(match[v]);
					else return v;
				}
			}
		}
	}
	return -1;
}
int Edmonds_BC() {
	int cnt = 0;
	memset(match, -1, sizeof match);
	for (int i = 1; i <= n; ++i) {
		if (match[i] == -1) {
			int u = bfs(i);
			if (u != -1) {
				cnt++;
				ans1.push_back(u);
				ans2.push_back(i);
				while (u != -1) {
					int v = pre[u];
					int t = match[v];
					match[u] = v;
					u = t;
				}
			}
		}
	}
	return cnt;
}
