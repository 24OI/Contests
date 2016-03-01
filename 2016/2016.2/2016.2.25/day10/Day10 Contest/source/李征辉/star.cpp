#include<cstdio>
#include<algorithm>
using namespace std;

const long N= 1005;
const double S= 0.000005;
bool se;
long a[N], b[N], c[N], i, j, n, k, m, num, _num;
double t[N];

double f(){
	if(b[j]*a[i]==b[i]*a[j]) return 1234.56789;
	if(se) return (double)(b[j]*c[i]-b[i]*c[j])/(double)(b[j]*a[i]-b[i]*a[j]);
	else return (double)(a[i]*c[j]-a[j]*c[i])/(double)(a[j]*b[i]-a[i]*b[j]);
}

double abs(double x){
	return x>0.000 ? x : -x;
}

int main(){
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	scanf("%ld", &n);
	for(i= 0; i<n; i++) scanf("%ld%ld%ld", &a[i], &b[i], &c[i]);
	m= 2; num= 0;
	for(i= 0; i<n; i++){
		k= 0;
		se= !a[i];
		for(j= 0; j<n; j++) if(i!=j){t[k]= f(); k++;}
		sort(t, t+k);
		t[k]= t[k-1]+100; t[k+1]= t[k]+100;
		for(j= 0; j<k;){
			while(abs(t[j]-1234.56789)<S) j++;
			if(j<k){
				_num= 1;
				while(abs(t[j]-t[j+_num])<S) _num++;
				_num++;
				if(_num>m){m= _num; num= 1;} else
				if(_num==m) num++;
				j+= _num-1;
			}
		}
	}
	printf("%ld %ld", m, num/m);
	return 0;
}
