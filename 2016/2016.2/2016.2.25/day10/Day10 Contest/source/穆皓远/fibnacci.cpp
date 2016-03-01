#include <cstdio>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n, m;
const int mod=1000000001;
const int MAXN=100005;
long long fib[MAXN];
inline long long calfib(const long long &a, const long long &b, int n){return n>2?(fib[n-2]*a+fib[n-1]*b)%mod:n<2?a:b;}
inline long long calsum(const long long &a, const long long &b, int n){return (calfib(a, b, n+2)+mod-b)%mod;}
int a[MAXN];
namespace Force{
	void solve(){
		for (;m--;){
			int flag=getuint(), l=getuint(), r=getuint();
			if (flag==1) for (int i=l;i<=r;i++) (a[i]+=fib[i-l+1])%=mod;
			else{
				int ans=0;
				for (int i=l;i<=r;i++) (ans+=a[i])%=mod;
				printf("%d\n", ans);
			}
		}
	}
};
namespace Force233{
	struct SeGment_Tree{
		struct node{
			int l, r;inline int mid(){return l+r>>1;}
			node *s[2];
			long long a, b, sum;
			inline void update(){sum=(s[0]->sum+s[1]->sum)%mod;}
			inline void add(const long long &da, const long long &db){(a+=da)%=mod, (b+=db)%=mod, (sum+=calsum(da, db, r-l+1))%=mod;}
			inline void pushdown(){if (a||b) s[0]->add(a, b), s[1]->add(calfib(a, b, mid()-l+2), calfib(a, b, mid()-l+3)), a=b=0;}
		} pool[MAXN<<1], *poolnow, *root;
		SeGment_Tree(){poolnow=pool;}
		node *build(int l, int r){
			node *p=poolnow++;p->l=l, p->r=r;
			if (l==r) return p->sum=a[l], p;
			int mid=p->mid();
			p->s[0]=build(l, mid), p->s[1]=build(mid+1, r);
			return p->update(), p;
		}
		int l, r;
		inline void add(node *p){
			if (l<=p->l&&p->r<=r) return p->add(fib[p->l-l+1], fib[p->l-l+2]);
			p->pushdown();
			int mid=p->mid();
			if (l<=mid) add(p->s[0]);if (mid<r) add(p->s[1]);
			p->update();
		}
		inline void add(int _l, int _r){return l=_l, r=_r, add(root);}
		inline long long query(node *p){
			if (l<=p->l&&p->r<=r) return p->sum;
			p->pushdown();
			int mid=p->mid();
			if (l<=mid&&mid<r) return (query(p->s[0])+query(p->s[1]))%mod; else return query(p->s[mid<r]);
		}
		inline long long query(int _l, int _r){return l=_l, r=_r, query(root);}
		void init(){root=build(1, n);}
	} SGT;
	void solve(){
		SGT.init();
		for (;m--;){
			int flag=getuint(), l=getuint(), r=getuint();
			if (flag==1) SGT.add(l, r); else printf("%d\n", (int)SGT.query(l, r));
		}
	}
};
int main(){
	freopen("fibnacci.in", "r", stdin);
	freopen("fibnacci.out", "w", stdout);
	n=getuint(), m=getuint();
	fib[1]=1;for (int i=2;i<=n+2;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
	for (int i=1;i<=n;i++) a[i]=getuint();
	if (n<=1000&&m<=1000) return Force::solve(), 0;
	Force233::solve();
	return 0;
}

