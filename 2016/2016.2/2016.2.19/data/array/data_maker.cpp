#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N[10]={100,5000,100000,100000,100000,500000,1000000,10000000,10000000,10000000};
const int type[10]={1,2,3,1,2,3,3,1,2,3};
char order[30];
int a[10000010];
long long Random(){return ((long long)rand()<<45)|((long long)rand()<<30)|((long long)rand()<<15)|((long long)rand()<<0);}
void build1(int id)
{
	printf("array:%d\n",id);
	sprintf(order,"array%d.in",id);
	freopen(order,"w",stdout);
	int i,j,k,n=N[id];
	cout<<n<<endl;
	for(i=1;i<=n;i++)a[i]=i;
	for(i=1;i<=n;i++)swap(a[i],a[Random()%i+1]);
	for(i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
	fclose(stdout);
	freopen("CON","w",stdout);
}
void build2(int id)
{
	printf("array:%d\n",id);
	sprintf(order,"array%d.in",id);
	freopen(order,"w",stdout);
	int i,j,k,n=N[id];
	for(i=1;i<=n;i++)a[i]=i;
	for(i=1;i<n-i;i++)if(i&1)swap(a[i],a[n-i]);
	for(i=1;i<=n/10;i++)swap(a[Random()%n+1],a[Random()%n+1]);
	cout<<n<<endl;
	if(n>100000)
	{
		for(i=n-100000+1;i<=n-50000;i++)a[i]=n-i;
		for(i=n-50000+1;i<=n;i++)a[i]=i-n+50000;
	}
	for(i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
	fclose(stdout);
	freopen("CON","w",stdout);
}
void build3(int id)
{
	printf("array:%d\n",id);
	sprintf(order,"array%d.in",id);
	freopen(order,"w",stdout);
	int i,j,k,n=N[id];
	for(i=1;i<=n/2;i++)a[i]=i<<1;
	for(i=n/2+1;i<=n;i++)a[i]=(i<<1)-1;
	for(i=1;i<n/2-i;i++)if(i&1)
	{
		swap(a[i],a[n/2-i]);
		swap(a[n/2+i],a[n-i]);
	}
	for(i=1;i<=n/10;i++)swap(a[Random()%n+1],a[Random()%n+1]);
	cout<<n<<endl;
	if(n>100000)
	{
		for(i=n-100000+1;i<=n-50000;i++)a[i]=n-i;
		for(i=n-50000+1;i<=n;i++)a[i]=i-n+50000;
	}
	for(i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
	fclose(stdout);
	freopen("CON","w",stdout);
}
int main(int argc,char *argv[])
{
	srand((unsigned)time(NULL));
	/*——————数据生成器——————*/
	for(int i=0;i<10;i++)
	if(type[i]==1)build1(i);
	else if(type[i]==2)build2(i);
	else if(type[i]==3)build3(i);
	/*———数据生成器—————*/
	fclose(stdout);
	return 0;
}
