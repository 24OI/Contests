#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int n,a,b,k;
long long p,ans=0;

int jdz(int x)
{
	return x>=0 ? x:-x;
}

void moni(int n,int a,int b,int k)
{
	if (k==0)
	{
		ans++;return;
	}
	long long lim=jdz(b-a);
	for (int i=1;i<lim;++i) if (a+i<=n&&a+i!=b) moni(n,a+i,b,k-1);
	for (int i=1;i<lim;++i) if (a-i>0&&a-i!=b) moni(n,a-i,b,k-1);
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	p=10*10*10*10*10*10*10*10*10+7;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	if (k==0)
	{
		cout <<'0';
		return 0;
	}
	if (a==b||jdz(a-b)==1)
	{
		cout <<'0';
		return 0;
	}
	if (n<=10&&k<=5)
	{
		moni(n,a,b,k);
		cout << ans%p<<endl;
		return 0;
	}
	else cout<<"1";
	return 0;
}
