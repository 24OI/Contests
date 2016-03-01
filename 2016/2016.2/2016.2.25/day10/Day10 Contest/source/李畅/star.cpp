#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct dis{
	double A;
	double B;
	double C;
}d[1010];

int n,G[100100],cnt;
double q[2][100100];

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		d[i].A=(double)a;d[i].B=(double)b;d[i].C=(double)c; 
	}
	for(int i=1;i<=n;i++){
		 for(int j=i+1;j<=n;j++){
		 	if(d[i].A/d[i].B!=d[j].A/d[j].B){
		 		double y=(d[i].C*d[j].A-d[i].A*d[j].C)/(d[i].A*d[j].B-d[j].A*d[i].B);
		 		double x=(d[i].B*d[j].C-d[i].C*d[j].B)/(d[i].A*d[j].B-d[j].A*d[i].B);
		 		int flag=0;
		 		for(int h=1;h<=cnt;h++){
		 			if(x==q[0][h] && y==q[1][h]){
					 G[h]++;flag=1;break;
					}
		 		}
		 		if(flag==1) continue;
				q[0][++cnt]=x;
				q[1][cnt]=y;
				G[cnt]=2;
		 	}
		 }
	}
	int best=0;
	for(int i=1;i<=cnt;i++)
	best=max(best,G[i]);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	if(G[i]==best) ans++;
	printf("%d %d",best,ans);
}
