#include <cstdio>
#include <cassert>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n;
const double eps=1e-6;
inline int dcmp(const double &x){return x<-eps?-1:x>eps;}
typedef std::pair<double, double> pii;
inline bool cmp(const pii &i, const pii &j){return dcmp(i.first-j.first)?dcmp(i.first-j.first)<0:dcmp(i.second-j.second)<0;}
double A[1005], B[1005], C[1005];
namespace Force{
	std::pair<double, double> a[205*205];
	void solve(){
		int m=0, ans=1, anscnt=233;
		for (int i=1;i<=n;i++){
			if (!dcmp(A[i])&&!dcmp(B[i])) continue;
			for (int j=i+1;j<=n;j++){
				//if (m<218){printf("%d %d\n", i, j);}
				if (!dcmp(A[j])&&!dcmp(B[j])) continue;
				if (dcmp(A[i])&&dcmp(A[j])){
					double x=A[i], y=B[i], z=C[i], d=A[i]/A[j];
					x-=A[j]*d, y-=B[j]*d, z-=C[j]*d;
					if (dcmp(y)){
						y=-z/y, x=-(B[i]*y+C[i])/A[i];
						a[++m]=std::make_pair(x, y);
					}
				} else if (dcmp(B[i])&&dcmp(B[j])){
					double x=A[i], y=B[i], z=C[i], d=B[i]/B[j];
					x-=A[j]*d, y-=B[j]*d, z-=C[j]*d;
					if (dcmp(x)){
						x=-z/x, y=-(A[i]*x+C[i])/B[i];
						a[++m]=std::make_pair(x, y);
					}
				} else if (dcmp(A[i])){
					double x=-C[i]/A[i], y=-C[j]/B[j];
					a[++m]=std::make_pair(x, y);
				} else{
					double y=-C[i]/B[i], x=-C[j]/A[j];
					a[++m]=std::make_pair(x, y);
				}
			}
		}
		std::sort(a+1, a+m+1, cmp);
		for (int i=1;i<=m;i++){
			if (i>1&&!dcmp(a[i].first-a[i-1].first)&&!dcmp(a[i].second-a[i-1].second)) continue;
			double x=a[i].first, y=a[i].second;
			int t=0;
			for (int j=1;j<=n;j++){
				//printf("%.3f\n", A[j]*x+B[j]*y+C[j]);
				if (!dcmp(A[j]*x+B[j]*y+C[j])) t++;
			}
			//if (t!=2) printf("%d %d\n", i, t);
			//if (t==3) printf("%d %.6f %.6f\n", i, x, y);
			if (ans<t) ans=t, anscnt=1; else if (ans==t) anscnt++;
		}
		printf("%d %d\n", ans, anscnt);
	}
}
int main(){
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	n=getuint();
	int ans=0, anscnt=233;
	for (int i=1;i<=n;i++) scanf("%lf%lf%lf", &A[i], &B[i], &C[i]);
	if (n<=200) return Force::solve(), 0;
	static std::pair<double, double> a[1005];
	static int cnt[1005];
	for (int i=1;i<=n;i++){
		if (!dcmp(A[i])&&!dcmp(B[i])) continue;
		int m=0;
		for (int j=1;j<=n;j++) if (i!=j){
			if (!dcmp(A[j])&&!dcmp(B[j])) continue;
			if (dcmp(A[i])&&dcmp(A[j])){
				double x=A[i], y=B[i], z=C[i], d=A[i]/A[j];
				x-=A[j]*d, y-=B[j]*d, z-=C[j]*d;
				if (dcmp(y)){
					y=-z/y, x=-(B[i]*y+C[i])/A[i];
					a[++m]=std::make_pair(x, y);
				}
			} else if (dcmp(B[i])&&dcmp(B[j])){
				double x=A[i], y=B[i], z=C[i], d=B[i]/B[j];
				x-=A[j]*d, y-=B[j]*d, z-=C[j]*d;
				if (dcmp(x)){
					x=-z/x, y=-(A[i]*x+C[i])/B[i];
					a[++m]=std::make_pair(x, y);
				}
			} else if (!dcmp(A[i])){
				double y=-C[i]/B[i], x=-C[j]/A[j];
				a[++m]=std::make_pair(x, y);
			} else{
				double x=-C[i]/A[i], y=-C[j]/B[j];
				a[++m]=std::make_pair(x, y);
			}
		}
		for (int j=1;j<=m;j++) assert(!dcmp(a[j].first*A[i]+a[j].second*B[i]+C[i]));
		//for (int i=1;i<=m;i++) if (!dcmp(a[i].first+0.5)&&!dcmp(a[i].second)) printf("%d ", i);putchar('\n');
		for (int i=1;i<=n;i++) cnt[i]=0;
		std::sort(a+1, a+m+1, cmp);
		for (int l=1, r;l<=m;cnt[r-l+1]++, l=r+1){
			for (r=l;r<m&&!dcmp(a[l].first-a[r+1].first)&&!dcmp(a[l].second-a[r+1].second);r++);
			//if (r-l+2==3) printf("%.6f %.6f\n", a[l].first, a[l].second);
		}
		for (int i=n;i;i--) if (cnt[i]) {if (i>ans) ans=i, anscnt=cnt[i]; else if (i==ans) anscnt+=cnt[i];break;}
	}
	assert(anscnt%(ans+1)==0);
	printf("%d %d\n", ans+1, anscnt/(ans+1));
	return 0;
}

