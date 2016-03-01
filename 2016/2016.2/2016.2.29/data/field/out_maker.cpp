#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const long long N=100010;
long long mindiv[N],prime[N],miu[N],cnt[N],tot;
long long n[N],m[N],p[N],ans[N],y[N],order[N];
long long Case,f[N],t,q,i,j,k;
void add(long long a,long long c){for(long long i=a;i<N;i+=i&-i)f[i]+=c;}
long long search(long long a){long long r=0,i;for(i=a;i;i-=i&-i)r+=f[i];return r;}
long long cmp1(long long a,long long b){return cnt[a]<cnt[b];}
long long cmp2(long long a,long long b){return p[a]<p[b];}
void solve()
{
	miu[1]=1;
	for(i=2;i<N;i++)
	{
		if(!mindiv[i])
		{
			prime[++tot]=mindiv[i]=i;
			cnt[i]=1;miu[i]=-1;
		}
		for(j=1;j<=tot&&prime[j]<=mindiv[i]&&(k=prime[j]*i)<N;j++)
		{
			mindiv[k]=prime[j];
			cnt[k]=cnt[i]+1;
			if(mindiv[i]==prime[j])miu[k]=0;
			else miu[k]=-miu[i];
		}
	}
	for(i=1;i<N;i++)y[i]=i;
	sort(y+1,y+N,cmp1);
	scanf("%I64d",&Case);
	for(i=1;i<=Case;i++)scanf("%I64d%I64d%I64d",&n[i],&m[i],&p[i]);
	for(i=1;i<=Case;i++)order[i]=i;
	sort(order+1,order+Case+1,cmp2);
	for(tot=0,q=1;q<=Case;q++)
	{
		t=order[q];
		while(tot<N-1&&cnt[y[tot+1]]<=p[t])
		{
			tot++;
			for(i=y[tot];i<N;i+=y[tot])add(i,miu[i/y[tot]]);
		}
		if(n[t]>m[t])swap(n[t],m[t]);
		for(i=1;i<=n[t];i=j+1)
		{
			j=min(n[t]/(n[t]/i),m[t]/(m[t]/i));
			ans[t]+=(search(j)-search(i-1))*(n[t]/i)*(m[t]/i);
		}
	}
	for(i=1;i<=Case;i++)printf("%I64d\n",ans[i]);
}
char orde[30];
int main()
{
	for(long long tt=1;tt<=10;tt++)
	{
		sprintf(orde,"field%I64d.in",tt);
		freopen(orde,"r",stdin);
		sprintf(orde,"field%I64d.out",tt);
		freopen(orde,"w",stdout);
		solve();
		for(long long i=0;i<N;i++)mindiv[i]=prime[i]=miu[i]=cnt[i]=n[i]=m[i]=p[i]=ans[i]=y[i]=order[i]=f[i]=0;
		tot=Case=t=q=0;
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}

