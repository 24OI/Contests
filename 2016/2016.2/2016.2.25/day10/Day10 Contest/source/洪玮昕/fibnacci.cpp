#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=200020,mod=1000000001;
struct point
{
	int f1,f2,sum,l,r;
}t[500];
int n,m,x,y,z,l,r,l1,r1,ans,n1,f[N],fsum[N],sum[N],s[N],ss[N],s1[N],sum1;
int main()
{
	int a,b,c,i,j;
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		s[i]%=mod;
		sum[i]=(sum[i-1]+s[i])%mod;
	}
	fsum[1]=f[1]=1;
	for(i=2;i<=n+1;i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
		fsum[i]=(fsum[i-1]+f[i])%mod;
	}
	a=sqrt(n);
	for(i=1;i<=n;i++)
	{
		if((i-1)*a+1>n) break;
		t[++z].l=(i-1)*a+1;
		t[z].r=i*a;
		if(t[i].r>n) t[z].r=n;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&l,&r);
		if(a==1)
		{
			for(i=1;i<=z;i++)
			{
				if(t[i].l>r) break;
				if(t[i].r<l) continue;
				if(t[i].l>=l&&t[i].r<=r)
				{
					t[i].sum=t[i].sum+fsum[t[i].r-l+1]-fsum[t[i].l-l];
					if(t[i].sum<0) t[i].sum+=mod;
					else t[i].sum%=mod;
					t[i].f1=(t[i].f1+f[t[i].l-l+1])%mod;
					t[i].f2=(t[i].f2+f[t[i].l-l+2])%mod;
				}
				else
				{
					l1=max(l,t[i].l);
					r1=min(r,t[i].r);
					for(j=l1;j<=r1;j++)
					{
						ss[j]=(ss[j]+f[j-l+1])%mod;
						t[i].sum=(t[i].sum+f[j-l+1])%mod;
					}
				}
			}
		}
		if(a==2)
		{
			ans=0;
			for(i=1;i<=z;i++)
			{
				if(t[i].l>r) break;
				if(t[i].r<l) continue;
				if(t[i].l>=l&&t[i].r<=r) ans=(ans+t[i].sum)%mod;
				else 
				{
					l1=max(l,t[i].l);
					r1=min(r,t[i].r);
					s1[t[i].l]=t[i].f1;
					s1[t[i].l+1]=t[i].f2;
					for(j=t[i].l+2;j<=t[i].r;j++)
						s1[j]=(s1[j-1]+s1[j-2])%mod;
					for(j=l1;j<=r1;j++)
					{
						ans=(ans+ss[j])%mod;
						ans=(ans+s1[j])%mod;
					}
				}
			}
			ans=ans+sum[r]-sum[l-1];
			if(ans<0) ans+=mod;
			else ans%=mod;
			printf("%d\n",ans);
		}
	}
}
