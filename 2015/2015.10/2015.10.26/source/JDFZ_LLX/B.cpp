#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int m;
int k;
struct yuangong
{
	int s;
	int t;
	int whs;
	int wht;
}y[2005];
struct data
{
	int tim;
	int num;
	bool own;
	bool dir;//0½ø1³ö 
}w[2005<<1];
bool cmp(data a,data b)
{
	return a.tim<b.tim;
}
int ans;
int cal(int loc)
{
	if(loc==2*n)
	{
		return m-w[loc].tim;
	}
	if(w[loc].dir)
	{
		if(w[loc].own)
		{
			if(w[loc+1].dir)
			{
				return w[loc+1].tim-w[loc].tim+cal(loc+1);
			}
			else
			{
				if(w[loc+1].own)
				{
					return w[loc+1].tim-w[loc].tim+cal(loc+1);
				}
				else
				{
					return cal(loc+1);
				}
			}
		}
		else
		{
			return cal(loc+1);
		}
	}
	else
	{
		if(w[loc+1].dir)
		{
			return w[loc+1].tim-w[loc].tim+cal(loc+1);
		}
		else
		{
			if(w[loc+1].own)
			{
				return w[loc+1].tim-w[loc].tim+cal(loc+1);
			}
			else
			{
				return cal(loc+1);
			}
		}
	}
}
void dfs(int loc,int num)
{
	if(num==k)
	{
		int tmp=w[1].tim+cal(1);
		if(tmp>ans)
		{
			ans=tmp;
		}
		return;
	}
	if(loc==n)
	{
		return;
	}
	for(int i=loc+1;i<=n;i++)
	{
		w[y[i].whs].own=1;
		w[y[i].wht].own=1;
		dfs(i,num+1);
		w[y[i].whs].own=0;
		w[y[i].wht].own=0;
	}
}
struct xxx
{
	int num1;
	int num2;
	int li;
}yy[2005<<4];
int cnt;
bool cmpx(xxx a,xxx b)
{
	return a.li>b.li;
}
void greedy()
{
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		yy[i].num1=i;
		yy[i].li=0;;
		int tims=y[i].whs;
		int timt=y[i].wht;
		if(w[tims+1].dir)
		{
			yy[i].li+=w[tims+1].tim-w[tims].tim;
		}
		if(!w[timt-1].dir||(w[timt-1].dir&&w[timt-1].num==i))
		{
			yy[i].li+=w[timt].tim-w[timt-1].tim;
		}
		else
		{
			yy[++cnt].num1=i;
			yy[cnt].num2=w[timt-1].num;
			yy[cnt].li+=w[timt].tim-w[timt-1].tim;
			if(w[tims+1].dir)
			{
				yy[cnt].li+=w[tims+1].tim-w[tims].tim;
			}
			timt=y[yy[cnt].num2].wht;
			if(!w[timt-1].dir||w[timt-1].num==yy[cnt].num1)
			{
				yy[cnt].li+=w[timt].tim-w[timt-1].tim;
			}
		}
		yy[i].li*=2;
	}
	sort(yy+1,yy+1+cnt,cmpx);
	for(int i=1;i<=k;i++)
	{
		if(yy[i].num2)
		{
			if((k-i)>1)
			{
				w[y[yy[i].num1].whs].own=1;
				w[y[yy[i].num1].wht].own=1;
				w[y[yy[i].num2].whs].own=1;
				w[y[yy[i].num2].wht].own=1;
				k--;
			}
			else
			{
				k++;
			}
		}
		else
		{
			w[y[yy[i].num1].whs].own=1;
			w[y[yy[i].num1].wht].own=1;
		}
	}
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&y[i].s,&y[i].t);
		w[2*i-1].tim=y[i].s;
		w[2*i].tim=y[i].t;
		w[2*i-1].dir=1;
		w[2*i].dir=0;
		w[2*i-1].num=i;
		w[2*i].num=i;
	}
	sort(w,w+1+2*n,cmp);
	for(int i=1;i<=2*n;i++)
	{
		if(w[i].dir)
		{
			y[w[i].num].whs=i;
		}
		else
		{
			y[w[i].num].wht=i;
		}
	}
	if(n<=20)
	{
		dfs(0,0);
		printf("%d\n",ans);
	}
	else
	{
		greedy();
		printf("%d\n",w[1].tim+cal(1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
