#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=100100;
const int M=1e9+1;

int a[N],c[N],s[N],f[N],l[N],r[N];
int n,m,i,j,k,b,t,ans,u,v;

void rebuild(){
	int i,j,p;
	for(i=1;i<=t;i++){
		p=1;
		for(j=l[i];j<=r[i];j++){
			a[j]+=f[p];
			p++;
		}
	}
	for(i=1;i<=n;i++)c[i]=(c[i-1]+a[i])%M;
	t=0;
}

int sum(int t,int u,int v){
	int x,y;
	if(u>r[t] || v<l[t])return 0;
	if(u<=l[t] && v>=r[t]){
		x=u-l[t];
		y=v-l[t]+1;
		return (s[y]-s[x]+M)%M;
	}
	if(u>=l[t]){
		x=u-l[t];
		y=r[t]-l[t]+1;
		return (s[y]-s[x]+M)%M;
	}
	if(v<=r[t]){
		x=0;
		y=v-l[t]+1;
		return (s[y]-s[x]+M)%M;
	}
}

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=(a[i-1]+a[i])%M;
	}
	s[1]=f[1]=1;
	for(i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%M;
		s[i]=(s[i-1]+f[i])%M;
	}
	b=sqrt(n);
	for(i=1;i<=m;i++){
		if(b==t)rebuild();
		scanf("%d",&k);
		if(k&1){
			t++;
			scanf("%d%d",&l[t],&r[t]);
		}else{
			scanf("%d%d",&u,&v);
			ans=(c[v]-c[u-1]+M)%M;
			for(j=1;j<=t;j++){
				ans+=sum(j,u,v);
				ans%=M;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
