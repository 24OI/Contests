#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
//#define che
using namespace std;
const int maxn= 1000 + 10;
typedef long long LL;
const LL oo = 1ll<<60;
struct Point{
	LL xa,xb,ya,yb ;  // 写成a/b的形式
	bool operator==(const Point &b) const{
		return xa==b.xa && xb == b.xb && ya == b.ya && yb==b.yb;
	}
}p[1000*1000];
int pn,n;
LL A[maxn], B[maxn], C[maxn];

bool cmp(Point a, Point b){
	return (a.xa*b.xb-a.xb*b.xa <0)	||
			(a.xa*b.xb-a.xb*b.xa ==0 && a.ya*b.yb - b.ya*a.yb<0);
}
LL GCD(LL a, LL b){
	return b==0?a:GCD(b, a%b);
}
int main(){
	freopen("star.in","rt",stdin);
	freopen("star.out","wt",stdout);
	scanf("%d",&n);	pn=0;
	for (int i=0; i<n; i++)	scanf("%I64d%I64d%I64d",&A[i],&B[i], &C[i]);
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++){
			LL xa = B[i]*C[j]-B[j]*C[i],xb = A[i]*B[j]-A[j]*B[i],
			   ya = A[i]*C[j]-A[j]*C[i],yb=-xb;
			if (xb <0) xa=-xa, xb= -xb;  // 保证分母为正，即可直接比较是否相同
			if (yb <0) ya=-ya, yb= -yb;
			LL xg = GCD(abs(xa), abs(xb)),
			   yg = GCD(abs(ya), abs(yb));
			if ( xa!=0 || xb!=0 ) xa/= xg, xb/= xg;
			if ( ya!=0 || yb!=0) ya/= yg, yb/= xg; 
			p[pn++] = (Point){xa,xb,ya,yb};
		}
	sort(p, p+pn,cmp);
	int mxli=0, mxnm=0;
	p[pn++] = (Point){oo,oo,oo,oo};
	for (int i=1,cnt=1; i<pn; i++)
		if ( p[i]==p[i-1]) cnt++;
			else{
				if ( cnt > mxli){	mxli=cnt, mxnm=1;}	else
				if ( cnt==mxli)	mxnm++;
				cnt=1;
			}
	int rel ;
	for (int i=0; i<=n; i++)
		if ( i*(i-1)/2 == mxli){	rel = i; break;}
	printf("%d %d\n",rel,mxnm);
	#ifdef che
	printf("The Crossing Point\n");
	for (int i=0; i<pn; i++)
		printf("( %I64d/%I64d   ,   %I64d/%I64d   )\n",p[i].xa, p[i].xb, p[i].ya,p[i].yb);
	#endif
	return 0;
}
