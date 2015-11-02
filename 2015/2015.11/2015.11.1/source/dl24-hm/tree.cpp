#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here\n")

int n, m;
int dis[3010][3010];
int head[100010], next[200010], pt[200010], w[200010], sumedge;
int l[10000], r[10000], lson[10000], rson[10000], max[3010][10000], sumnode;

inline void build(int x, int y, int z)
{
	next[++sumedge] = head[x];
	head[x] = sumedge;
	pt[sumedge] = y;
	w[sumedge] = z;
}

void getdis(int x, int y, int t, int f)
{
	dis[t][x] = y;
	for (int i = head[x]; ~i; i = next[i]) if ((i ^ 1) != f) getdis(pt[i], y + w[i], t, i);
}

void build(int ll, int rr)
{
	int x = sumnode, i;
	l[x] = ll; r[x] = rr;
	if (ll == rr) f(i, 1, n) max[i][x] = dis[i][ll];
	else
	{
		int mid = ll + rr >> 1;
		lson[x] = ++sumnode;
		build(ll, mid);
		rson[x] = ++sumnode;
		build(mid + 1, rr);
		f(i, 1, n) max[i][x] = std::max(max[i][lson[x]], max[i][rson[x]]);
	}
}

int ask(int x, int a, int b, int c, int d)
{
	int i, mx = 0;
	if (l[x] == r[x]) f(i, a, b) mx = std::max(mx, max[i][x]);
	else
	{
		int mid = l[x] + r[x] >> 1;
		if (c <= mid) mx = std::max(mx, ask(lson[x], a, b, c, d));
		if (d > mid) mx = std::max(mx, ask(rson[x], a, b, c, d));
	}
	return mx;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	scanf("%d", &n);
	int i, x, y, z, d;
	sumedge = -1;
	memset(head, -1, sizeof(head));
	f(i, 2, n)
	{
		scanf("%d %d %d", &x, &y, &z);
		build(x, y, z);
		build(y, x, z);
	}
	f(i, 1, n) getdis(i, 0, i, -1);
	build(1, n);
	scanf("%d", &m);
	f(i, 1, m)
	{
		scanf("%d %d %d %d", &x, &y, &z, &d);
		printf("%d\n", ask(0, x, y, z, d));
	}
	// int j;
	// f(i, 1, n) {f(j, 1, n) printf("%d ", dis[i][j]); ln;}
	
	return 0;
}
