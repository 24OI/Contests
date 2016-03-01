#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=10000010;
struct pair{int begin,end;}stack[N];
int n,now,i,j,k,tot,a[N],len[N],ans,sum=0;
inline int ReadInt()//优化接受int数，省时间，具体内容自己看懂，当成模板使用
{
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return data;
}
int main()
{
	freopen("array0.in","r",stdin);
	freopen("array0.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		j=ReadInt();
		if(tot&&a[tot]==j)len[tot]++;
		else {a[++tot]=j;len[tot]=len[tot-1]+1;}
		ans=max(ans,len[tot]-len[tot-1]);
	}
	n=tot;tot=0;a[0]=0x7fffffff;a[n+1]=0x80000000;
	for(i=1;i<=n;i++)
	{
		if(a[i-1]>a[i]&&a[i]<a[i+1])
		{
			while(tot&&a[stack[tot].begin]>a[i])tot--;
			stack[++tot].begin=i;stack[tot].end=-1;
		}
		if(a[i-1]<a[i]&&a[i]>a[i+1])
		{
			while(tot>1&&a[stack[tot-1].end]<=a[i])tot--;
			stack[tot].end=i;
			ans=max(ans,len[stack[tot].end]-len[stack[tot].begin-1]);
		}
		sum+=len[i];
	}
	if(stack[tot].end==-1)ans=max(ans,len[n]-len[stack[tot].begin-1]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
