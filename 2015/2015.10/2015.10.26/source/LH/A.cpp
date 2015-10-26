#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000070;

int b[maxn];
bool vis[maxn];
int n;
int sum;

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&b[i]);
	if (b[1]>2||b[1]<1){
		printf("0");
		fclose(stdout);
		return 0;
	}
	if (b[1]==2){
		vis[0]=1;
		vis[1]=1;
		vis[2]=1;
		for (int i=2;i<n;i++){
			if ((b[i]-1<0)||(!vis[b[i]-1])){
				printf("0");
				fclose(stdout);
				return 0;
			}
			else vis[b[i]]=1;
		}
		printf("1");
		fclose(stdout);
		return 0;
	}
	else{
		for (int i=1;i<n;i++) if (b[i]<=0){
			printf("0");
			fclose(stdout);
			return 0;
		}
		long long cnt=1;
		int m=0,w=0,last=-1;
		sum=1;
		vis[1]=1;
		for (int i=1;i<n;i++){
			if (!vis[b[i]]){
				if (m!=0){
					if (m!=b[i]){
						printf("0");
						fclose(stdout);
						return 0;
					}
				}
				else{
					m=b[i];
					w=i;
				}
			}
			if (!vis[b[i]+1]){
				sum++;
			}
			vis[b[i]+1]=1;
			if (m==0){
				cnt+=sum-1;
			}
		}
		if (m==0){
			cout<<cnt;
			fclose(stdout);
			return 0;
		}
		else{
			printf("1");
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdout);
	return 0;
}
