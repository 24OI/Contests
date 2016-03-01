#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[1050];
inline int Read()
 {
	 int x=0;char y;
	 do y=getchar(); while (y<'0'||y>'9');
	 do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
	 return x;
 }

int main()
 {
	 freopen("output.txt","r",stdin);
	 while (scanf("%d",&a[n+1])!=EOF) n++;
	 fclose(stdin);
	 freopen("out.txt","r",stdin);int k=0;
	 while (scanf("%d",&k)!=EOF)
	  if (k!=a[++m]) {cout <<m<<endl;return 0;}
	 cout <<"Aha"<<endl;
 }