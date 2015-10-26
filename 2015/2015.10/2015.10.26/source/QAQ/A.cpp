#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,a[N],tot;
LL sum,ans;
int id,tmp;
bool v[N],f;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&n);
	n--;
	for(int i=1;i<=n;i++)
	{
		ans+=sum+1;
		scanf("%d",&a[i]);
		if(!v[a[i]-1])
		{
			if(a[i]>2)
			{
				if(v[a[i]-2])
				{
					tot++;
					if(tot==1)
					{
						v[a[i]-1]=1;
						id=i;
						tmp=a[i]-1;
					}
					else 
					{
						f=1;
						break;
					}
				}
				else 
				{
					f=1;
				}
			}
			else 
			{
				if(a[i]==2)
				{
					tot=1;
					tmp=1,id=1;
					break;
				}
			}
		}
		if(!v[a[i]])
		{
			v[a[i]]=1;
			sum++;
		}
	}
//	cout<<tot<<" "<<id<<" "<<tmp;
	if(f||tot>1) cout<<0<<endl;
	else 
	{
		if(tot==0) cout<<ans+sum+1-n<<endl;
		else
		{
			for(int i=0;i<=n;i++)
			{
				//cout<<a[i]<<" "<<tmp-1<<endl;
				if(a[i]==tmp-1)
				{
					ans=id-i;
					//cout<<i<<" "<<id<<endl;
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

