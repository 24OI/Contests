#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1100005;
int vis[N],n,now,ans;
int a[N];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout); 
	scanf("%d",&n);n--;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int f=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx+1)f++;
		if(a[i]-mx>3){puts("0");return 0;}
		if(a[i]>i+1){puts("0");return 0;}
		
		mx=max(a[i],mx);
	}
	if(f>=2)puts("0");
	else if(f)
	{
		mx=0;int pos=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>mx+1){pos=i;break;}
			mx=max(a[i],mx);
		}
		if(pos==1)//前面没数了
		{puts("1");return 0;} 
		for(int i=1;i<pos;i++)
		if(a[i]==mx)//找到第一个mx的位置 后面就可以搞了 
		{ans=pos-i;break;}
		printf("%d\n",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			ans+=now+1;
			if(vis[x]==0)
			vis[x]=1,now++;
		}
		ans+=now+1;
		cout<<ans-n<<endl;
	}
}
/*
7
1 1 2 3 3 2
*/
		
