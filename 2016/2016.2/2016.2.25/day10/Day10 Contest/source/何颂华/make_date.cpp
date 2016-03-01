#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
#define ll long long
int n=1000,m=2000;
inline int Rand(int x)
 {return (1LL*rand()*rand()%x+rand()+10086)%x;}
int main()
 {
	 freopen("input.txt","w",stdout);
	 srand(time(NULL));
	 cout <<n<<' '<<m<<endl;
	 for (int i=1;i<=n;i++) cout <<Rand(100000000)<<' ';puts("");
	 for (int i=1;i<=m;i++)
	  {
		  int q=Rand(2)+1,w=Rand(n)+1,e=Rand(n)+1;
		  if (w>e) swap(w,e);
		  cout <<q<<' '<<w<<' '<<e<<endl;
	  }
	 return 0;
 }