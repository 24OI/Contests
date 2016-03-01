#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e3+5,maxm=5e5+5;

int t[maxn];
struct line{
	ll a,b,c;
}l[maxn];
struct point{
	ll xs,xm,ys,ym;
	bool operator<(const point&r)
		const{return xs<r.xs||(xs==r.xs&&xm<r.xm)||(xs==r.xs&&xm==r.xm&&ys<r.ys)||(xs==r.xs&&xm==r.xm&&ys==r.ys&&ym<r.ym) ;}
	bool operator==(const point&r)
		const{return xs==r.xs&&xm==r.xm&&ys==r.ys&&ym==r.ym;}
}p[maxm];
int n,m,ans,anst;

ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);} 

void insert(line u,line v){
	ll a1=u.a,b1=u.b,c1=u.c;
	ll a2=v.a,b2=v.b,c2=v.c;
	
	//printf("~%lld %lld %lld\n",a1,b1,c1);
	//printf("~%lld %lld %lld\n",a2,b2,c2);
	
	if(b1*a2==b2*a1) return;
	ll ys=c2*a1-c1*a2;
	ll ym=b1*a2-b2*a1;
	ll yd=gcd(ys,ym);
	if(yd) ys/=yd,ym/=yd;
	
	ll xs=b1*c1*a2-b1*c2*a1+c1*b2*a1-c1*b1*a2;
	ll xm=a1*b1*a2-a1*b2*a1;
	ll xd=gcd(xs,xm);
	if(xd) xs/=xd,xm/=xd;
	
	if(!xs) xm=0;
	if(!ys) ym=0;
	
	p[++m]=(point){xs,xm,ys,ym};
	//printf("%lld %lld %lld %lld\n",xs,xm,ys,ym);
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&l[i].a,&l[i].b,&l[i].c);
	for(int i=1;i<=n;i++)
		t[i]=i*(i-1)/2;
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			insert(l[i],l[j]);
			
	sort(p+1,p+m+1);
	
	int cnt=1;
	for(int i=2;i<=m+1;i++){
		if(i>m||!(p[i]==p[i-1])){
			int x=lower_bound(t+1,t+n+1,cnt)-t;
			if(x>ans) ans=x,anst=0;
			if(ans==x) anst++;
			//printf("%d %d %d\n",i,cnt,x);
			cnt=1;
		}
		else cnt++;
	}
	
	printf("%d %d\n",ans,anst);
	return 0;
}
