#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std; 
int l[15],r[15];
int a,b,c,d,e,n,ans=0x3f3f3f3f;
bitset<500001> x,y,op[11];
int check(int t)
{
	int tmp=0,i,j;
	for(i=0;i<n;i++)
	if(t&(1<<i)) tmp+=r[i]-l[i]+1;
	if(tmp>ans) return 0;
	y=0;
	for(i=0;i<n;i++)
	if(t&(1<<i)) y^=op[i];
	if((x^y).any()) return 0;
	return tmp;
}
struct node{
	int val;
	bitset<255> b;
	bool operator <(const node &a)const{
		return val<a.val;
	}
}h[100505];
int st[300],top;
int vis[300];
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=a+1;i<=a+b;i++) x.set(i);
	for(int i=a+b+c+1;i<=a+b+c+d;i++) x.set(i);
	cin>>n;
	if(n<=10)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			for(int j=l[i];j<=r[i];j++)
			op[i].set(j);
		}
		for(int tmp,i=0;i<(1<<n);i++)
		if(tmp=check(i))
			ans=tmp;
		if(ans==0x3f3f3f3f) ans=-1;
		cout<<ans<<endl;
	}
	else if(a+b+c+d+e<=250)
	{
		int cnt=0;
		for(int i=1;i<=a;i++)
		{
			h[++cnt].val=0;
			h[cnt].b.set(i);	
		}
		for(int i=a+b+1;i<=a+b+c;i++)
		{
			h[++cnt].val=0;
			h[cnt].b.set(i);	
		}
		for(int i=a+b+c+d+1;i<=a+b+c+d+e;i++)
		{
			h[++cnt].val=0;
			h[cnt].b.set(i);	
		}
		for(int l,r,i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			h[++cnt].val=r-l+1;
			for(int j=l;j<=r;j++)
				h[cnt].b.set(j);
		}
		sort(h+1,h+cnt+1);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=a+b+c+d+e;j++)
			if(h[i].b.test(j))
			{
				if(!vis[j])
				{
					vis[j]=i;ans+=h[i].val;
					for(int k=1;k<=top;k++)
						h[st[k]].b^=h[i].b;
					st[++top]=i;
					break;
				}
				else h[i].b^=h[vis[j]].b;
			}
		}
		for(int i=1;i<=a+b+c+d+e;i++)
		if(!vis[i]) 
		{
			puts("-1");
			return 0;
		}
		cout<<ans<<endl;
	}
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
