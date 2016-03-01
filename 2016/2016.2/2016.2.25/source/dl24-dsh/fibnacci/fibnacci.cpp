#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int fibo[100002];
int tree[400002],line[100002];
int t1,t2,t3,op,t4,t5,t6;
int n,m;
const int inf=1000000001;

void getfibo(){
	fibo[1]=1;
	for (int i=2;i<=n+1;i++){
		fibo[i]=fibo[i-2]+fibo[i-1];
		fibo[i]%=inf;
	}
	return;
}

void in(){
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%d",&line[i]);
}

void maketree(int l,int r,int now){
	if (l==r){
		tree[now]=line[l];
		tree[now]%=inf;
		return;
	}
	maketree(l,(l+r)/2,now*2);
	maketree((l+r)/2+1,r,now*2+1);
	tree[now]=tree[now*2]+tree[now*2+1];
	tree[now]%=inf;
	return;
}

void update(int l,int r,int now,int t,int num){
	if (l==r&&l==t){
		tree[now]+=num;
		tree[now]%=inf;
		//cout<<l<<" "<<r<<" "<<tree[now]<<endl;
		return;
	}
	if ((l+r)/2>=t) update(l,(l+r)/2,now*2,t,num);
	else update((l+r)/2+1,r,now*2+1,t,num);
	tree[now]=tree[now*2]+tree[now*2+1];
	tree[now]%=inf;
	//cout<<l<<" "<<r<<" "<<tree[now]<<endl;
	return;
}

int ask(int l,int r,int now,int f,int t){
	if (l==r&&l>=f&&l<=t){
		//cout<<"!"<<l<<" "<<r<<" "<<tree[now]<<endl;
		return tree[now];
	}
	
	if (r<f||l>t) return 0;
	
	if (l>=f&&r<=t){
		//cout<<"!"<<l<<" "<<r<<" "<<tree[now]<<endl;
		return tree[now];
	}
	int p1=ask(l,(l+r)/2,now*2,f,t);
	p1%=inf;
	int p2=ask((l+r)/2+1,r,now*2+1,f,t);
	p2%=inf;
	//cout<<"!"<<l<<" "<<r<<" "<<p1+p2<<endl;
	return (p1+p2)%inf;
}

void option(){
	scanf ("%d%d%d",&op,&t1,&t2);
	if (op==1){
		for (int i=t1;i<=t2;i++){
			update(1,n,1,i,fibo[i-t1+1]);
		}
	}
	else{
		printf ("%d\n",ask(1,n,1,t1,t2));
	}
}

void file(){
	freopen ("fibnacci.in","r",stdin);
	freopen ("fibnacci.out","w",stdout);
}

int main(){
	file();
	in();
	getfibo();
	maketree(1,n,1);
	for (int i=1;i<=m;i++) option();
	
	return 0;
}






















