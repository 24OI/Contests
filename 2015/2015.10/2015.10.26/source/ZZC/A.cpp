#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool v[1000010];
int a[1000010];
int tot,sum,n,ed;
long long ans;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;n--;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=(long long)sum+1;
		if(v[a[i]]!=1) {
			v[a[i]]=1;
			sum++;
			if(!v[a[i]-2]&&a[i]!=1&&a[i]!=2) 
			{
				//cout<<a[i];
				puts("0");
				return 0;
			}
			if(!v[a[i]-1]&&a[i]!=1){
				v[a[i]-1]=1;
				tot++;
				if(tot>1){
					puts("0");
					return 0;
				}
				for(int j=1;j<i;j++){
					if(a[j]==a[i]-2){
						ed=i-j-1;
						break;
					}
				}
			}
			
		}
	}
	if(tot==0){
		ans+=sum+1-n;
		cout<<ans<<endl;	
	}
	if(tot==1)
	{
		cout<<ed+1<<endl;
	}
	return 0;
}
/*
5
1 3 1 3
*/
