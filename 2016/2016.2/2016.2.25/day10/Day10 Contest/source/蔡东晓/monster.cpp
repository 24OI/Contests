#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int next[1100][1100],f[1100],a[1100],r[1100];
bool can[1100];
int n,t,m=1;
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	int i,j,k;
	for(i=0;i<=1090;i++)can[i]=false;
	can[1]=true;
	for(i=1;i<=n;i++){m*=2; can[m]=true;}
	for(i=0;i<m;i++)scanf("%d",&a[i]);
	for(i=0;i<=m;i++){
		f[i]=-1;
		for(j=0;j<=m;j++)next[i][j]=-1;
	}
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)if(can[i^j]){
			if(f[i]==-1)f[i]=j;
			else{
				k=f[i];while(next[i][k]!=-1)k=next[i][k];
				next[i][k]=j;
			}
		}
//for(i=0;i<m;i++){k=f[i];while(k!=-1){printf("%d ",k);k=next[i][k];}printf("\n");}
	for(i=1;i<=t;i++){
		for(j=0;j<m;j++)r[j]=a[j];
		for(j=0;j<m;j++){
			k=f[j];
			while(k!=-1){
				r[j]+=a[k];
				k=next[j][k];
			}
		}
		for(j=0;j<m;j++)a[j]=r[j];
	}
	for(i=0;i<m-1;i++)printf("%d ",a[i]);printf("%d\n",a[m-1]);
	return 0;
}
