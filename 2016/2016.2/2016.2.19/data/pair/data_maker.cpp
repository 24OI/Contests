#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N[10]={5,7,20,100,500,1000,5000,10000,20000,20000};//点数 
const int M[10]={10,10,10,1000,5000,10000,50000,100000,200000,200000};//边数 
const int S[10]={2,2,2,20,10,50,10,300,50,1};//块数 
char order[30];
int fa[20010];
int get(int x){return fa[x]==x?x:(fa[x]=get(fa[x]));}
void build(int id)
{
	printf("build:%d\n",id);
	sprintf(order,"pair%d.in",id);
	freopen(order,"w",stdout);
	int i,j,k,n=N[id],m=M[id],s=S[id],cnt=n;
	for(i=1;i<=n;i++)fa[i]=i;
	cout<<n<<' '<<m<<endl;
	for(i=1;i<=m;i++)
	{
		j=rand()%n+1;k=rand()%n+1;
		while(j==k||(get(j)!=get(k)&&cnt<=s))
		{
			j=rand()%n+1;
			k=rand()%n+1;
		}
		if(get(j)!=get(k))cnt--,fa[get(j)]=get(k);
		cout<<j<<" "<<k<<endl;
	}
	fclose(stdout);
	freopen("CON","w",stdout);
}
int main(int argc,char *argv[])
{
	srand((unsigned)time(NULL));
	/*——————数据生成器——————*/
	for(int i=0;i<10;i++)build(i);
	/*———数据生成器—————*/
	fclose(stdout);
	return 0;
}
