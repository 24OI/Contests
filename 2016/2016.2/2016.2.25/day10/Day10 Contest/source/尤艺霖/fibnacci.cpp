#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=1000000001;
long long fib[120000];
long long opt,x1,x2;
long long fib2[120000][2],fibs[120000][2];
long long s[120000];
long long a[120000],n,m;
inline long long fibsum(long long s1,long long s2,long long l)
{
	return ((s1*fibs[l][0]%mod)+(s2*fibs[l][1])%mod)%mod;
}
inline long long fibnum(long long s1,long long s2,long long l)
{
	return ((s2*fib2[l][1]%mod)+(s1*fib2[l][0])%mod)%mod;
}
struct segment
{
	long long lef[520000];
	long long rig[520000];
	long long val[520000];
	long long lz1[520000];
	long long lz2[520000];
	long long siz[520000];
	inline void update(long long x)
	{
		val[x]=val[(x<<1)]+val[(x<<1)+1];
		val[x]%=mod;
	}
	inline void inc(long long x,long long s1,long long s2)
	{
//		printf("inc: %I64d %I64d %I64d %I64d\n",lef[x],rig[x],s1,s2);
		val[x]+=fibsum(s1,s2,siz[x]);
		val[x]%=mod;
		lz1[x]+=s1;
		lz1[x]%=mod;
		lz2[x]+=s2;
		lz2[x]%=mod;
	}
	inline void pushdown(long long x)
	{
		if(lz1[x]!=0)
		{
			inc((x<<1),lz1[x],lz2[x]);
			inc((x<<1)+1,fibnum(lz1[x],lz2[x],siz[(x<<1)]+1),fibnum(lz1[x],lz2[x],siz[(x<<1)]+2));
			lz1[x]=0;
			lz2[x]=0;
		}
	}
	inline void build(long long x,long long le,long long ri)
	{
		lef[x]=le;
		rig[x]=ri;
		val[x]=0;
		siz[x]=ri-le+1;
		lz1[x]=0;
		lz2[x]=0;
		if(le==ri)
		{
			return;
		}
		build((x<<1),le,(ri+le)/2);
		build((x<<1)+1,(le+ri)/2+1,ri);
	}
	inline void edit(long long x,long long le,long long ri,long long s1)
	{
//		printf("%I64d %I64d %I64d %I64d %I64d\n",lef[x],rig[x],le,ri,s1);
		if(le<=lef[x]&&ri>=rig[x])
		{
			s1=s1+lef[x]-le;
			inc(x,fib[s1],fib[s1+1]);
			return;
		}
		pushdown(x);		
		if(le<=rig[(x<<1)])edit((x<<1),le,ri,s1);
		if(ri>=lef[(x<<1)+1])edit((x<<1)+1,le,ri,s1);
		update(x);
	}
	inline long long query(long long x,long long le,long long ri)
	{
		if(le<=lef[x]&&ri>=rig[x])return val[x];
		pushdown(x);
		long long ss=0;
		if(le<=rig[(x<<1)])ss+=query((x<<1),le,ri);
		if(ri>=lef[(x<<1)+1])ss+=query((x<<1)+1,le,ri);
//		printf("%I64d %I64d %I64d %I64d %I64d\n",lef[x],rig[x],le,ri,ss);
		return ss%mod;
	}
}sgt;
inline long long query(long long l,long long r)
{
	return ((s[r]-s[l-1]+mod)%mod+sgt.query(1,l,r))%mod;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	fib[0]=0;
	fib[1]=1;
	for (long long i=2;i<=100200;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=mod;
	}
	fib2[1][0]=1;
	fib2[2][1]=1;
	for (long long i=3;i<=100200;i++)
	{
		fib2[i][0]=fib2[i-1][0]+fib2[i-2][0];
		fib2[i][0]%=mod;
		fib2[i][1]=fib2[i-1][1]+fib2[i-2][1];
		fib2[i][1]%=mod;
	}
	for (long long i=1;i<=100200;i++)
	{
		fibs[i][0]=fibs[i-1][0]+fib2[i][0];
		fibs[i][0]%=mod;
		fibs[i][1]=fibs[i-1][1]+fib2[i][1];
		fibs[i][1]%=mod;
	}
	scanf("%I64d %I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]%=mod;
		s[i]=s[i-1]+a[i];
		s[i]%=mod;
	}
	sgt.build(1,1,n);
	while (m--)
	{
		scanf("%I64d %I64d %I64d",&opt,&x1,&x2);
		if(opt==1)
		{
			sgt.edit(1,x1,x2,1);
		}
		else
		{
			printf("%I64d\n",query(x1,x2));
		}
	}
	return 0;
}
/*
10 800
0 0 0 0 0 0 0 0 0 0 
1 3 7
1 4 9
1 1 5
2 4 8
*/
