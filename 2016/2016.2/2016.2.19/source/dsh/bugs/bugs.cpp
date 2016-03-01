#include<cstdio>
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;

long long n,m,p;
long long ct;
long long p1,p2;
int t0;
long long t1,t2,t3,t4,t5,t6,t7,t8;

string f1,f2,f3,wtg;

struct Matrix
{
    int h,l;
    long long s[52][52];
    const Matrix operator=(const Matrix &x)
    {
        h=x.h;
        l=x.l;
        for(int i=0;i<5;i++)
         for(int j=0;j<5;j++)
          s[i][j]=x.s[i][j];
    }
};
Matrix M_mul(Matrix m1,Matrix m2)
{
    int h1=m1.h,h2=m2.h;
    int l1=m1.l,l2=m2.l;
    Matrix mans;
    mans.h=h1,mans.l=l2;
    memset(mans.s,0,sizeof(mans.s));
    for(int i=0;i<h1;i++)
     for(int j=0;j<l2;j++)
      for(int k=0;k<l1;k++)
       {
        mans.s[i][j]+=m1.s[i][k]*m2.s[k][j];
        mans.s[i][j]%=p;
       }
    return mans;
}
Matrix M_pow(Matrix m1,int k)
{
	if (k==1) return m1;
    Matrix M;
    if(k/2)
    {
        M=M_pow(m1,k/2);
        M=M_mul(M,M);
    }
    if(k%2)
    {
        if(k/2)
        M=M_mul(M,m1);
        else
        M=m1;
    }
    return M;
}
int main(){
	freopen ("bugs.in","r",stdin);
	freopen ("bugs.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	cin>>wtg;
	f1="0";
	f2="1";
	while (f1.find(wtg)==-1){
		ct++;
		f3=f1;
		f1=f2;
		f2=f3+f2;
		//cout<<ct<<" "<<f1<<" "<<f2<<endl;
	}
	if (n<ct){
		cout<<0<<endl;
		return 0;
	}
	if (n==ct){
		cout<<1<<endl;
		return 0;
	}
	while (t0!=-1){
		t0=f1.find(wtg,t0);
		
		//cout<<t0<<endl;
		if (t0!=-1){
			p1++;
			t0++;
		}
	}
	//cout<<f1<<endl;
	ct++;
	f3=f1;
	f1=f2;
	f2=f3+f2;
	t0=0;
	//cout<<ct<<" "<<f1<<" "<<f2<<endl;
	
	
	while (t0!=-1){
		t0=f1.find(wtg,t0);
		//cout<<t0<<endl;
		if (t0!=-1){
			p2++;
			t0++;
		}
	}
	t2=p2;
	
	p2-=p1;
	t1=p1;

	for (int i=ct+1;i<=n;i++){
		t3=t1+t2;
		t3%=p;
		if ((i-ct)&1) t3+=p1;
		else t3+=p2;
		t3%=p;
		t1=t2;
		t2=t3;
	}
	cout<<t2<<endl;
	return 0;
}














