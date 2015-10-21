#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int>build[202];
int n,a,b,k,sum;

void in(){
	scanf ("%d%d%d%d",&n,&a,&b,&k);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (abs(i-j)<abs(i-b)&&i!=j) build[i].push_back(j);
		}
	}
}

int ask(int f,int t){
	int sum=0;
	if (t==0) return 1;
	for (int i=0;i<build[f].size();i++){
		sum+=ask(build[f][i],t-1);
	}
	return sum;
}


int main(){
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	
	in();
	
	printf ("%d",ask(a,k));
	
	return 0;
}