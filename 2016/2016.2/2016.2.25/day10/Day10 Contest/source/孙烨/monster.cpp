#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n,i,N,j,k,t;
int a[1030];
int pow1[11]={1,2,4,8,16,32,64,128,256,512,1024};
bool f[1030][11];
int sum[1030];
const long long M=593119681;
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	cin>>n>>t;
	N=pow1[n];
	for(i=0;i<=N-1;i++) cin>>a[i];
	
	memset(f,0,sizeof(f));
	for(j=0;j<=N-1;j++) 
	{
		int m=j,tot=0;
		while(m)
		{
			if(m%2==1) f[j][tot]=1;
			tot++;
			m/=2;
		}
	}
	
	for(i=1;i<=t;i++)
	{
		for(j=0;j<=N-1;j++) sum[j]=0;
		for(j=0;j<=N-1;j++) 
		if(a[j])
		{
			for(k=0;k<=10;k++) 
			if(f[j][k]==0 && pow1[k]+j<=N)
			{
				int x=a[j+pow1[k]],y=a[j];
				sum[j+pow1[k]]=(sum[j+pow1[k]]+y)%M;
				sum[j]=(sum[j]+x)%M;
			}
		}
		for(j=0;j<=N-1;j++) a[j]=(a[j]+sum[j])%M;
	}
	for(i=0;i<=N-1;i++) cout<<a[i]<<' ';
	cout<<endl;
}
