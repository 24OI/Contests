#include <cstdio>
#include <vector>

struct node
{
	unsigned int l,r;
	std::vector<unsigned int> data;
	unsigned int sum;
	unsigned int lazy;
};

const unsigned int mod = 1000000000 + 1;
unsigned int fibnacci[100000 + 10];
unsigned int data[100000 + 10];
struct node tree[(100000 + 10) << 1];

void tree_init(unsigned int i,unsigned int l,unsigned int r)
{
	tree[i].l = l;
	tree[i].r = r;
	if(l == r) {
		tree[i].lazy = 1;
		tree[i].sum = data[l];
		return;
	}
	tree_init(i << 1,l,(l + r) >> 1);
	tree_init(1 + (i << 1),1 + ((l + r) >> 1),r);
	(tree[i].sum = tree[i << 1].sum + tree[1 + (i << 1)].sum) %= mod;
}

void tree_apply(unsigned int i)
{
	unsigned int c1 = i << 1,c2 = 1 + (i << 1);
	unsigned int l = tree[i].l,r = tree[i].r,m;
	unsigned int j,f;

//	if(!tree[i].lazy)
//		return;
	tree[i].lazy = 0;
	tree[c1].lazy = 1;
	tree[c2].lazy = 1;
	m = (l + r) >> 1;
	for(j = 0;j < tree[i].data.size();++j)
	{
		f = tree[i].data[j];
		(tree[c1].sum += fibnacci[f + m - l] - ((f == 0) ? 0 :fibnacci[f - 1])) %= mod;
		(tree[c2].sum += fibnacci[r - l + f] - fibnacci[f + m - l]) %= mod;
		if(tree[c1].l != tree[c1].r)
			tree[c1].data.push_back(f);
		if(tree[c2].l != tree[c2].r)
			tree[c2].data.push_back(f + m - l + 1);
	}
	tree[i].data.clear();
//	if(tree[i].sum != (tree[c1].sum + tree[c2].sum) % mod)
//		printf("ERROR!\n");
	(tree[i].sum = tree[c1].sum + tree[c2].sum) %= mod;
}

unsigned int tree_query(unsigned int i,unsigned int l,unsigned int r)
{
	unsigned int ans = 0;
	unsigned int l0 = tree[i].l,r0 = tree[i].r,m0;
	m0 = (l0 + r0) >> 1;
	if(l0 == l && r0 == r)
		return tree[i].sum;
	if(tree[i].lazy)
		tree_apply(i);
	if(l <= m0)
		(ans += tree_query(i << 1,l,m0)) %= mod;
	if(r >= m0 + 1)
		(ans += tree_query((i << 1) + 1,m0 + 1,r)) %= mod;
	return ans;
}

void tree_add(unsigned int i,unsigned int l,unsigned int r,unsigned int f)
{
	unsigned int l0 = tree[i].l,r0 = tree[i].r,m0;
	m0 = (l0 + r0) >> 1;
	if(l0 == l && r0 == r) {
		tree[i].lazy = 1;
		tree[i].data.push_back(f);
		(tree[i].sum += fibnacci[r - l + f] - ((f == 0) ? 0 :fibnacci[f - 1])) %= mod;
		return;
	}
	if(tree[i].lazy)
		tree_apply(i);
	if(l <= m0)
		tree_add(i << 1,l,m0,f);
	if(r >= m0 + 1)
		tree_add((i << 1) + 1,m0 + 1,r,f + m0 - l + 1);
	(tree[i].sum = tree[i << 1].sum + tree[(i << 1) + 1].sum) %= mod;
}

int main(void)
{
	unsigned int i;
	unsigned int n,m,op,l,r;

	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%u %u",&n,&m);
	for(i = 1;i <= n;++i)
		scanf("%u",&data[i]);

	fibnacci[0] = 0;
	fibnacci[1] = 1;
	for(i = 2;i <= n;++i)
		(fibnacci[i] = fibnacci[i - 1] + fibnacci[i - 2]) %= mod;
	for(i = 1;i <= n;++i)
		(fibnacci[i] += fibnacci[i - 1]) %= mod;
	tree_init(1,1,n);

	while(m--)
	{
		scanf("%u %u %u",&op,&l,&r);
		switch(op)
		{
		case 1:
			tree_add(1,l,r,1);
			break;
		case 2:
			printf("%u\n",tree_query(1,l,r));
			break;
		}
	}

//	printf("%d\n",sizeof(tree) / 1024 / 1024);
	return 0;
}
