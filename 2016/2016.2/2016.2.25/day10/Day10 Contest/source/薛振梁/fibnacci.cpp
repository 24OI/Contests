#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define MOD 1000000001

typedef long long ntype;

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

void initialize();
void quit();
void fibnacci(const int x);

static ntype n,m;
static ntype a[100010];
static ntype F[100010];

inline void add(int x,ntype v){
	for(; x<=n;x+=x&(-x)){
		a[x]+=v;
		a[x]%=MOD;
	}
}

inline ntype query(int r){
	ntype result=0;
	for(;r>0;r-=r&(-r)){
		result+=a[r];
		result%=MOD;
	}
	return result;
}

int main(){
	initialize();

	for(int cnt=0;cnt<m;cnt++){
		int command=read();
		int l=read();
		int r=read();
		
		switch(command){
			case 1:
				for(int i=l;i<=r;i++){
					add(i,F[i-l+1]);
				}
			break;
			case 2:
				printf("%lld\n",query(r)-query(l-1));
			break;
		}
	}

	quit();	
	return 0;
}

void fibnacci(const int x){
	F[0]=0;
	F[1]=1;
	
	for(int i=2;i<=x;i++){
		F[i]=F[i-1]+F[i-2];
		F[i]%=MOD;
	}
}

void initialize(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	
	memset(a,0,sizeof(a));
	fibnacci(100001);
	
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		add(i,read());
	}
}

void quit(){
	
	fclose(stdin);
	fclose(stdout);
}