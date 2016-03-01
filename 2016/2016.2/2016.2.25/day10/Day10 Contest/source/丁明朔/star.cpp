#include<cstdio>
#include<cmath>
#define eps 1e-6
using namespace std;

int n;

struct point{
	double x,y;
};

struct line{
	double a,b,c;
}L[1010];

point cross(line l1,line l2){
	point ret;
	if(l1.a!=0){
		ret.y=(l2.a*l1.c/l1.a-l2.c)/(l2.b-l2.a*l1.b/l1.a);
		ret.x=-(l1.c+l1.b*ret.y)/l1.a;
	}else{
		ret.y=-(l1.c/l1.b);
		ret.x=-(l2.c+l2.b*ret.y)/l2.a;
	}
	return ret;
}

bool cmp(point a,point b){
	if(fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps) return 1;
	else return 0;
}

bool cmp(double a,double b){
	return fabs(a-b)<eps;
}

bool px(line l1,line l2){
	if(cmp(l1.a*l2.b,l1.b*l2.a)) return 1;
	else return 0;
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&L[i].a,&L[i].b,&L[i].c);
	}
	int mx=-1,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(px(L[i],L[j])) continue;
			point p=cross(L[i],L[j]);
			int t=2;
			for(int k=1;k<=n;k++){
				if(k==i||k==j) continue;
				if(px(L[i],L[k])||px(L[j],L[k])) continue;
				point p2=cross(L[i],L[k]);
				if(cmp(p,p2)) t++;
			}
			if(t<mx) continue;
			if(t==mx) ans++;
			if(t>mx){
				mx=t;
				ans=1;
			}
		}
	}
	printf("%d %d\n",mx,ans);
	return 0;
}
