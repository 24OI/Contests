#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int maxn= 100000 + 10;
typedef long long LL;
const LL MOD = 1e9 +1;
template<class T>
T upsum(T &a ,T b){	a= (a+b)%MOD;}

struct Node{
	Node *lft, *rgh;
	int l , r;
	LL sum;
	vector <LL> syb;   // 标记不能叠加，恶心。
	void maint(){
		sum = (lft->sum + rgh->sum)%MOD;
	}
} tree[maxn<<1], *rot, *none, Rnone;
LL ar[maxn],fib[maxn], pref[maxn];
int n ,tsze;

void init();
LL subFib(int l ,int r);
Node *Build(int l, int r);
void pushdown(Node *o);
void Modify(Node *o, int l, int r, int st);
LL Query(Node *o, int l, int r);
Node *NewNod(int l, int r, Node *lft,Node *rgh, LL s);

int main(){
	freopen("fibnacci.in","rt",stdin);
	freopen("fibnacci.out","wt",stdout);
	init();
	int Q;
	scanf("%d%d",&n,&Q);
	for (int i=1; i<=n; i++)	scanf("%I64d", &ar[i]);
	rot = Build(1,n);
	while ( Q--){
		int typ , l,r;
		scanf("%d%d%d",&typ, &l, &r);
		if ( typ ==1)	Modify(rot, l ,r, 1);
			else{
				LL ans= Query(rot, l ,r);
				printf("%I64d\n",ans);
			}
	}
	return 0;
}
void init(){
	memset(fib, 0 ,sizeof(fib));
	memset(pref, 0, sizeof(pref));
	fib[1] = pref[1] =  1;
	for (int i=2; i<=100000; i++){
		upsum( fib[i] , fib[i-1] + fib[i-2]);
		upsum( pref[i], pref[i-1] + fib[i]);
	}
	none= &Rnone;
	none->lft=  none->rgh = none;
	none->sum = 0;	none->syb.clear();
	tsze = 0;
}
LL subFib(int l ,int r){
	return ( (pref[r] - pref[l-1])%MOD + MOD)%MOD;
}
Node *NewNod(int l, int r, Node *lft,Node *rgh, LL s){
	Node *o= &tree[ tsze++] ;
	o->l =l; o->r = r;
	o->lft= lft;	o->rgh= rgh;
	o->sum =s;
	return o;
}

Node *Build(int l, int r){
	if( l==r ) return NewNod(l,r,none, none, ar[l]%MOD);
		else{
			int mid = (l+r)>>1;
			Node *o = NewNod(l, r, Build(l,mid), Build(mid+1,r), 0);
			o->maint();
			return o;
		}
}

void pushdown(Node *o){
	if ( o->syb.size()){
		int len=o->r-o->l+1 , mid= (o->r + o->l)>>1,
			lenl = mid- o->l+1 , lenr = o->r - mid;
		if ( o->l != o->r)
			for (int i=0; i< o->syb.size(); i++){
				int _st = o->syb[i];
				upsum(o->lft->sum , subFib(_st, _st+lenl-1));
				o->lft->syb.push_back(_st);
				upsum(o->rgh->sum , subFib(_st+lenl, _st+len-1));
				o->rgh->syb.push_back(_st+lenl);
			}
		o->syb.clear();
	}
}
void Modify(Node *o, int l, int r, int st){
	pushdown(o);
	if ( l == o->l && r==o->r){
		upsum( o->sum , subFib(st, st+r-l));
		o->syb.push_back( st);
	}	else{
		int mid = (o->l + o->r)>>1;
		if ( r <= mid) Modify(o->lft , l, r,st);	else
		if ( l > mid ) Modify(o->rgh , l, r, st); else
			Modify(o->lft, l, mid , st),
			Modify(o->rgh, mid+1, r, st+mid-l+1);
		o->maint();
	}
}

LL Query(Node *o, int l, int r){
	pushdown(o);
	if ( o->l == l && o->r==r)	return o->sum;
		else{
			int mid = (o->l + o->r) >>1;
			LL tmp =0;
			if ( r<=mid)	return  Query(o->lft, l,r);	else
			if ( l> mid)	return  Query(o->rgh, l ,r);	else
				return ( Query(o->lft, l ,mid) + Query(o->rgh , mid+1, r))%MOD;
		}
}

