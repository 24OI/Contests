#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=128;
const int M=593119681;

int a[N],s[N];
int c[N][N],ans[N][N],p[N][N];
int n,m,i,j,k,t,sum,x,y,z,h;

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	m=1<<n;
	if(n>6){
		for(i=0;i<m;i++)scanf("%d",&a[i]);
		for(j=1;j<=t;j++){
			for(k=0;k<m;k++)s[k]=0;
			for(k=0;k<m;k++)
				for(h=0;h<n;h++){
					s[k^(1<<h)]+=a[k];
					s[k^(1<<h)]%=M;
				}	
			for(k=0;k<m;k++){
				a[k]+=s[k];
				a[k]%=M;
			}
		}
		for(i=0;i<m;i++)printf("%d ",a[i]);
		return 0;
	}
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		for(j=0;j<n;j++){
			k=i^(1<<j);
			c[i][k]=1;
		}
	}
	for(i=0;i<m;i++)c[i][i]=1;
	for(i=0;i<m;i++)ans[i][i]=1;
	for(i=t;i;i>>=1){
		if(i&1){
			for(x=0;x<m;x++)
				for(y=0;y<m;y++){
					p[x][y]=0;
					for(z=0;z<m;z++){
						p[x][y]+=(long long)ans[x][z]*c[z][y]%M;
						p[x][y]%=M;
					}
				}
			for(x=0;x<m;x++)
				for(y=0;y<m;y++)ans[x][y]=p[x][y];
		}
		for(x=0;x<m;x++)
			for(y=0;y<m;y++){
				p[x][y]=0;
				for(z=0;z<m;z++){
					p[x][y]+=(long long)c[x][z]*c[z][y]%M;
					p[x][y]%=M;
				}
			}
		for(x=0;x<m;x++)
			for(y=0;y<m;y++)c[x][y]=p[x][y];
	}
	for(i=0;i<m;i++){
		sum=0;
		for(j=0;j<m;j++){
			sum+=(long long)a[j]*ans[i][j];
			sum%=M;
		}
		printf("%d ",sum);
	}
	return 0;
}
