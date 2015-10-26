#include<stdio.h>
int n;
int A;
int B;
int C;
int D;
int E;
bool state[100005*5];
int m;
int l[100005];
int r[100005];
int ans=0x3f3f3f3f;
void dfs(int loc,int tim,int num)
{
	if(ans<tim)
	{
		return;
	}
	if(!num)
	{
		if(ans>tim)
		{
			ans=tim;
		}
		return;
	}
	if(loc==m)
	{
		return;
	}
	for(int i=loc+1;i<=m;i++)
	{
		int sum=0;
		for(int j=l[i];j<=r[i];j++)
		{
			if(state[j])
			{
				state[j]=0;
				sum++;
			}
			else
			{
				state[j]=1;
				sum--;
			}
		}
		dfs(i,tim+r[i]-l[i]+1,num-sum);
		for(int j=l[i];j<=r[i];j++)
		{
			if(state[j])
			{
				state[j]=0;
			}
			else
			{
				state[j]=1;
			}
		}
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d%d%d%d",&A,&B,&C,&D,&E);
	n=A+B+C+D+E;
	for(int i=A+1;i<=A+B;i++)
	{
		state[i]=1;
	}
	for(int i=A+B+C+1;i<=A+B+C+D;i++)
	{
		state[i]=1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	dfs(0,0,B+D);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
