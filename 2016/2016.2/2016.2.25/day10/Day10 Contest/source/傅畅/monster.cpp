#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
//#define che
using namespace std;
typedef long long LL;
const LL MOD = 593119681;
const int maxn= 2000 +10;
struct Mat{
	int n;
	LL **a;
}tmp,ner,ans;
int n ,t;
LL inia[maxn];
void printMat(Mat ar){
	for (int i=0; i<ar.n; i++){
		printf("[%d ",ar.a[i][0]);
		for (int j=1; j<ar.n; j++)	printf(",%d",ar.a[i][j]);
		printf("]\n");
	}
}
void Mul(Mat a, Mat b ,Mat c){
	for (int i=0; i<a.n; i++)
		for (int j=0; j<b.n; j++){
			tmp.a[i][j] = 0;
			for (int k=0; k<a.n; k++)
				tmp.a[i][j] = ( tmp.a[i][j] + a.a[i][k] * b.a[k][j])%MOD;
		}
	for (int i=0; i<a.n; i++)
		for (int j=0; j<a.n; j++)
			c.a[i][j] = tmp.a[i][j];
	c.n= a.n;
}

void ppow(Mat base, int pw, Mat ans){
	if ( pw==0){
		for (int i=0; i<ans.n; i++)
			for (int j=0;j < ans.n; j++)	ans.a[i][j] =0;
		for (int i=0; i<ans.n ; i++)	ans.a[i][i] =1;
	}	else{
		ppow(base, pw>>1, ans);
		Mul(ans, ans, ans);
		#ifdef che
		printf("When pw=  %d:\n",(pw/2)*2);
		printMat(ans);
		#endif
		if ( pw &1) Mul(ans, base, ans);
	}
	#ifdef che
	printf("When pw=  %d:\n",pw);
	printMat(ans);
	#endif
}

void IniZ(Mat &ar){
	ar.a= new LL*[ar.n];
	for (int i=0; i<ar.n; i++){
		ar.a[i] =new LL[ar.n];
		for (int j=0; j<ar.n; j++)	ar.a[i][j] = 0;
	}
}

int main(){
	freopen("monster.in","rt",stdin);
	freopen("monster.out","wt",stdout);
	scanf("%d%d",&n, &t);
	int m = (1<<n);
	for (int i=0; i<m; i++){
		scanf("%I64d", &inia[i]);
		inia[i] %= MOD;
	}
	ner.n = tmp.n= ans.n=m;
	IniZ(ner);
	IniZ(tmp);IniZ(ans);

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++)
			if ( (i &(1<<j))==0){
				int k= i | (1<<j);
				ner.a[i][k] = ner.a[k][i] = 1;
			}
		ner.a[i][i]=1;
	}
	#ifdef che
	printf("Near Matrix:\n");
	printMat(ner);
	#endif
	ppow(ner, t, ans);
	#ifdef che
	printf("The Answer Mat:\n");
	printMat(ans);
	#endif
	for (int j=0; j<m; j++){
		LL sum = 0;
		for (int k=0; k<n; k++)
			sum = (sum + inia[k] * ans.a[k][j])%MOD;
		printf("%I64d ",sum);
	}
	printf("\n");
	return 0;
}
