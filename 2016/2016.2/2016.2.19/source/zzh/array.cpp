#include<cstdio>
#include<algorithm>

int n,b[110000],a[110000],min,p,ans;
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	ans=0;
	for (int i=1;i<=n;i++){
		min=2147483647;
		for (int j=i;j>=1;j--){
			if (b[j]>b[i]) break;
			if (b[j]<=min){p=j;min=b[j];}
		}
		//printf("%d",i-p+1);
		if (ans<i-p+1) ans=i-p+1;
	}
	printf("%d\n",ans);
	return 0;
}
