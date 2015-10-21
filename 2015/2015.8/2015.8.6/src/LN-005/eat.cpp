#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#include <algorithm>
#include <ctime>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
typedef long long ll;
struct qu
{
	int l,r;
}qujian[100005];
int arr[100005];
int cnter[100005];
int n,tot=0,tt=0;
int main(){
	open("eat.in","eat.out");
	for (int i = 0; i < 100005; ++i)
	{
		cnter[i]=1;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int l=0,r,last=arr[0],tag=false,q=0;
	for (int i = 1; i < n; ++i)
	{
		if(last>arr[i]){
			last=arr[i];
			++q;
		}else
			break;
	}
	last=arr[0];
	for (int i = q; i < n; ++i)
	{
		if(!tag && last<arr[i]){
			last=arr[i];
		}else if(!tag && last>arr[i]){
			last=arr[i];
			qujian[tot].l=i-1;
			tag=true;
		}else if(tag && last>arr[i]){
			last=arr[i];
		}else if(tag && last<arr[i]){
			last=arr[i];
			qujian[tot++].r=i-1;
			tag=false;
		}
		if(i==n-1 && tag){
			qujian[tot++].r=n-1;
		}
	}
	for (int i = 0; i < tot-1; ++i)
	{
		int tr=qujian[i].r+1;
		while(tr<qujian[i+1].l+1 && arr[qujian[i].l]>arr[tr]){
			++cnter[tt];
			++tr;
		}
		++tt;
	}
	int mm=(tot>0)?1:0;
	for (int i = 0; i < tt; ++i)
	{
		mm=max(mm,cnter[i]);
	}
	cout<<mm<<endl;
	
	return 0;
}
