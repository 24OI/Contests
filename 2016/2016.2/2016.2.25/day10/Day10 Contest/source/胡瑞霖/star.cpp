#include<algorithm>
#include<cmath>
#include<cstdio>
#define esp 1E-8
using namespace std;
int sum[1000005],kk,num,tot,a[1005],b[1005],c[1005],n,bg,ed,back[1000005];
long long c1,c2,k;
double now1,now2;
struct data{double x,y;}d[1000005];
bool cmp1(data a,data b){return a.x<b.x;}
bool cmp2(data a,data b){return a.y<b.y;}
int main(){
	freopen("star.in","r",stdin);freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		kk=i*(i-1)>>1;back[kk]=i;
	}
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			c1=a[i]*c[j]-a[j]*c[i];c2=b[i]*c[j]-b[j]*c[i];
			k=a[i]*b[j]-a[j]*b[i];
			if(k==0)continue;
			tot++;d[tot].x=(c2)/(k);d[tot].y=-(c1/k);
		}
	sort(d+1,d+tot+1,cmp1);bg=1;ed=1;now1=d[1].x,now2=d[1].y;
	for(int i=2;i<=tot;++i){
		if(fabs(d[i].x-now1)<esp&&fabs(d[i].y-now2)<esp)ed++;
		else{
			sort(d+1+bg,d+1+ed,cmp2);bg=i;ed=i;now1=d[i].x;now2=d[i].y;
		}
	}
	sort(d+1+bg,d+1+tot,cmp2);now1=d[1].x,now2=d[1].y;num=1;
	for(int i=2;i<=tot;++i){
		if(fabs(d[i].x-now1)<esp&&fabs(d[i].y-now2)<esp)num++;
		else{
			now1=d[i].x;now2=d[i].y;sum[back[num]]++;num=1;
		}
	}
	
	sum[back[num]]++;
	for(int i=tot;i;--i){
		if(sum[i]){
			printf("%d %d",i,sum[i]);break;
		}
	}
	return 0;
}
