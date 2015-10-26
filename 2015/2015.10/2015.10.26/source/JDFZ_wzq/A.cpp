#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000100
using namespace std;
typedef long long ll;
int n;
int b[N];
ll ans;
int vis[N];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&b[i]);
	if(n==2&&b[2]==1){puts("2");return 0;}
	else if(n==2&&b[2]==2){puts("1");return 0;}
	else if(n==2&&b[2]>2){puts("0");return 0;}
	int flag=0,cnt=0,no;
	vis[b[2]]=1;
	for(int i=3;i<=n;i++)
	{
		if(b[i]-2>=1&&(!vis[b[i]-2])&&(!vis[b[i]-1]))
		{flag=1;break;}
		else if(b[i]-2>=1&&vis[b[i]-2]&&(!vis[b[i]-1]))
		{cnt++,no=i;}
		vis[b[i]]=1;
	}
	if(flag){puts("0");return 0;}
	else if(cnt>1){puts("0");return 0;}
	if(!cnt)
	{
		memset(vis,0,sizeof(vis));
		int top=0;
		for(int i=1;i<=n;i++)
		{
			while(vis[top+1])top++;
			ans+=top+1;
			if(i!=n)
			{
				if(b[i+1]<=top+1)ans--;
				vis[b[i+1]]=1;
			}
		}
		printf("%lld\n",ans);
	}else
	{
		memset(vis,0,sizeof(vis));
		int top=0;
		for(int i=1;i<no;i++)
		{
			while(vis[top+1])top++;
			if(top==b[no]-2)ans++;
			vis[b[i+1]]=1;
		}
		printf("%lld\n",ans);
	}
}