#include<cstdio>
#define LL long long
using namespace std;
int n,tot;
LL a[1001],b[1001],c[1001];
struct com{
	LL q,w,e,r;
	int l;
}p[1000001];
LL gcd(LL a,LL b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
LL abs(LL x){
	if(x<0) return -x;
	else return x;
}
void get(LL &x1,LL &x2,LL &y1,LL &y2,int x,int y){
	x1=-c[x]*b[y]+c[y]*b[x];
	x2=b[y]*a[x]-a[y]*b[x];
	LL jk=gcd(abs(x1),abs(x2));
	if(jk=0){
		x1/=jk;
		x2/=jk;
	}
	y1=-c[x]*a[y]+c[y]*a[x];
	y2=a[y]*b[x]-b[y]*a[x];
	jk=gcd(abs(y1),abs(y2));
	if(jk!=0){
		y1/=jk;
		y2/=jk;
	} 
}
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
	}
	int maxl=2;
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==0&&a[j]==0&&(double)c[i]/b[i]*b[j]!=double(c[j])) continue;
			if(b[i]==0&&b[j]==0&&(double)c[i]/a[i]*a[j]!=double(c[j])) continue;
			if((double)a[i]/a[j]==(double)b[i]/b[j]&&(double)a[i]/a[j]!=(double)c[i]/c[j]);
			LL x1=0,x2=0,y1=0,y2=0;
 			get(x1,x2,y1,y2,i,j);
			bool f=false;
			for(int k=1;k<=tot;k++){
				if(p[k].q==x1&&p[k].w==x2&&p[k].e==y1&&p[k].r==y2){
					p[k].l++;
					f=true;
					if(p[k].l>maxl) maxl=p[k].l,num=1;
					else if(p[k].l==maxl) num++;
					break;
				}
			}
			if(!f){
				p[++tot].q=x1; p[tot].w=x2; p[tot].e=y1;p[tot].r=y2;
				p[tot].l=2;
				if(maxl==2) num++;
			}
		}
		tot=0;
	}
	printf("%d %d",maxl,num);
}
