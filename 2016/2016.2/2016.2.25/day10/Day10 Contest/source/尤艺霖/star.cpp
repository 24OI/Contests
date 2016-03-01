#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
double a[1200],b[1200],c[1200];
long double mat[2][3];
int fac[1200000],cnt;
inline long double fabs(long double x)
{
	if(x>0)return x;
	return -x;
}
const long double eps=1e-7;
inline bool zero(long double x)
{
	if(fabs(x)<eps)return true;
	return false;
}
pair<long double,long double>ine[1200000];
int hash[1200];
inline void inter(int x,int y)
{
	if(zero(a[x])&&zero(a[y]))return;
	if(zero(a[x]))swap(x,y);
	long double tp=a[y]/a[x];
	mat[1][1]=b[y]-b[x]*tp;
	mat[1][2]=c[y]-c[x]*tp;
	if(zero(mat[1][1])&&!zero(mat[1][2]))return;
	long double ty=mat[1][2]/mat[1][1];
	long double tx=(c[x]-ty*b[x])/a[x];
	cnt++;
	ine[cnt].first=tx;
	ine[cnt].second=ty;
//	printf("%lf %lf\n",(double)tx,(double)ty);
}
int n;
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
		c[i]=-c[i];
	}
	for (int i=1;i<n;i++)
	{
		fac[((i-1)*i)/2]=i;
		for (int j=i+1;j<=n;j++)
		{
			inter(i,j);
		}
	}
	int ct=0;
	sort(ine+1,ine+cnt+1);
	for (int i=1;i<=n;i++)
	{
		if(zero(ine[i].first-ine[i-1].first)&&zero(ine[i].second-ine[i-1].second)&&i!=1)
		{
			ct++;
		}
		else
		{
			if(i!=1)
			{
				hash[fac[ct]]++;
	//			printf("%d\n",ct);
			}
			ct=1;
		}
	}
	hash[fac[ct]]++;
	int cp=1100;
	while (hash[cp]==0)cp--;
	printf("%d %d\n",cp,hash[cp]);
	return 0;
}
