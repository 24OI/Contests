#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define NMAX 1000
#define MOD 100007

typedef int ntype;
typedef float number;

struct Node{
	Node(number _x,number _y,int i,int j):x(_x),y(_y){
		insert(i);
		insert(j);
	}
	
	void insert(int l){
		lines.insert(l);
	}
	
	number x;
	number y;
	set<int> lines;
};

typedef vector<Node>::iterator iterator_t;

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

inline ntype read_with_sign(){
	ntype x=0,f=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c and c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	
	return x*f;
}

static int n;
static int answer;
static number a[NMAX];
static number b[NMAX];
static number c[NMAX];
static vector<Node> hb[MOD];

inline bool almost_equal(const number a,const number b){
	return fabs(a-b)<0.0001;
}

inline number compute_y(int i,number x){
	// Notice when B==0, no y exists.
	return -(a[i]/b[i])*x-c[i]/b[i];
}

inline number compute_x(int i,number y){
	// Notice when A==0, no x exists.
	return -(b[i]/a[i])*y-c[i]/a[i];
}

inline bool is_parrall(int i,int j){
	if(almost_equal(b[i],0.0) || almost_equal(b[j],0.0)){
		return almost_equal(b[i],b[j]);
	}else{
		return almost_equal(a[i]/b[i],a[j]/b[j]);
	}
}

inline void compute_point(int i,int j,number *output_x,number *output_y){
	if(almost_equal(a[i],0.0)){
		*output_y=-c[i]/b[i];
		*output_x=compute_x(j,*output_y);
	}else if(almost_equal(a[j],0.0)){
		*output_y=-c[j]/b[j];
		*output_x=compute_x(i,*output_y);
	}else if(almost_equal(b[i],0.0)){
		*output_x=-c[i]/a[i];
		*output_y=compute_y(j,*output_x);
	}else if(almost_equal(b[j],0.0)){
		*output_x=-c[j]/a[j];
		*output_y=compute_y(i,*output_x);
	}else{
		*output_x=(c[j]*b[i]-c[i]*b[j])/(a[i]*b[j]-a[j]*b[i]);
		*output_y=compute_y(i,*output_x);
	}
}

void initialize();
void quit();

inline int h(number x,number y){
	return abs((((long long)x)<<1)+(((long long)y)>>1))%MOD;
}

inline int query(number x,number y){
	int hash=h(x,y);
	
	for(iterator_t beg=hb[hash].begin();beg!=hb[hash].end();beg++){
		if(almost_equal(beg->x,x) and almost_equal(beg->y,y)){
			return beg->lines.size();
		}
	}
	
	return 0;
}

inline void increase(number x,number y,int i,int j){
	int hash=h(x,y);
	
	iterator_t beg;
	for(beg=hb[hash].begin();beg!=hb[hash].end();beg++){
		if(almost_equal(beg->x,x) and almost_equal(beg->y,y)){
			break;
		}
	}
	
	if(beg==hb[hash].end()){
		hb[hash].push_back(Node(x,y,i,j));
	}else{
		beg->insert(i);
		beg->insert(j);
	}
}

int main(){
	initialize();

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!is_parrall(i,j)){
				number x,y;
				compute_point(i,j,&x,&y);
				// printf("( %.4f, %.4f )\n",x,y);
				
				increase(x,y,i,j);
				
				int cnt=query(x,y);
				if(cnt>answer)answer=cnt;
			}
		}
	}

	quit();	
	return 0;
}

void initialize(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	
	n=read();
	for(int i=0;i<n;i++){
		a[i]=number(read_with_sign());
		b[i]=number(read_with_sign());
		c[i]=number(read_with_sign());
		
		// Ignore 0, 0, 0
		// if(a[i]==0.0 && a[i]==b[i] && a[i]==c[i])
		// 	i--,n--;
	}
	
	answer=0;
}

void quit(){
	int cnt=0;
	
	// Too slow here
	for(int i=0;i<MOD;i++){
		for(iterator_t beg=hb[i].begin();beg!=hb[i].end();beg++){
			if(beg->lines.size()==answer){
				cnt++;
			}
		}
	};
	
	printf("%d %d",answer,cnt);
	
	fclose(stdin);
	fclose(stdout);
}