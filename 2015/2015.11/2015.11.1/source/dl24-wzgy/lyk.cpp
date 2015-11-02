#include<cstdio>
#define f(x,y,z) for (int x=(y);x<=(z);++x)
#define maxn 100007
int a[maxn],b1[maxn],b2[maxn],b[maxn];
void swap(int &a,int &b)
{
	int c=a;a=b;b=c;
}
int min(int a,int b) {return a<b ? a:b;}
int max(int a,int b) {return a>b ? a:b;}
int merge_sort(int l,int r)
{
	if (l==r) return 0;
	if (l+1==r) 
	{
		if (a[l]>a[r]) {swap(a[l],a[r]);return 1;}
		else return 0;
	}
	int m=(l+r)>>1;
	int rnt=0;
	rnt+=merge_sort(l,m);rnt+=merge_sort(m+1,r);
	int p1=l,p2=m+1,p=l;
	f(i,l,m) b1[i]=a[i];
	f(i,p2,r) b2[i]=a[i];
	while (p1<=m&&p2<=r)
	{
		if (b1[p1]<b2[p2]) a[p++]=b1[p1++];
		else {a[p++]=b2[p2++];rnt+=m-p1+1;}
	}
	if (p1<=m) f(i,p1,m) a[p++]=b1[p1++];
	if (p2<=r) f(i,p2,r) a[p++]=b2[p2++];
	return rnt;
}
int main()
{
	freopen("lyk.in","r",stdin);
	freopen("lyk.out","w",stdout);
	int n;
	scanf("%d",&n);
	f(i,1,n) scanf("%d",&a[i]);
	f(i,1,n) b[i]=a[i];
	bool later=merge_sort(1,n)%2;
	int m,l,r;
	scanf("%d",&m);
	f(i,1,m)
	{
		scanf("%d%d",&l,&r);
		if (l>r) swap(l,r);
		int mi=min(b[l],b[r]);
		int ma=max(b[l],b[r]);
		f(j,l+1,r) if (b[l]>b[j]) later=!later;
		f(j,l,r-1) if (b[r]>b[j]) later=!later;
		// later=!later;
		f(j,l+1,r-1) if (b[j]>mi&&b[j]<ma) later=!later;
		if (later) printf("1\n");
		else printf("0\n");
		swap(b[l],b[r]);
	}
	return 0;
}