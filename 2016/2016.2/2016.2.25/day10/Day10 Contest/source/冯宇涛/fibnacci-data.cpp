#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int main(){
	freopen("fibnacci.in","w",stdout);
	srand(time(0));
	printf("100000 100000\n");
	for(int i=0;i<100000;i++)
		printf("%d ",rand()%100000);
	printf("\n");
	for(int i=0;i<100000;i++){
		int op=rand()%2+1;
		int l=rand()%50000+1,r=l+500;
		if(l>r)swap(l,r);
		printf("%d %d %d\n",op,l,r);
	}
	return 0;
}
