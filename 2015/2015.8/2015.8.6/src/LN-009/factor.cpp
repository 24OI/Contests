#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int m[1000003],p[1000003],pt;
long long l,r;
bool flag;

void oula(){
    int k;
    for(int i=2;i<1000000;i++){
        if(m[i]==0){
            p[++pt]=i;
			m[i]=i;
		}
		
		for(int j=1;j<=pt;j++){
            k=p[j]*i;
			if (k>=1000000) break;
			m[k]=p[j];
        }
    }
}

int main(){
	freopen ("factor.in","r",stdin);
	freopen ("factor.out","w",stdout);
	
	oula();
	
	scanf ("%lld%lld",&l,&r);
	for (long long i=l;i<=r;i++){
		flag=0;
		for (int j=1;j<=pt;j++){
			if (i%p[j]==0){
				printf ("%d\n",p[j]);
				flag=1;
				break;
			}
		}
		if (flag==0) printf ("%lld\n",i);
	}
	
	
	
	return 0;
}