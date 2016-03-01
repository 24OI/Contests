#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1000+10;
const double eps = 1e-6;
double Fabs(double x){
	return x>0?x:-x;
}
struct Point{
	double x,y;
	Point(){x=0;y=0;}
	Point(double _x,double _y){
		x=_x; y=_y;
	}
	bool friend operator < (const Point &a,const Point &b){
		return a.x<b.x || (a.x==b.x && a.y<b.y);
	}
	bool friend operator == (const Point &a,const Point &b){
		return Fabs(a.x-b.x)<eps && Fabs(a.y-b.y)<eps;
	}
}p,M[N*N];
int n,cnt,Ans,ac;
double kx[N],ky[N];
double kz[N],bz[N];
int cx,cy,cz;
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int a,b,c,i=1;i<=n;++i){
		scanf("%d%d%d",&a,&b,&c);
		if(b==0){
			kx[++cx] = 1.0f*(-c)/a;
		}else if(a==0){
			ky[++cy] = 1.0f*(-c)/b;
		}else{
			++cz;
			kz[cz]=1.0f*(-a)/b;
			bz[cz]=1.0f*(-c)/b;
		}
	}
	for(int i=1;i<=cx;++i){
		for(int j=1;j<=cz;++j){
			p = Point(kx[i],kz[j]*kx[i]+bz[j]);
			M[++cnt]=p;
		}
	}
	for(int i=1;i<=cy;++i){
		for(int j=1;j<=cz;++j){
			p = Point((ky[i]-bz[j])/kz[j],ky[i]);
			M[++cnt]=p;
		}
	}
	for(int i=1;i<=cx;++i){
		for(int j=1;j<=cy;++j){
			p = Point(kx[i],ky[j]);
			M[++cnt]=p;
		}
	}
	for(int i=1;i<=cz;++i){
		for(int j=i+1;j<=cz;++j){
			if(kz[j]-kz[i]==0) continue;
			double x=(bz[i]-bz[j])/(kz[j]-kz[i]);
			double y=kz[i]*x+bz[i];
			p = Point(x,y);
			M[++cnt]=p;
		}
	}
	sort(M+1,M+1+cnt);
	Ans=2,ac=1;
	for(int i=2;i<=cnt;){
		int c=1;
		for(;M[i]==M[i-1] && i<=cnt;++i,++c);
		if(c==1){
			if(Ans==2) ++ac;
			++i; continue;
		}
		c = (1.0f+sqrt(1+8*c))/2;
		if(Ans==c) ++ac;
		else if(Ans<c) Ans=c,ac=1; 
	}
	printf("%d %d\n",Ans,ac);
	return 0;
}
