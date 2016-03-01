#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
struct poi
{
	static const double eps = 1e-16;
	double x, y;
	bool operator<(const poi &rhs) const{return fabs(x-rhs.x) > eps ? x < rhs.x: rhs.y-y > eps;}
	bool operator>(const poi &rhs) const{return rhs < *this;}
	bool operator<=(const poi &rhs) const{return !(rhs < *this);}
	bool operator>=(const poi &rhs) const{return !(*this < rhs);}
	bool operator==(const poi &rhs) const{return !(*this < rhs) && !(rhs < *this);} 
};
struct line{int a, b, c;} night[1100];
struct node
{
	poi key;
	int val, pri;
	node *lht, *rht, *fa;
	bool ls;
	node(poi ik = (poi){0.0, 0.0}, int iv = 1):key(ik), val(iv), pri(rand()), lht(0), rht(0), fa(0), ls(false) {}
} *root1, *root2;
node *zag(node *cur, bool flag)
{
	if(cur->rht)
	{
		cur->fa->lht = cur->rht;
		cur->rht->fa = cur->fa;
		cur->rht->ls = true;
	}else cur->fa->lht = 0;
	cur->rht = cur->fa;
	cur->fa = cur->fa->fa;
	if(cur->fa) (cur->rht->ls ?((cur->fa->lht = cur), (cur->ls = true)):((cur->fa->rht = cur), (cur->ls = false)));
	else (flag?root1:root2) = cur;
	cur->rht->fa = cur;
	cur->rht->ls = false;
	return cur;
}
node *zig(node *cur, bool flag)
{
	if(cur->lht)
	{
		cur->fa->rht = cur->lht;
		cur->lht->fa = cur->fa;
		cur->lht->ls = false;
	}else cur->fa->rht = 0;
	cur->lht = cur->fa;
	cur->fa = cur->fa->fa;
	if(cur->fa) (cur->lht->ls ?((cur->fa->lht = cur), (cur->ls = true)):((cur->fa->rht = cur), (cur->ls = false)));
	else (flag?root1:root2) = cur;
	cur->lht->fa = cur;
	cur->lht->ls = true;
	return cur;
}
node *fix(node *cur, bool flag)
{
	while(cur->fa && cur->pri < cur->fa->pri)
		cur = (cur->ls? zag(cur, flag):zig(cur, flag));
	return cur;
}
void proces(const poi &p)
{
	if(!root1){root1 = new node(p, 2);return;}
	node *cur = root1;
	for(;;)
	{
		if(p == cur->key){++cur->val;return;}
		if(p < cur->key)
		{
			if(cur->lht) cur = cur->lht;
			else
			{
				cur->lht = new node(p, 2);
				cur->lht->fa = cur;
				cur->lht->ls = true;
				fix(cur->lht, true);
				return;
			}
		}else
		{
			if(cur->rht) cur = cur->rht;
			else
			{
				cur->rht = new node(p, 2);
				cur->rht->fa = cur;
				fix(cur->rht, true);
				return;
			}
		}
	}
}
bool get(const poi &p)
{
	if(!root2){root2 = new node(p, 0);return true; }
	node *cur = root2;
	for(;;)
	{
		if(p == cur->key) return false;
		if(p < cur->key)
		{
			if(cur->lht) cur = cur->lht;
			else
			{
				cur->lht = new node(p, 2);
				cur->lht->fa = cur;
				cur->lht->ls = true;
				fix(cur->lht, false);
				return true;
			}
		}else
		{
			if(cur->rht) cur = cur->rht;
			else
			{
				cur->rht = new node(p, 2);
				cur->rht->fa = cur;
				fix(cur->rht, false);
				return true;
			}
		}
	}
}
void sclear(node *cur)
{
	if(!cur) return;
	if(cur->lht)sclear(cur->lht);
	if(cur->rht)sclear(cur->rht);
	delete cur;
}
int n;
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
	srand(666666);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &night[i].a, &night[i].b, &night[i].c);
		sclear(root2);
		root2 = 0;
		for(int j = i-1; j >= 0; --j)
		{
			poi cur;
			if(intersect(night[i], night[j], cur) && get(cur))
					proces(cur);
		}
	}
}
void dfs(node *cur, int &m, int &a)
{
	if(!cur) return;
	if(cur->val > m)
	{
		m = cur->val;
		a = 1;
	}else if(cur->val == m)
		++a;
	dfs(cur->lht, m, a);
	dfs(cur->rht, m, a);
} 
void printans()
{
	int curm = 0, cura = 0;
	dfs(root1, curm, cura);
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

