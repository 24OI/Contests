#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define ll long long
struct node{
	ll ux,uy,dx,dy;
	bool friend operator <(node x,node y){
		if(x.ux==y.ux){
			if(x.uy==y.uy) {
				if(x.dx==y.dx)return x.dy<y.dy;
				return x.dx<y.dx;
			}
			return x.uy<y.uy;
		}
		return x.ux<y.ux;
	}
	node(){}
	node(ll _ux,ll _uy,ll _dx,ll _dy){
		ux=_ux; uy=_uy; dx=_dx; dy=_dy;
	}
}x;
map<node,int>m;
int ma,num,n,light;
ll ux,uy,dx,dy,k,a[1100],b[1100],c[1100];

ll gcd(ll x,ll y){
	if(x%y==0)return y;
	return(y,x%y);
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int j=1;j<i;j++){
			if(b[i]==0&&b[j]==0)continue;
			k=a[i]*b[j]-a[j]*b[i];
			if(k==0)continue;
			ux=c[j]*b[i]-c[i]*b[j];
			uy=a[j]*c[i]-a[i]*c[j];
			dx=gcd(ux,k);
			ux/=dx;
			dx=k/dx;
			dy=gcd(uy,k);
			uy/=dy;
			dy=k/dy;
			if(ux==0)dx=1;
			if(uy==0)dy=1;
			m[node(ux,uy,dx,dy)]++;
		}
	}
	map<node,int>::iterator tmp;
	for(tmp=m.begin();tmp!=m.end();tmp++)
	if(tmp->second>ma){
		ma=tmp->second;
		x=tmp->first;
		num=1;
	}
	else if(tmp->second==ma)num++;
	for(int i=1;i<=n;i++){
		ux=-(a[i]*x.ux+c[i]*x.dx);
		if(b[i]==0)dx=x.dx;
		else dx=b[i]*x.dx;
		if(dx!=0&&ux!=0){
			k=gcd(ux,dx);
			ux/=k;
			dx/=k;	
		}
		if(ux==0)dx=1;
		if(ux==x.uy&&dx==x.dy)light++;
	}
	printf("%d %d\n",light,num);
	return 0;
}
