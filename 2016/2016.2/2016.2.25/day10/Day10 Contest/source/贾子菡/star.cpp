#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int maxx=0;ll a[1005],b[1005],c[1005];int vis[100000];
int n;struct node{
double x;double y;
bool operator<(const node&rhs)const{return (x==rhs.x && y<rhs.y)||(x<rhs.x);}
};
map<node,int> table;
void check(int i,int j)
{if(double(a[i]/a[j])==double(b[i]/b[j]) && double(a[i]/a[j])==double(c[i]/c[j]))return;
if(!a[i] && !a[j])return;if(!b[i] && !b[j])return;
double x,y;
if(a[i]==0){y=(double)(-1*c[i]/b[i]);x=(double)((-1*c[j]-b[j]*y)/a[j]);}
else if(a[j]==0){y=(double)(-1*c[j]/b[j]);x=(double)((-1*c[i]-b[i]*y)/a[i]);}
else if(b[i]==0){x=(double)(-1*c[i]/a[i]);y=(double)((-1*c[j]-a[j]*y)/b[j]);}
else if(b[j]==0){x=(double)(-1*c[j]/a[j]);y=(double)((-1*c[i]-a[i]*y)/b[i]);}
else{
	y=(double)((-1*c[j]+a[j]*c[i]/a[i])*(-1*a[i]/(b[j]*a[j]-b[i])));
	x=(double)((-1*c[i]-b[i]*y)/a[i]);
}
node kk;kk.x=x,kk.y=y;
if(!table.count(kk))table[kk]=0;
table[kk]++;
maxx=max(table[kk],maxx);
vis[table[kk]]++;
}
int main()
{freopen("star.in","r",stdin);
freopen("star.out","w",stdout);
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
for(int i=0;i<n;i++)
for(int j=0;j<i;j++)
if(i!=j)
{check(i,j);
}
printf("%d %d",maxx,vis[maxx]);
return 0;
}
