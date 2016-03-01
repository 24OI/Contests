#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const long long mod=593119681;

struct Mat
{
	long long d[130][130];
};

struct Edge
{
	int to,nxt;
}edge[300000*13];

int tot,fir[300000],n,t,s,vis[500000];
long long aaa[300000],bbb[300000];

void addedge(int x,int y)
{
	edge[tot]=(Edge) {y,fir[x]}; fir[x]=tot++;
}

Mat operator * (Mat o1,Mat o2)
{
	Mat ret;
	for (int i=0; i<s; i++)
	  for (int j=0; j<s; j++)
	  {
	  	ret.d[i][j]=0;
	  	for (int k=0; k<s; k++)
	  	  ret.d[i][j]+=(o1.d[i][k]*o2.d[k][j])%mod;
	  }
	return ret;
}

Mat operator ^ (Mat o1,int o2)
{
	Mat ret;
	for (int i=0; i<s; i++) ret.d[i][i]=1;
	while (o2)
	{
		if (o2&1) ret=ret*o1;
		o1=o1*o1;
		o2>>=1;
	}
	return ret;
}

int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d%d",&n,&t);
	s=(1<<n);
	if ((t<=1000)||(n>=10))
	{
		
		for (int i=0; i<s; i++)
		{
			scanf("%I64d",&aaa[i]);
			aaa[i]=aaa[i]%mod;
			bbb[i]=0;
		}
		for (int i=0; i<n; i++) vis[1<<i]=1;
		memset(fir,-1,sizeof(fir)); tot=0;
		for (int i=0; i<s; i++)
		  for (int j=0; j<s; j++)
		    if (vis[i^j]) 
		      addedge(i,j);
		while (t--)
		{
			for (int i=0; i<s; i++)
			  for (int j=fir[i]; j!=-1; j=edge[j].nxt)
			    bbb[edge[j].to]=(bbb[edge[j].to]+aaa[i])%mod;
			for (int i=0; i<s; i++) 
			{
				aaa[i]=(aaa[i]+bbb[i])%mod;
				bbb[i]=0;
			}
		}
		for (int i=0; i<s; i++) printf("%I64d\n",aaa[i]);
		return 0;
	}
	if (n<=7)
	{
		Mat aa;
		for (int i=0; i<s; i++) 
		{
			scanf("%I64d",&aa.d[i][i]);
			aa.d[i][i]=aa.d[i][i]%mod;
		}
		vis[0]=1;
		for (int i=0; i<n; i++) vis[1<<i]=1;
		memset(fir,-1,sizeof(fir)); tot=0;
		for (int i=0; i<s; i++)
		  for (int j=0; j<s; j++)
		    if (vis[i^j]) 
		      addedge(i,j);
		Mat bb;
		for (int i=0; i<s; i++)
		  for (int j=0; j<s; j++)
		    bb.d[i][j]=0;
		for (int i=0; i<s; i++)
		  for (int j=fir[i]; j!=-1; j=edge[j].nxt)
		    bb.d[i][edge[j].to]=1;
		//bb=bb^t;
		//cout<<endl;for(int i=0;i<s;i++){for(int j=0;j<s;j++) cout << bb.d[i][j] << ' ';cout<<endl;}
		aa=(bb^t)*aa;
		for (int i=0; i<s; i++) printf("%I64d\n",aa.d[i][0]);
		return 0;
	}
	return 0;
}
