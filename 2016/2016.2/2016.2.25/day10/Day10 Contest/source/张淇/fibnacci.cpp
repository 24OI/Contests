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
#define maxn 100010
#define maxm 100010
#define eps 1e-10
#define inf 1000000000
#define ll long long
#define mod 1000000001
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=x;i<=(y);i++)
#define for3(i,x,y) for(int i=x;i>=(y);i--)
using namespace std;
int a[maxn],fi[maxn];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int n=read(),m=read();fi[0]=0;fi[1]=1;
	for2(i,2,n)fi[i]=(fi[i-1]+fi[i-2])%mod;
	for1(i,n){a[i]=read();a[i]=a[i]%mod;}
		for1(i,m){
			int x=read(),l=read(),r=read();
			if(x==1){
				for2(i,l,r)a[i]=(a[i]+fi[i-l+1])%mod;
			}
			if(x==2){
				int ans=0;
				for2(i,l,r)ans=(ans+a[i])%mod;
				printf("%d\n",ans%mod);
			}
		}
	return 0;
}
