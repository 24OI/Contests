#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;
#define maxn 1005
#define eps 1e-9
int n,t,m;
double a[maxn],b[maxn],c[maxn];
map<int,int> v;
struct point{
	double x,y,i,j;
	
}p[maxn*maxn];
bool de(point a,point b){
		return (fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);
}
bool cmp(point a,point b){
		if (fabs(a.x-b.x)<eps) return a.y<b.y;
		return a.x<b.x;
}

int tot[maxn*maxn];
void read(int &n){
	 char c=getchar();
	 n=0;
	 while (c<'0' || c>'9') c=getchar();
	 while (c>='0' && c <='9') n=n*10+c-'0',c=getchar();
	 }
void cross(int i,int j){
	double x,y;
	if (a[i]==0 && a[j]==0) return;
	int ii=i,jj=j;
	if (a[j]==0) swap(i,j);
	if (a[i]==0){
		if (b[i]==0) return;
		y=-c[i]/b[i];
		x=(-b[j]*y-c[j])/a[j];
		p[++t].x=x;p[t].y=y;
		p[t].i=ii;p[t].j=jj;
		return;
	}
	double m=a[j]/a[i];
	b[i]*=m;c[i]*=m;
	b[i]-=b[j];c[i]-=c[j];
	if (b[i]==0) return;
	y=-c[i]/b[i];
	x=(-c[j]-b[j]*y)/a[j];
	p[++t].x=x;p[t].y=y;
	p[t].i=ii;p[t].j=jj;
}
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++){
	 	cross(i,j);
	 }
	sort(p+1,p+t+1,cmp);
	int ans=1;
	v[p[1].i]=1;v[p[1].j]=1;
	for (int i=2;i<=t;i++){
		if (de(p[i-1],p[i])){
			v[p[i].i]=1;v[p[i].j]=1;
		}
		else {
			m=v.size();
			if (m>ans) ans=m;
			tot[m]++;
			v.clear();
		}
	}
	m=v.size();
	if (m>ans) ans=m;
	tot[m]++;
    printf("%d %d",ans,tot[ans]);
	return 0;
}

