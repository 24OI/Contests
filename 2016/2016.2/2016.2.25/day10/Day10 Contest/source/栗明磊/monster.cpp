#include<cstdio>
#include<cstring>
#define for4(i,x) for(int i=head[x],y=edges[i].go;i;i=edges[i].next,y=edges[i].go)
int n,t;
struct e{
	int go,next;
}edges[1<<12];
int a[1<<10+10],b[1<<10+10],tot,head[1<<10+10],*x,*z,*tem;
void add(int x,int y){
	if(x!=y)edges[++tot]=(e){y,head[x]};head[x]=tot;
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	n=1<<n;
	for(int i=0;i<n;i++){
		int j=0;
		while((i^(1<<j))<n)add(i,i^(1<<j)),j++;
		scanf("%d",&a[i]);
	}
	x=a;z=b;
	for(int i=1;i<=t;i++){
		for(int j=0;j<n;j++){
			z[j]=(z[j]+x[j])%593119681;			
			for4(k,j){
				z[y]=(z[y]+x[j])%593119681;
			}
		}
		tem=x;x=z;z=tem;
		memset(z,0,4*n);
	}
	for(int i=0;i<n;i++)printf("%d ",x[i]);
}