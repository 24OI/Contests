#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
struct po{long long zx,mx,zy,my;bool fx,fy;};
bool operator < (const po& a,const po& b){
	if(a.fx!=b.fx)return a.fx<b.fx;
	if(a.zx!=b.zx)return a.zx<b.zx;
	if(a.mx!=b.mx)return a.mx<b.mx;
	if(a.fy!=b.fy)return a.fy<b.fy;
	if(a.zy!=b.zy)return a.zy<b.zy;
	if(a.my!=b.my)return a.my<b.my;
	return false;
}
int n;
int a[1010],b[1010],c[1010];
int an[1000100];
vector<po> v;
map<po,int> ma;
po pp;
long long gcd(long long a,long long b){
	return b==0 ? a : gcd(b,a%b);
}
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	int i,j,a1,a2,b1,b2,c1,c2,l;
	long long zx,mx,zy,my,g;
	bool fx,fy;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++){
		a1=a[i];a2=a[j];
		b1=b[i];b2=b[j];
		c1=c[i];c2=c[j];
		fx=fy=1;//正数符号定为1； 
		zx=(long long)c1*b2-c2*b1;if(zx<0){fx=!fx;zx=0-zx;}
		mx=(long long)a2*b1-a1*b2;if(mx<0){fx=!fx;mx=0-mx;}
		zy=(long long)c1*a2-c2*a1;if(zy<0){fy=!fy;zy=0-zy;}
		my=(long long)a1*b2-a2*b1;if(my<0){fy=!fy;my=0-my;}
		if(!zx||!mx)fx=1;if(!zy||!my)fy=1;
		g=gcd(zx,mx);if(g){zx/=g;mx/=g;}
		g=gcd(zy,my);if(g){zy/=g;my/=g;}
		pp.fx=fx;pp.fy=fy;pp.zx=zx;pp.zy=zy;pp.mx=mx;pp.my=my;
		v.push_back(pp);
	}
	l=v.size();
	for(i=0;i<l;i++)if(!ma.count(v[i]))ma[v[i]]=1;else ma[v[i]]+=1;
	for(i=0;i<l;i++){a[i]=ma[v[i]];ma[v[i]]=0;}
	int ax=0;for(i=0;i<l;i++)ax=max(ax,a[i]);
	int ans=0;for(i=0;i<l;i++)if(a[i]==ax)ans++;
	//for(i=0;i<l;i++)printf("%d ",a[i]);printf("\n");
	int m=floor(sqrt(ax*2));
	printf("%d %d\n",m+1,ans);
	return 0;
}
