#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N[10]={200,500,1000,20000,100000,20000,100000,20000,50000,100000};
const int P[10]={200,500,1000,20000,100000,0,0,20000,50000,100000};
const int T[10]={1,1,1,1,1,5000,5000,5000,5000,5000};
void Random(int C,int n,int p)
{
	int i,j,k,l;
	cout<<C<<endl;
	for(i=1;i<=C;i++)
	{
		j=rand()%n+1;
		k=rand()%n+1;
		if(j>k)swap(j,k);
		for(l=1;1<<l<j;l++);
		if(rand()%100==1)l=100000;
		l=rand()%min(l,p+1);
		cout<<j<<' '<<k<<' '<<l<<endl;
	}
}
char order[30];
void work()
{
	for(int i=0;i<10;i++)
	{
		sprintf(order,"field%d.in",i+1);
		freopen(order,"w",stdout);
		Random(T[i],N[i],P[i]);
	}
}
int main()
{
	srand(747929791);
	work();
	return 0;
}

