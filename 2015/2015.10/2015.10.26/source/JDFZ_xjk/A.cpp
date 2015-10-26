#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 1000005
int n;
int a[N];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
		scanf("%d",&a[i]);
	int mx=0,tmp=0,pos,ans=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>mx+2) tmp=2;
		else if(a[i]==mx+2)
		{
			tmp++;
			pos=i;
		}
		mx=max(mx,a[i]);
	}
	if(tmp>1) puts("0");
	else if(tmp)
	{
		mx=0;
		for(int i=0;i<pos;i++)
		{
			mx=max(mx,a[i]);
			if(mx==a[pos]-2) ans++;
		}
		cout<<ans<<endl;
	}	
	else
	{
		mx=0;
		for(int i=1;i<=n;i++)
		{
			ans+=mx;
			mx=max(mx,a[i]);
		}
		cout<<ans+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
