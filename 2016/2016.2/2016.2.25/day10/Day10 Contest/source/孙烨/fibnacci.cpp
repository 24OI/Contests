#include<iostream>
#include<cstdio>
using namespace std;
int f[100010];
int i,j,k;
int n,m,len;
int l[10010],r[10010],sumi[10010];
const long long M=1000000001;
void update(int x) {sumi[x]=(sumi[2*x]+sumi[2*x+1])%M;}
void build(int x,int L,int R)
{
	if(L>n) return;
	if(L>R) return;
	l[x]=L;r[x]=R;
	if(L==R) {scanf("%d",&sumi[x]);return;}
	int mid=(L+R)>>1;
	build(2*x,L,mid);build(2*x+1,mid+1,R);
	update(x);
}

void change(int x,int k,int v)
{
	if(l[x]==k&&r[x]==k) {sumi[x]+=v;return;}
	int mid=(l[x]+r[x])/2;
	if(k<=mid) change(2*x,k,v);
	else change(2*x+1,k,v);
	update(x); 
}

int Qsum(int x,int L,int R)
{
	if(l[x]>R||r[x]<L) return 0;
	if(L<=l[x]&&R>=r[x]) return sumi[x];
	return (Qsum(2*x,L,R)+Qsum(2*x+1,L,R))%M;
}
int main()
{
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	cin>>n>>m;
	len=1;
	while(len<n) len*=2;
	build(1,1,len);
	
	f[0]=0;f[1]=1;
	for(i=2;i<=50000;i++) f[i]=(f[i-1]+f[i-2])%M;
	for(i=1;i<=m;i++)
	{
		int op,le,ri;
		cin>>op>>le>>ri;
		if(op==1) for(int j=le;j<=ri;j++) change(1,j,f[j-le+1]);
		if(op==2) cout<<Qsum(1,le,ri)<<endl;
	}
	
}
/*
13 2
1 2 3 4 5 6 7 8 9 10 11 12 13
1 1 13
2 1 3
*/
