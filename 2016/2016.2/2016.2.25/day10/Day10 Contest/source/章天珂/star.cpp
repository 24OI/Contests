#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1000007
#define eps 1e-5
using namespace std;
int n;
struct point{
	double x,y;
}p[N];

bool cmp(point a,point b){
	if (abs(a.x-b.x) < eps) return a.y<b.y;
	return a.x<b.x;
}

double a[1007],b[1007],c[1007];
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]=(double)x;
		b[i]=(double)y;
		c[i]=(double)z;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if (a[i]*b[j]!=a[j]*b[i]){
				cnt++;
				if (a[i]==0) {
					p[cnt].y=-c[i]/b[i];	
					p[cnt].x=-(b[j]*p[cnt].y+c[j])/a[j];
					continue;
				}
				if (a[j]==0){
					p[cnt].y=-c[j]/b[j];
					p[cnt].x=-(b[i]*p[cnt].y+c[i])/a[i];	
					continue;
				}
				if (b[i]==0){
					p[cnt].x=-c[i]/a[i];
					p[cnt].y=-(a[j]*p[cnt].x+c[j])/b[j];
					continue;
				}
				if (b[j]==0){
					p[cnt].x=-c[j]/a[j];
					p[cnt].y=-(a[i]*p[cnt].x+c[i])/b[i];
					continue;
				}
				p[cnt].y=(a[j]*c[i]-a[i]*c[j])/(a[i]*b[j]-a[j]*b[i]);
				p[cnt].x=-(b[i]*p[cnt].y+c[i])/a[i];
			}
		}
	sort(p+1,p+cnt+1,cmp);
	int sum=1,max=0;;
	int maxan=1;
	for(int i=1;i<=cnt;i++){
		if (abs(p[i].x-p[i+1].x)<eps && abs(p[i].y-p[i+1].y)<eps) {
			sum++;
			continue;
		}
		if (sum>max) {max=sum;maxan=1;}
		else if (sum==max) maxan++;
		sum=1;
	}
	max=(int)(sqrt(1+8*max)+1)/2;
	printf("%d %d\n",max,maxan);	
}

