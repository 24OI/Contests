#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here\n")

int n, m;
int a[100010];
int l[400010], r[400010], lson[400010], rson[400010], sum[400010], sumnode;

void build(int ll, int rr)
{
	int x = sumnode;
	l[x] = ll; r[x] = rr;
	if (ll == rr) sum[x] = 1;
	else
	{
		int mid = ll + rr >> 1;
		lson[x] = ++sumnode;
		build(ll, mid);
		rson[x] = ++sumnode;
		build(mid + 1, rr);
		sum[x] = sum[lson[x]] + sum[rson[x]];
	}
}

void chg(int x, int a)
{
	if (l[x] == r[x]) --sum[x];
	else
	{
		int mid = l[x] + r[x] >> 1;
		if (a <= mid) chg(lson[x], a); else chg(rson[x], a);
		--sum[x];
	}
}

int ask(int x, int ll, int rr)
{
	if (rr < ll) return 0;
	if (ll <= l[x] && rr >= r[x]) return sum[x];
	int mid = l[x] + r[x] >> 1, sum = 0;
	if (ll <= mid) sum += ask(lson[x], ll, rr);
	if (rr > mid) sum += ask(rson[x], ll, rr);
	return sum;
}

int main()
{
	freopen("lyk.in", "r", stdin);
	freopen("lyk.out", "w", stdout);
	
	scanf("%d", &n);
	int i;
	f(i, 1, n) scanf("%d", a + i);
	int ans = 0, x, y;
	build(1, n);
	f(i, 1, n - 1)
	{
		chg(0, a[i]);
		ans += ask(0, 1, a[i] - 1);
	}
	// printf("%d\n", ans);
	ans %= 2;
	scanf("%d", &m);
	f(i, 1, m)
	{
		scanf("%d %d", &x, &y);
		if (x != y) ans ^= 1;
		printf("%d\n", ans);
	}
	
	return 0;
}
