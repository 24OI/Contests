#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define MAXN 100010
#define MAXM 100010
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-8
#define ll long long
#define a1 x.a
#define b1 x.b
#define c1 x.c
#define a2 y.a
#define b2 y.b
#define c2 y.c
struct L{
	int a;
	int b;
	int c;
	L(){
		
	}
	L(int x,int y,int z){
		a=x;
		b=y;
		c=z;
	}
	
};
struct pt{
	double x;
	double y;
	pt(){
		
	}
	pt(double _x,double _y){
		x=_x;
		y=_y;
	}
	friend bool operator <(pt x,pt y){
		return x.x!=y.x?x.x<y.x:x.y<y.y;
	}
};
inline bool hj(L x,L y){
	return b1*a2-b2*a1;
}
L a[MAXN];
int n;
map<pt,int>h;
int ans,anst;
pt jiao(L x,L y){
	if(!b1){
		swap(x,y);
	}
	double X=((double)c1*b2-c2*b1)/((double)b1*a2-b2*a1);
	double Y=((double)a1*X+c1)/((double)-b1);
	return pt(ceil(X*1000),ceil(Y*1000));
}
int main(){
	int i,j,x,y,z;
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[i]=L(x,y,z);
		for(j=1;j<i;j++){
			if(hj(a[i],a[j])){
				//*
				pt J=jiao(a[i],a[j]);
				h[jiao(a[i],a[j])]++;
				int t=h[J];
				if(t>ans){
					ans=t;
					anst=1;
				}else if(t==ans){
					anst++;
				}
				//*/
			}
		}
	}
	printf("%d %d\n",ans+1,anst);
	return 0;
}

/*
c1b2-c2b1
---------
b1a2-b2a1
*/
