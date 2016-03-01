#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long
#define N 100100

struct data{
	ll x1,x2,y1,y2;
};

ll a[N],b[N],c[N],t[N];
data s[N];
int n,m,i,j,k,ans,sum,r;
ll g;

ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}

bool cross(int u,int v){
	return a[u]*b[v]-a[v]*b[u]!=0;
}

bool comp(data u,data v){
	if(u.x1!=v.x1)return u.x1<v.x1;
	if(u.x2!=v.x2)return u.x2<v.x2;
	if(u.y1!=v.y1)return u.y1<v.y1;
	if(u.y2!=v.y2)return u.y2<v.y2;
	return false;
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		for(j=1;j<i;j++)
			if(cross(i,j)){
				k++;
				s[k].x1=b[i]*c[j]-b[j]*c[i];
				s[k].x2=a[i]*b[j]-a[j]*b[i];
				g=gcd(abs(s[k].x1),abs(s[k].x2));
				s[k].x1/=g;
				s[k].x2/=g;
				if(s[k].x1<0){
					s[k].x1*=-1;
					s[k].x2*=-1;
				}
				if(s[k].x1==0)s[k].x2=0;
				s[k].y1=a[i]*c[j]-a[j]*c[i];
				s[k].y2=a[j]*b[i]-a[i]*b[j];
				g=gcd(abs(s[k].y1),abs(s[k].y2));
				s[k].y1/=g;
				s[k].y2/=g;
				if(s[k].y1<0){
					s[k].y1*=-1;
					s[k].y2*=-1;
				}
				if(s[k].y1==0)s[k].y2=0;
			}
	}
	sort(s+1,s+k+1,comp);
	for(i=1;i<=k;i++)t[i]=1;
	ans=sum=0;
	for(i=1;i<=k;i++){
		if(i<k && s[i].x1==s[i+1].x1 && s[i].x2==s[i+1].x2
		&& s[i].y1==s[i+1].y1 && s[i].y2==s[i+1].y2 ){
			t[i+1]+=t[i];
			t[i]=0;
		}
		r=(int)sqrt(t[i]<<1)+1;
		if(r>ans){
			ans=r;
			sum=1;
		}else if(r==ans)sum++;
	}
	printf("%d %d\n",ans,sum);
	return 0;
}
