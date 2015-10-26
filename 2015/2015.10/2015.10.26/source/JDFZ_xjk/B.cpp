#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,k,cnt;
struct node
{
	int id,flag,pos;
	node(int a,int b,int c):id(a),flag(b),pos(c){}
	node(){}
	bool operator <(const node &a)const{
		return pos<a.pos;
	}
}a[4005];
int f[2005],dp[2005][2005][2];
int pos[2005][2];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>n>>m>>k;
	for(int s,t,i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&t);
		a[++cnt]=node(i,0,s);
		a[++cnt]=node(i,1,t);
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++)
		pos[a[i].id][a[i].flag]=i;
	int ans=a[1].pos+m-a[cnt].pos;
	for(int i=1;i<cnt;i++)
	if(a[i].flag&&!a[i+1].flag) 
		ans+=a[i+1].pos-a[i].pos;
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<cnt;i++)
	if(!a[i].flag)
	{
		if(a[i+1].flag)
		{
			if(a[i].id==a[i+1].id)
			for(int j=k;j;j--)
				f[j]=max(f[j],f[j-1]+a[i+1].pos-a[i].pos);
		}
		else
		{
			int t=pos[a[i].id][1],tmp=1;
			memset(dp[tmp],-0x3f,sizeof(dp[tmp]));
			dp[1][0][0]=0;dp[1][1][1]=a[i+1].pos-a[i].pos;
			while(!a[t-1].flag)
			{
				tmp++;
				memset(dp[tmp],-0x3f,sizeof(dp[tmp]));
				for(int i=0;i<min(k+1,tmp);i++)
					dp[tmp][i][0]=max(dp[tmp-1][i][1],dp[tmp-1][i][0]);
				for(int i=1;i<=min(k,tmp);i++)
					dp[tmp][i][1]=max(dp[tmp-1][i-1][0],dp[tmp-1][i-1][1]+a[t].pos-a[t-1].pos);
				t=pos[a[t-1].id][1];
			}
			for(int i=1;i<=min(k,tmp);i++) 
				dp[tmp][i][1]+=a[t].pos-a[t-1].pos;
			for(int i=k;i;i--)
			for(int j=1;j<=min(tmp,i);j++)
				f[i]=max(f[i],f[i-j]+max(dp[tmp][j][0],dp[tmp][j][1]));
		}
	}
	int mx=0;
	for(int i=1;i<=k;i++) mx=max(mx,f[i]);
	cout<<mx+ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
