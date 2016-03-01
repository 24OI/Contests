#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,a[maxn],b[maxn],c[maxn];
struct star
{
	double x,y;
}s[maxn*maxn];
int ccc=0,cnt[maxn*maxn];
void work(int x,int y)
{
	double eps=0.000001;
	int q=a[x],w=b[x],e=c[x];
	int m=a[y],n=b[y],p=c[y];
	int judge=0;
	double ansx,ansy;
	if ((q*n==w*m) && ((q*p==m*e) || (w*p==n*e)))
		judge=1;
	else if ((q==0) && (n==0))
	{
		ansx=double(-p)/m;
		ansy=double(-e)/w;
	}
	else if ((w==0) && (m==0))
	{
		ansx=double(-e)/q;
		ansy=double(-p)/n;
	}
	else
	{
		if (w==0) ansx=double(-e)/q;
		else if (n==0) ansx=double(-p)/m;
		else if (e*n==w*p)
		{
			if (e*n==0) ansx=0;
			else judge=1;
		}
		else ansx=(double)(m*w-n*q)/(e*n-w*p);
		if (q==0) ansy=double(-e)/w;
		else if (m==0) ansy=double(-p)/n;
		else if (e*m==p*q)
		{
			if (e*m==0) ansy=0;
			else judge=1;
		}
		else ansy=(double)(n*q-w*m)/(e*m-p*q);
	}
	if (judge==0)
	{
		int flag=0;
		for (int i=1;i<=ccc;i++)	
		{
			if ((fabs(ansx-s[i].x)<=eps) && (fabs(ansy-s[i].y)<=eps))
			{
				cnt[i]=cnt[i]+1;
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			ccc++;	
			s[ccc].x=ansx;
			s[ccc].y=ansy;
			cnt[ccc]=1;
		}
	}
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			work(i,j);
	sort(cnt+1,cnt+ccc+1);
	int sum=1;
	for (int i=ccc-1;i>=1;i--)
	{
		if (cnt[i]==cnt[i+1])
			sum++;
		else break;
	}
	if (cnt[ccc]==1) printf("2 %d\n",sum);
	else printf("%d %d\n",cnt[ccc]*2/(n-1),sum);
	return 0;
}
