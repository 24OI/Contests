#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int mo=1000000001;
int a[1010],b[1010];
int n;

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int i,j,op,l,r,ans,m;
	scanf("%d%d",&n,&m);
	a[0]=0;a[1]=1;for(i=2;i<=n;i++)a[i]=(a[i-1]+a[i-2])%mo;
//for(i=0;i<n;i++)/*cout<<a[i]<<' ';*/cout<<a[i]<<endl;
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			for(j=l;j<=r;j++)b[j]=(b[j]+a[j-l+1])%mo;
		}else{
			ans=0;
			for(j=l;j<=r;j++)ans=(ans+b[j])%mo;
			printf("%d\n",ans);
		}
	}
	return 0;
}
