#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans=1;
int Hive,num[1000010];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&Hive);
	for(int i=1;i<Hive;i++)
	{
		scanf("%d",&num[i]);
	}
	int flag=1,flag2=1;
	if(num[1]==2)
	{
		flag2=0;
	}
	for(int i=2;i<=Hive;i++)
	{
		if(num[i-1]>i)
		{
			flag=0;
			break;
		}
		ans+=num[i-1];
	}
	if(!flag)
	{
		puts("0");
	}else if(!flag2)
	{
		puts("1");
	}else
	{
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
