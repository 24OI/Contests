#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const double eps=1e-8;
const int N=1000+5;
struct line{
	ll a,b,c;
}a[N];
struct point{
	double x,y;
	bool operator<(const point &rhs)const{
		if(fabs(x-rhs.x)<eps)return y<rhs.y;
		return x<rhs.x;
	}
};
vector<point>ins;
void calc(line a,line b){
	ll D=a.a*b.b-a.b*b.a;
	if(!D)return;
	ll D1=a.c*b.b-a.b*b.c;
	ll D2=a.a*b.c-a.c*b.a;
	ins.push_back((point){double(D1/D),double(D2/D)});
}
void solve(int n){
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	calc(a[i],a[j]);
}
bool dcmp(point a,point b){
	return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
}
int main(){
	freopen("star.in","r",stdin);
	freopen("stat.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld %lld %lld",&a[i].a,&a[i].b,&a[i].c);
	solve(n);
	sort(ins.begin(),ins.end());
	int cnt=1,ans=1;
	for(int i=1;i<ins.size();i++){
		if(dcmp(ins[i-1],ins[i]))cnt++;
		else{
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	ans=max(ans,cnt);
	int tot=0;cnt=1;
	for(int i=1;i<ins.size();i++){
		if(dcmp(ins[i-1],ins[i]))cnt++;
		else{
			if(cnt==ans)tot++;
			cnt=1;
		}
	}
	if(cnt==ans)tot++;
	int tmp=1;
	while(true){
		if(tmp*(tmp-1)/2==ans)break;
		tmp++;
	}
	printf("%d %d\n",tmp,tot);
	return 0;
}
	
