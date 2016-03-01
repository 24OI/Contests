#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-8
#define md 1000000001
#define N 100010
using namespace std;
struct Ju
{
	ll a[3][3]; int x,y;
	ll *operator [] (int x) { return a[x];}
} Sum[N],Fib[N],a,mid;
int p[N];
struct TR { int l,r,x,y,sum,sz;} tr[4*N];
int n,Ans;

void operator *= (Ju &a,Ju &b)
{
	mid.x=a.x; mid.y=a.y;
	memset(mid.a,0,sizeof(mid.a));
	for (int i=0;i<a.x;i++)
	  for (int j=0;j<b.y;j++)
	    for (int k=0;k<a.y;k++)
	      mid[i][j]=(mid[i][j]+a[i][k]*b[k][j])%md;
	a=mid;
}

void ycl()
{
	a.x=2; a.y=2;
	a[0][0]=0; a[0][1]=1;
	a[1][0]=1; a[1][1]=1;
	Fib[0].x=Fib[0].y=2;
	Fib[0].a[0][0]=Fib[0].a[1][1]=1;
	for (int i=1;i<=n;i++)
	{
		Fib[i]=Fib[i-1];
		Fib[i]*=a;
	}
	a.x=3; a.y=3;
	a[0][0]=0; a[0][1]=1; a[0][2]=1;
	a[1][0]=1; a[1][1]=1; a[1][2]=1;
	a[2][0]=0; a[2][1]=0; a[2][2]=1;
	Sum[0].x=Sum[0].y=3;
	Sum[0].a[0][0]=Sum[0].a[1][1]=Sum[0].a[2][2]=1;
	for (int i=1;i<=n;i++)
	{
		Sum[i]=Sum[i-1];
		Sum[i]*=a;
	}
}

void build(int i,int l,int r)
{
	tr[i].l=l; tr[i].r=r; tr[i].sz=r-l+1;
	if (l==r) { tr[i].sum=p[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum; if (tr[i].sum>=md) tr[i].sum-=md;
}

void tagit(int i,int x,int y)
{
	if (tr[i].l==tr[i].r)
	{
		tr[i].sum+=x; if (tr[i].sum>=md) tr[i].sum-=md;
	}
	else
	{
		a.x=1; a.y=3; a[0][0]=x; a[0][1]=y; a[0][2]=x+y; if(a[0][2]>=md) a[0][2]-=md; 
		a*=Sum[tr[i].sz-2];
		tr[i].sum+=a[0][2]; if (tr[i].sum>=md) tr[i].sum-=md;
		tr[i].x+=x; if (tr[i].x>=md) tr[i].x-=md;
		tr[i].y+=y; if (tr[i].y>=md) tr[i].y-=md;
	}
}

void release(int i)
{
	if (tr[i].x>0||tr[i].y>0)
	{
		int x=tr[i].x,y=tr[i].y; tr[i].x=tr[i].y=0;
		tagit(i<<1,x,y);
		a.x=1; a.y=2; a[0][0]=x; a[0][1]=y;
		a*=Fib[tr[i<<1].sz];
		tagit(i<<1|1,a[0][0],a[0][1]);
	}
}
	

void modify(int i,int l,int r,int x,int y)
{
	//printf("modify [%d %d] %d %d\n",tr[i].l,tr[i].r,x,y);
	if (l<=tr[i].l&&tr[i].r<=r)
	{
		tagit(i,x,y);
		return;
	}
	release(i);
	int mid=(tr[i].l+tr[i].r)>>1;
	if (l<=mid) modify(i<<1,l,r,x,y);
	if (mid+1<=r)
	{
		a.x=1; a.y=2; a[0][0]=1; a[0][1]=1;
		int mi=max(mid-l+1,0);
		a*=Fib[mi];
		modify(i<<1|1,l,r,a[0][0],a[0][1]);
		
	}
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum; if (tr[i].sum>=md) tr[i].sum-=md;
}

void query(int i,int l,int r)
{
	if (l<=tr[i].l&&tr[i].r<=r)
	{
		Ans+=tr[i].sum; if (Ans>=md) Ans-=md;
		return;
	}
	release(i);
	int mid=(tr[i].l+tr[i].r)>>1;
	if (l<=mid) query(i<<1,l,r);
	if (mid+1<=r) query(i<<1|1,l,r);
}

int main()
{
	freopen("fibnacci.in","r",stdin); freopen("fibnacci.out","w",stdout);
	int m,ty,l,r;
	scanf("%d%d",&n,&m);
	ycl();
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ty,&l,&r);
	//	printf("%d %d %d\n",ty,l,r);
		if (ty==1)
		{
			modify(1,l,r,1,1);
		}
		else
		{
			Ans=0; query(1,l,r);
			printf("%d\n",Ans);
		}
	//	for (int i=1;i<=7;i++) printf("%d [%d %d] sum %d x %d y %d\n",i,tr[i].l,tr[i].r,tr[i].sum,tr[i].x,tr[i].y);
	//	printf("\n");
	}
	return 0;
}


