#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+5,mod=1e9+1;

int f[maxn],pre[maxn];
int st[maxn],ed[maxn],b[maxn];
int a[maxn],sum[maxn];
int f1[maxn],f2[maxn];
int fx[maxn];
int n,m,Q,t;

void getfx(int p){
	fx[st[p]]=f1[p],fx[st[p]+1]=f2[p];
	for(int i=st[p]+2;i<=ed[p];i++)
		fx[i]=(fx[i-1]+fx[i-2])%mod;
	/*printf("%d:\n",p);
	for(int i=st[p];i<=ed[p];i++)
		printf("%d ",fx[i]);
	printf("\n");*/
}

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	
	scanf("%d%d",&n,&Q);
	m=sqrt(n);
	
	while(ed[t]<n){
		t++;
		st[t]=ed[t-1]+1;
		ed[t]=min(n,st[t]+m-1);
		for(int i=st[t];i<=ed[t];i++) b[i]=t;
	}
	st[t+1]=n+1;
	
	//for(int i=1;i<=t;i++)
		//printf("%d %d\n",st[i],ed[i]);
	
	f[1]=pre[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
		pre[i]=(f[i]+pre[i-1])%mod;
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[b[i]]=(sum[b[i]]+a[i])%mod;
	}
	
	while(Q--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		int p=b[l],q=b[r];
		//printf("%d %d\n",p,q);
		
		if(op==1){
			if(p==q){
				for(int i=l;i<=r;i++){
					int x=f[i-l+1];
					a[i]=(a[i]+x)%mod;
					sum[p]=(sum[p]+x)%mod;
				}
			}
			else{
				if(l==st[p]) p--;
				if(r==ed[q]) q++;
				
				for(int i=p+1;i<=q-1;i++){
					//printf("1~\n");
					int x=(pre[ed[i]-l+1]-pre[st[i]-l]+mod)%mod;
					sum[i]=(sum[i]+x)%mod;
					f1[i]=(f1[i]+f[st[i]-l+1])%mod;
					f2[i]=(f2[i]+f[st[i]-l+2])%mod;
					//printf("%d %d %d\n",sum[i],f1[i],f2[i]);
				}
				
				for(int i=l;i<=ed[p];i++){
					//printf("2~\n");
					int x=f[i-l+1];
					a[i]=(a[i]+x)%mod;
					sum[p]=(sum[p]+x)%mod;
				}
				
				for(int i=st[q];i<=r;i++){
					//printf("3~\n");
					int x=f[i-l+1];
					a[i]=(a[i]+x)%mod;
					sum[q]=(sum[q]+x)%mod;
				}
			}
		}
		else{
			int ans=0;
			if(p==q){
				getfx(p);
				for(int i=l;i<=r;i++){
					ans=(ans+a[i])%mod;
					ans=(ans+fx[i])%mod;
				}
			}
			else{
				if(l==st[p]) p--;
				if(r==ed[q]) q++;
				
				for(int i=p+1;i<=q-1;i++)
					ans=(ans+sum[i])%mod;
				
				if(l<=ed[p]) getfx(p);
				for(int i=l;i<=ed[p];i++){
					ans=(ans+a[i])%mod;
					ans=(ans+fx[i])%mod;
				}
				
				if(st[q]<=r) getfx(q);
				for(int i=st[q];i<=r;i++){
					ans=(ans+a[i])%mod;
					ans=(ans+fx[i])%mod;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
