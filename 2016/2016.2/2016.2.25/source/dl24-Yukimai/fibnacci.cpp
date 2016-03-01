#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int raw[100010], n, f[100010], m;
const int M = (int)1e9+1;
int splus(int lhs, int rhs)
{
	return (lhs%M+rhs%M)%M;
}
#include <vector>
#include <utility>
#define fi first
#define se second
#define MP make_pair 
typedef pair<int, int> pii;
typedef vector<pii> vpii; 
struct node
{
	int l, r, sum;
	vpii lazy;
	node *lht, *rht;
	node(int il, int ir, int is):l(il), r(ir), sum(is), lazy(), lht(0), rht(0) {}
	node(int il = 0, int ir = 0):l(il), r(ir), sum(0), lazy(), lht(0), rht(0) {}
	bool leaf(){return l==r;}
} *root;
int sminus(int lhs, int rhs)
{
	int ans = (lhs%M-rhs%M)%M;
	if(ans<0) ans += M;
	return ans;
}
node *maketree(int il, int ir)
{
	if(il==ir) return new node(il, ir, raw[il]%M);
	node *ans = new node(il, ir);
	int m = il+((ir-il)>>1);
	ans->lht = maketree(il, m);
	ans->rht = maketree(m+1, ir);
	ans->sum = splus(ans->lht->sum,ans->rht->sum);
	return ans;
}
int fib(int b, int e)
{
	return sminus(f[e+2], f[b+1]);
}
void pushd(node *cur)
{
	while(!cur->lazy.empty())
	{
		pii now = cur->lazy.back();
		cur->lazy.pop_back();
		int m = now.first + ((now.se-now.first) >>1);
		cur->lht->sum = splus(cur->lht->sum, fib(now.fi, m));
		if(!cur->lht->leaf()) cur->lht->lazy.push_back(MP(now.first, m));
		cur->rht->sum = splus(cur->rht->sum, fib(m+1, now.se));
		if(!cur->rht->leaf()) cur->rht->lazy.push_back(MP(m+1, now.se));
	}
}

void qplus(node *cur, int il, int ir, int fb, int fe)
{
	if(cur->l == il && cur->r == ir)
	{
		cur->sum = splus(cur->sum, fib(fb, fe));
		if(!cur->leaf()) cur->lazy.push_back(MP(fb, fe));
		return;
	}
	int m = cur->lht->r;
	pushd(cur);
	if(ir <= m) qplus(cur->lht, il, ir, fb, fe);
	else if(il > m) qplus(cur->rht, il, ir, fb, fe);
	else
	{
		qplus(cur->lht, il, m, fb, fb+m-il);
		qplus(cur->rht, m+1, ir, fb+m-il+1, fe);
	}
	cur->sum = splus(cur->lht->sum, cur->rht->sum);
}
int qsum(node *cur, int il, int ir)
{
	if(il == cur->l && ir == cur->r) return cur->sum;
	pushd(cur);
	int m = cur->lht->r;
	if(il > m) return qsum(cur->rht, il, ir);
	if(ir <= m) return qsum(cur->lht, il, ir);
	return splus(qsum(cur->lht, il, m), qsum(cur->rht, m+1, ir)); 
}
void raed()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", raw+i);
	f[1] = f[2] = 1;
	for(int i = 3; i <= n+3; ++i)
		f[i] = splus(f[i-1], f[i-2]);
}
void snow()
{
	while(m--)
	{
		int t1, t2, t3;
		scanf("%d%d%d", &t1, &t2, &t3);
		if(t1 == 1)
			qplus(root, t2, t3, 1, t3-t2+1);
		else
			printf("%d\n", qsum(root, t2, t3));
	}
}
int main()
{
#ifndef snowoi
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
#endif
	raed();
	root = maketree(1, n);
	snow();
	return 0;
}

