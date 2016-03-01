#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;

bitset<32>s;
struct edge{int node;edge *next;}*e[2000],*p;
const int mo=593119681;
int a[100][100],d[100][100],tmp[100][100],b[2000],n,t,ans;

void add(int x,int y){
	p=new(edge);
	p->node=y;
	p->next=e[x];
	e[x]=p;
}

void init(){
	scanf("%d%d",&n,&t);
	for(int i=0;i<1<<n;i++)
	for(int j=0;j<1<<n;j++){
		s=(i^j);
		if(s.count()==1){
			add(i,j);
			if(n<=6)a[i][j]=1;
		}
	}
	if(n<=6)
	for(int i=0;i<1<<n;i++)a[i][i]=1;
	//b[0]=1;
	for(int i=0;i<1<<n;i++)scanf("%d",&b[i]),b[i]%=mo;
}

void chen(int a[][100],int b[][100],int size){
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	for(int l=0;l<size;l++)
	tmp[i][j]=(tmp[i][j]+(long long)a[i][l]*b[l][j]%mo)%mo;
	memcpy(a,tmp,sizeof(tmp));
}

void power(int a[][100],int y,int size){
	if(y==1)return;
	power(a,y/2,size);
	if((y&1)==0)chen(a,a,size);
	else chen(a,a,size),chen(a,d,size);
}

void work1(){
	memcpy(d,a,sizeof(a));
	power(a,t,1<<n);
	for(int i=0;i<1<<n;i++){
		ans=0;
		for(int j=0;j<1<<n;j++)
		ans=(ans+(long long)a[i][j]*b[j]%mo)%mo;
		printf("%d ",ans);
	}
	printf("\n");
}

void work2(){
	memcpy(d[0],b,sizeof(b));
	for(int i=1;i<=t;i++)
	for(int j=0;j<1<<n;j++){
		d[i&1][j]=d[i+1&1][j];
		for(p=e[j];p!=NULL;p=p->next){
			d[i&1][j]=(d[i&1][j]+d[i+1&1][p->node]);
			if(d[i&1][j]>=mo)d[i&1][j]-=mo;
		}
		if(i==t)printf("%d ",d[i&1][j]);
	}
	printf("\n");
}

int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	init();
	if(n<=6)work1();
	else work2();
	return 0;
}
