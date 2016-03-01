#include<cstdio>
using namespace std;

const long P= 593119681;
long f[2][1024*1024], t, n, m, i, j, k, l, a[20];

int main(){
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	scanf("%ld%ld", &n, &m);
	a[0]= 1;
	for(i= 0; i<20; i++) a[i+1]= a[i]<<1;
	for(i= 0; i<a[n]; i++) scanf("%ld", &f[0][i]);
	for(t= 1; t<=m; t++){
		k= t&1; l= k^1;
		for(i= 0; i<a[n]; i++){
			f[k][i]= f[l][i];
			for(j= 0; j<n; j++)
				f[k][i]= (f[k][i]+f[l][i^a[j]])% P;
		}
	}
	for(i= 0; i<a[n]; i++) printf("%ld ", f[k][i]);
	return 0;
}

