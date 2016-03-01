#include<cstdio>
#include<map>
#include<cmath>
#include<cstdlib>
#define N 1010
using namespace std;
int n,a[N],b[N],c[N];
int ans[N];
int D(int a,int b,int c,int d)
{
	return a*d-b*c;
}
bool cmp(double x){ if(abs(x)<1e-9) return 0; return 1; }
map<double,int>mp;
void cal(int i,int j)
{
	int cnt=0;
	double x=(double)D(-c[i],b[i],-c[j],b[j])/D(a[i],b[i],a[j],b[j]);
	double y=(double)D(a[i],-c[i],a[j],-c[j])/D(a[i],b[i],a[j],b[j]);
	if(mp.count(x*1000+y)) return;
	for(int k=1;k<=n;k++)
		if(cmp(a[k]*x+b[k]*y+c[k])==0)
			cnt++;
	mp[1000*x+y]=1;
	ans[cnt]++;
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cal(i,j);
	for(int i=n;i>=1;i--)
		if(ans[i]) printf("%d %d\n",i,ans[i]);
	return 0;
}
