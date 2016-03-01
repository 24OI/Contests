//DYJ,The last day!
//You mean everything to me.
//I can't live without you.
//I want to meet you at present.
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define maxn 1010
#define maxm 1010
#define eps 1e-10
#define inf 1000000000
#define ll long long
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=x;i<=(y);i++)
#define for3(i,x,y) for(int i=x;i>=(y);i--)
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll a[maxn],b[maxn],c[maxn];
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	int n=read();
	for1(i,n){a[i]=read();b[i]=read();c[i]=read();}
	int ans=1,cnt=0;
	for1(i,n){
		for2(j,i+1,n){
			int tmp=0;
			if(a[i]*b[j]!=a[j]*b[i]){
				tmp=2;
				for2(k,j+1,n){
					if(a[k]==0&&a[i]!=0)if((b[k]*c[j]*a[i]-c[i]*a[j]*b[k])==(b[j]*a[i]*c[k]-b[i]*a[j]*c[k])){tmp++;continue;}
					if(a[i]==0&&a[k]!=0)if((a[k]*b[j]*c[i]-c[j]*a[k]&b[i])==(a[j]*b[k]*c[i]-c[k]*a[j]*b[i])){tmp++;continue;}
					if((c[j]*a[i]-c[i]*a[j])*(b[k]*a[i]-b[i]*a[k])==(c[i]*a[k]-c[k]*a[i])*(b[i]*a[j]-b[j]*a[i])&&a[i]!=0&&a[k]!=0){tmp++;continue;}
				}
			}
			if(tmp==ans)cnt++;
			if(tmp>ans){ans=tmp;cnt=1;}
		}
	}
	printf("%d %d",ans,cnt);
	return 0;
}

