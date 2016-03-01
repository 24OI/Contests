#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-8
#define md
#define N 1010
using namespace std;

struct ff { ll x,y;};
struct QQ { ff x,y;} q[N*N];
ll A[N],B[N],C[N];
int dian[2000010];

ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b);}
ll Abs(ll x) { return x>0?x:-x;}
void yuefen(ff &x)
{
	if (x.x==0) x.y=0;
	else
	{
		if (x.y<0) { x.x=-x.x; x.y=-x.y;}
		ll mx=max(Abs(x.x),Abs(x.y)),mn=min(Abs(x.x),Abs(x.y));
		ll gd=gcd(mx,mn);
		x.x/=gd; x.y/=gd;
	}
}

bool operator != (QQ a,QQ b) { return a.x.x!=b.x.x||a.x.y!=b.x.y||a.y.x!=b.y.x||a.y.y!=b.y.y;}

bool cmp(QQ a,QQ b)
{
	if (a.x.x!=b.x.x) return a.x.x<b.x.x;
	if (a.x.y!=b.x.y) return a.x.y<b.x.y;
	if (a.y.x!=b.y.x) return a.y.x<b.y.x;
	return a.y.y<b.y.y;
}

int main()
{
	freopen("star.in","r",stdin); freopen("star.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
	int w=0;
	for (int u=1;u<=n;u++)
	  for (int v=u+1;v<=n;v++)
	  {
	  	int i=u,j=v;
	  	if (A[i]*B[j]==A[j]*B[i]) continue;
	  	if (B[i]==0) swap(i,j);
	  	ff x=(ff){B[i]*C[j]-B[j]*C[i],A[i]*B[j]-A[j]*B[i]};
	  	ff y=(ff){A[i]*B[i]*C[j]-A[i]*B[j]*C[i]+A[i]*B[j]*C[i]-A[j]*B[i]*C[i],A[i]*B[i]*B[j]-A[j]*B[i]*B[i]};
	  	y.x=-y.x;
	  	yuefen(x); yuefen(y);
	  	q[++w]=(QQ){x,y};
	  }
	for (int i=0;i<=n;i++) dian[i*(i-1)/2]=i;
	sort(q+1,q+w+1,cmp);
	//for (int i=1;i<=w;i++) printf("%lld/%lld %lld/%lld\n",q[i].x.x,q[i].x.y,q[i].y.x,q[i].y.y);
	q[0].x.x=q[1].x.x-1;
	QQ now=q[0];
	int ans=0,sum=0,cnt=0;
	for (int i=1;i<=w;i++)
	{
		if (q[i]!=now) { now=q[i]; cnt=0;}
		cnt++;
		if (cnt>ans)
		{
			ans=cnt; sum=1;
		}
		else if(cnt==ans) sum++;
	}
	printf("%d %d\n",dian[ans],sum);
	return 0;
}
	

