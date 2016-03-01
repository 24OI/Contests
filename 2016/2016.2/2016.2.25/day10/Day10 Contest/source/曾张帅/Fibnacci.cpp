#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
const int M=1000000000+1;
int n,m;
int l[200001],r[200001];
long long s[200001];
//int dcz[200001];
int op,ll,rr;
int i,j;
int f[100001];
int x;
void build(int ,int ,int );
//void cz(int ,int ,int );
void update(int );
int cx(int ,int ,int );
int main()
{
	freopen("Fibnacci.in","r",stdin);
	freopen("Fibnacci.out","w",stdout);
	cin>>n>>m;
	build(1,n,1);
	f[0]=0;f[1]=1;
	for(i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%M;
	for(i=1;i<=m;i++)
	{
		cin>>op>>ll>>rr;
		if(op==1)
		{
			update(1);
			//for(int k=1;k<=100;k++)cout<<s[k]<<' ';
		}
		else 
		{
			cout<<cx(ll,rr,1);
		}
	}
	return 0;
}
void build(int l0,int r0,int p)
{
	l[p]=l0;r[p]=r0;
	if(l0==r0)
	{
		cin>>x;
		s[p]=x%M;
	}
	else 
	{
		build(l0,(l0+r0)/2,p*2);
		build((l0+r0)/2+1,r0,p*2+1);
		s[p]=(s[p*2]+s[p*2+1])%M;
	}
}
void update(int p)
{
	if(l[p]==r[p])
	{
		if(l[p]>=ll&&l[p]<=rr)s[p]=(s[p]+f[l[p]-ll+1])%M;
	}
	else 
	{
		update(p*2);
		update(p*2+1);
		s[p]=s[p*2]+s[p*2+1];
	}
}
int cx(int ll,int rr,int p)
{
	if(ll==l[p]&&rr==r[p])return s[p];
	int mid=(l[p]+r[p])/2;
	if(mid<ll)return cx(ll,rr,p*2+1);
	else if(mid>=rr)return cx(ll,rr,p*2);
	else return (cx(ll,mid,p*2)+cx(mid+1,rr,p*2+1))%M; 
}
/*
5 2
0 0 0 0 0 
1 1 4
2 1 5
*/
