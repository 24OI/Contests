#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1005;
struct X{
	double x,y;
	X(int a1=0,int b1=0,int c1=0,int a2=0,int b2=0,int c2=0){
		if(a1!=0&&a2!=0)y=1.0*(a1*c2-a2*c1)/(a2*b1-a1*b2);
		else if(a1==0)y=-c1;
		else if(a2==0)y=-c2;
		if(b1!=0&&b2!=0)x=1.0*(b1*c2-b2*c1)/(a1*b2-a2*b1);
		else if(b1==0)x=-c1;
		else if(b2==0)x=-c2;
	}
}star[MAXN*MAXN];
double EPS=0.00001;
bool operator==(X x,X y){
	return abs(x.x-y.x)<=EPS&&abs(x.y-y.y)<=EPS;
}
bool cmp(X x,X y){
	if(abs(x.x-y.x)<=EPS)return x.y<y.y;
	return x.x<y.x;
}
int n,zx[MAXN][3],sum[MAXN],back,best;
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	for(int j=0;j<3;++j)
	scanf("%d",&zx[i][j]);
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
	if(i!=j){
		if(zx[i][0]==0&&zx[j][0]==0)continue;
		if(zx[i][1]==0&&zx[j][1]==0)continue;
		star[back++]=X(zx[i][0],zx[i][1],zx[i][2],zx[j][0],zx[j][1],zx[j][2]);
	}
	sort(star,star+back,cmp);
	int cnt=0;
	for(int i=0;i<=back;++i)
	if(star[i]==star[i-1])++cnt;
	else{
		++sum[cnt];
		best=max(best,cnt);
		cnt=1;
	}
	printf("%d %d",int(sqrt(2.0*best)+0.5),sum[best]);
	return 0;
}
