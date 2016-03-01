#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define MOD 593119681

typedef int ntype;

inline ntype read(){
	ntype x=0;
	char c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while('0'<=c and c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	
	return x;
} 

inline bool dis(int u,int v){
	int x=u^v;
	// int cnt=0;
	// for(int i=0;i<=32 and cnt<2;i++){
	// 	if((1<<i)&x)
	// 		cnt++;
	// }
	
	// return cnt==1;
	return bitset<32>(x).count()==1;
}

inline int pow_of_two(int n){
	switch(n){
		case 0:return 1;
		case 1:return 2;
		case 2:return 4;
		case 3:return 8;
		case 4:return 16;
		case 5:return 32;
		case 6:return 64;
		case 7:return 128;
		case 8:return 256;
		case 9:return 512;
		case 10:return 1024;
		case 11:return 2048;
		case 12:return 4096;
		case 13:return 8192;
		case 14:return 16384;
		case 15:return 32768;
		case 16:return 65536;
		case 17:return 131072;
		case 18:return 262144;
	}
	
	return 233;
}

void initialize();
void quit();

static int n,t;
static int pow;
static vector<int> G[300000];
static int data1[300000];
static int data2[300000];
static int *front=data1;
static int *back=data2;

int main(){
	initialize();

	for(int cnt=0;cnt<t;cnt++){
		for(int i=0;i<pow;i++){
			front[i]=back[i];
		}
		
		for(int u=0;u<pow;u++){
			for(int j=0;j<G[u].size();j++){
				int v=G[u][j];
				
				back[v]+=front[u];
				back[v]%=MOD;
			}
		}
	}

	quit();	
	return 0;
}

void initialize(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	
	n=read();
	t=read();
	pow=pow_of_two(n);
	
	for(int i=0;i<pow;i++){
		data2[i]=data1[i]=read()%MOD;
	}
	
	for(int i=0;i<pow;i++){
		for(int j=i+1;j<pow;j++){
			if(dis(i,j)){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
}

void quit(){
	for(int i=0;i<pow;i++){
		printf("%d ",back[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
}