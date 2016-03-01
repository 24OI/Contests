#include <iostream>
#include <cstdio>
#include <cstdio>
#define ED printf("\n");
#define put(xxx) printf("%d ",xxx);
using namespace std;

int f[100],mod=1000000001;
int s[100000],n,c;

struct function
{
	int f;
	int le;
	int rt;
};

function w[100000];

void star()
{
	int i;
	f[0]=0;
	f[1]=1;
	for(i=2;i<100000;i++) f[i]=(f[i-1]%mod+f[i-2]%mod)%mod;
}

void inp()
{
	int i;
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++) scanf("%d",&s[i]);
	for(i=0;i<c;i++) scanf("%d%d%d",&w[i].f,&w[i].le,&w[i].rt);
}

void add(int l,int r)
{
	int i,k;
	for(i=l;i<=r;i++) s[i]=s[i]%mod+f[i-l+1]%mod;
}

void out()
{
	int i;
	for(i=1;i<=n;i++) put(s[i]);
}

void sum(int l,int r)
{
	long long i,su=0;
	for(i=l;i<=r;i++) su=(su%mod+s[i]%mod)%mod;
	cout<<su<<endl;
}

void fun()
{
	int i;
	for(i=0;i<c;i++)
	{
		if(w[i].f==1) add(w[i].le,w[i].rt);
		else sum(w[i].le,w[i].rt);
	}
}

int main()
{

	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);

	ios::sync_with_stdio(false);

	star();
	inp();
	fun();

	return 0;
	
}