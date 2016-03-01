#include<iostream>
#include<cstdio>
#define maxn 1025
#define maxm maxn * 11
using namespace std;
const int mod = 593119681;
struct edge{
	int np;
	int next;
}e[maxm];
int tot = 1;
int head[maxn];
int va[maxn];
int tadd[maxn];
int pows[maxn];
void add(int a,int b){
	e[++tot] = (edge) {b,head[a]};
	head[a] = tot;
}
int n,t;
int tmp;
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d %d",&n,&t);
	tmp = n;
	int base = 1;
	pows[0] = 1;
	for(int i =1;i<=n;i++){
		pows[i] = 2 * pows[i-1];
	}
	n = pows[n] -1;
	for(int i =0;i<=n;i++){
		scanf("%d",&va[i]);
	}
	for(int i =0;i<=n;i++){
		for(int j =0;j<tmp;j++){
			add(i,i^pows[j]);
		}
	}
	while(t--){
		for(int i =0;i<=n;i++){
			for(int ne = head[i];ne;ne = e[ne].next){
				tadd[e[ne].np] += va[i];
				while(tadd[e[ne].np] > mod){
					tadd[e[ne].np] -= mod;
				}
			}
		}
		for(int i =0;i<=n;i++){
			va[i] += tadd[i];
			while(va[i] > mod){
				va[i] -= mod;
			}
			tadd[i] = 0;
		}
	}
	for(int i =0;i<=n;i++){
		printf("%d\n",va[i]);
	}
	return 0;
}
