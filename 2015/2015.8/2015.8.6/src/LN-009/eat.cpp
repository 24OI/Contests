#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>eat[100001];
int n,ct,tmp;

void in(){
	int n;
	scanf ("%d",&n);
	eat[0].push_back(0);
	for (int i=1;i<=n;i++){
		scanf ("%d",&tmp);
		eat[0].push_back(tmp);
	}
}

void eatfish(){
	for (int i=0;i<=100000;i++){
		ct=0;
		eat[i+1].push_back(0);
		
		for (int j=1;j<eat[i].size();j++){
			if (eat[i][j]>eat[i][j-1]){
				eat[i+1].push_back(eat[i][j]);
			}
		}
		
		if (eat[i].size()==eat[i+1].size()){
			printf ("%d",i);
			break;
		}
	}
}

int main(){
	freopen ("eat.in","r",stdin);
	freopen ("eat.out","w",stdout);
	
	in();
	eatfish();
	return 0;
}