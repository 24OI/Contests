#include <cstdio>
#include <cstring>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n, m;
const int mod=593119681;
inline void inc(int &a, int b){if ((a+=b)>=mod) a-=mod;}
int a[1<<18];
namespace Force{
	int b[1<<18];
	void solve(){
		for (;m--;){
			for (int i=0;i<1<<n;i++) for (int j=0;j<n;j++) inc(b[i^(1<<j)], a[i]);
			for (int i=0;i<1<<n;i++) if (b[i]) inc(a[i], b[i]), b[i]=0;
		}
		printf("%d", *a);for (int i=1;i<1<<n;i++) printf(" %d", a[i]);putchar('\n');
	}
};
namespace Force2{
	int N;
	struct Matrix{
		int a[64][64];
		inline void init0(){memset(a, 0, sizeof(a));}
		inline void init1(){init0();for (int i=0;i<N;i++) a[i][i]=1;}
		friend inline Matrix operator *(const Matrix &a, const Matrix &b){
			Matrix c;c.init0();
			for (int i=0;i<N;i++) for (int k=0;k<N;k++) for (int j=0;j<N;j++) c.a[i][j]=(c.a[i][j]+(long long)a.a[i][k]*b.a[k][j])%mod;
			return c;
		}
	};
	void solve(){
		N=1<<n;
		Matrix X, A;X.init0(), A.init1();
		for (int i=0;i<1<<n;X.a[i][i]=1, i++) for (int j=0;j<n;j++) X.a[i][i^(1<<j)]=1;
		for (;m;m>>=1, X=X*X) if (m&1) A=A*X;
		for (int i=0;i<1<<n;i++){
			int t=0;
			for (int j=0;j<1<<n;j++) t=(t+(long long)A.a[i][j]*a[j])%mod;
			if (i) putchar(' ');
			printf("%d", t);
		}putchar('\n');
	}
};
int main(){
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	n=getuint(), m=getuint();
	for (int i=0;i<1<<n;i++) a[i]=getuint();
	if (n<=10&&m<=1000) return Force::solve(), 0;
	if (n<=6) return Force2::solve(), 0;
	return 0;
}

