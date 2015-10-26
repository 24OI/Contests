#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2111111
using namespace std;
int a[N];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n,mx=0;scanf("%d",&n);
	n--;
	long long ans=0,ok=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mx+2<=a[i]){
			if(mx+2==a[i]){
				if(ok>0)ok=-1;
				else ok=1;
			}
			else ok=-1;
		}
		mx=max(mx,a[i]);
	}
	if(ok){
		if(ok==-1)cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	mx=0;int gs=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		ans+=mx;
		gs++;
	}
	cout<<ans+1<<endl;
	return 0;
}
/******************
±£Ö¤bi>=1?
*******************/ 
