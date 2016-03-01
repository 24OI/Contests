#include<algorithm>
#include<cstdio>
#define mo 1000000001
using namespace std;
int f[100005],a[100005],op,l,r,n,m,ans;
int main(){
	freopen("fibnacci.in","r",stdin);freopen("fibnacci.out","w",stdout);
	f[1]=1;scanf("%d%d",&n,&m);for(int i=2;i<=n;++i)f[i]=f[i-1]+f[i-2];
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int ii=1;ii<=m;++ii){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			for(int i=l;i<=r;++i)a[i]+=f[i-l+1],a[i]%=mo;
		}
		else{
			ans=0;
			for(int i=l;i<=r;++i){
				ans+=a[i];ans%=mo;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
