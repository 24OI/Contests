#include<stdio.h>
#include<algorithm>
using std::sort;
typedef long long LL;
const int maxn=1E3+5;
const int INF=1E9+7;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

int ans=-INF,cans=0;
void update(int v){
	if(v>ans){
		ans=v;
		cans=1;
	}else if(v==ans) ++cans;
}

struct DIV{
	LL a,b;
	bool operator <(const DIV &o)const{
		if(a!=o.a) return a<o.a;
		else return b<o.b;
	}
	bool operator !=(const DIV &o)const{
		return a!=o.a || b!=o.b;
	}
	void assign(LL _a,LL _b){
		a=_a;
		b=_b;
		LL t=gcd(a,b);
		a/=t;b/=t;
	}
};
struct STAR{
	DIV x,y;
	bool operator <(const STAR &o)const{
		if(x!=o.x) return x<o.x;
		else return y<o.y;
	}
	bool operator !=(const STAR &o)const{
		return x!=o.x || y!=o.y;
	}
}stars[maxn*maxn*2];
int cStars=0;

int N;
LL A[maxn],B[maxn],C[maxn];

void gen(int a,int b){
	if(a==b) return;
	if(A[a]*B[b]==A[b]*B[a]) return;
	//int t=gcd(A[a],A[b]);
	LL a1=A[a],b1=B[a],c1=C[a],
	    a2=A[b],b2=B[b],c2=C[b];
	b1*=a2;c1*=a2;
	b2*=a1;c2*=a1;
	a1=a2=a1*a2;
	a1-=a2;b1-=b2;c1-=c2;
	stars[cStars].y.assign(-c1,b1);
	LL ya=stars[cStars].y.a,
	   yb=stars[cStars].y.b;
	if(A[a]) a1=A[a],b1=B[a],c1=C[a];
	else a1=A[b],b1=B[b],c1=C[b];
	stars[cStars].x.assign(-(b1*ya+c1*yb),a1*yb);
	++cStars;
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%I64d%I64d%I64d",A+i,B+i,C+i);
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) gen(i,j);
	sort(stars,stars+cStars);
	int cur=0;
	for(int i=0;i<cStars;++i){
		if(!i || stars[i]!=stars[i-1]){
			update(cur);
			cur=1;
		}else ++cur;
	}
	update(cur);
	printf("%d %d\n",ans,cans);
}
