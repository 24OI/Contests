#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
struct Point
{
	int x,y;
	inline bool operator<(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	inline Point(float a=0,float b=0){x=*(int*)&a,y=*(int*)&b;}
}p[1000010],P;
map<Point,int>G;
map<Point,bool>M;
int n,A[1010],B[1010],C[1010],cnt,res1,res2,T1,T2;
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&A[i],&B[i],&C[i]);
	for(int i=1;i<=n;i++)
	{
		M.clear();
		for(int j=1;j<i;j++)
		if((T1=B[i]*A[j])!=(T2=B[j]*A[i]))
		{
			float x=(B[i]*C[j]-B[j]*C[i])/(float)(T2-T1),
			y=(A[i]*C[j]-C[i]*A[j])/(float)(T1-T2);
			Point P=Point(x,y);
			if(!G.count(P))G[P]=2,p[++cnt]=P;
			else if(!M.count(P))G[P]++,M[P]=1;
		}
	}
	for(int i=1;i<=cnt;i++)res1=max(res1,G[p[i]]);
	for(int i=1;i<=cnt;i++)
	if(res1==G[p[i]])res2++;
	printf("%d %d\n",res1,res2);
	fclose(stdin);fclose(stdout);
	return 0;
}
