#include<iostream>
#include<cstdio>
#define N 100010
#define p 1000000001
using namespace std;
int n,m,op,u,v,a[N],l[N*4],r[N*4],sum[N*4],la[N*4],fi[N],sq[N];
void pu(int k)
{
	sum[k]=(sum[k*2]+sum[k*2+1])%p;
}
void pd(int k)
{
	if(l[k*2]&&la[k*2]) pd(k*2);
	if(l[k*2+1]&&la[k*2+1]) pd(k*2+1);
	int rr=la[k]+r[k]-l[k],mid=(la[k]+rr)/2;
	(sum[k*2]+=((sq[mid]-sq[la[k]-1])%p+p)%p)%=p;
	la[k*2]=la[k];
	(sum[k*2+1]+=((sq[rr]-sq[mid])%p+p)%p)%=p;
	la[k*2+1]=mid+1;
	la[k]=0;
}
void build(int k,int z,int y)
{
	l[k]=z;
	r[k]=y;
	if(z==y)
	{
		sum[k]=a[z];
		return;
	}
	int mid=(z+y)/2;
	build(k*2,z,mid);
	build(k*2+1,mid+1,y);
	pu(k);
}
void ch(int k,int z,int y,int u)
{
	if(la[k]) pd(k);
	if(l[k]==z&&r[k]==y)
	{
		la[k]=u;
		(sum[k]+=((sq[u+y-z]-sq[u-1])%p+p)%p)%=p;
		return;
	}
	int mid=(l[k]+r[k])/2;
	if(y<=mid) ch(k*2,z,y,u);
	else if(z>mid) ch(k*2+1,z,y,u);
	else ch(k*2,z,mid,u),ch(k*2+1,mid+1,y,u+mid-z+1);
	pu(k);
}
int ask(int k,int z,int y)
{
	if(la[k]) pd(k);
	if(l[k]==z&&r[k]==y) return sum[k];
	int mid=(l[k]+r[k])/2;
	if(y<=mid) return ask(k*2,z,y);
	else if(z>mid) return ask(k*2+1,z,y);
	else return (ask(k*2,z,mid)+ask(k*2+1,mid+1,y))%p;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	fi[1]=1;
	for(int i=2;i<=n;i++) fi[i]=(fi[i-1]+fi[i-2])%p;
	for(int i=1;i<=n;i++) sq[i]=(sq[i-1]+fi[i])%p;
	while(m--)
	{
		scanf("%d%d%d",&op,&u,&v);
		if(op==1) ch(1,u,v,1);
		else printf("%d\n",ask(1,u,v));
	}
}
