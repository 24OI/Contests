#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct matrix
{int a[20][20];
};
struct matrix g,f,e;

int n,m;
int a[300100],b[300100],cnt[300100],c[30][30],inv_c[30][30];
const int mod=593119681;
const int phimod=6*10*16*148*3040;

matrix operator *(matrix A,matrix B)
{matrix ret;
 int i,j,k;
 for(i=0;i<=n;i++)
 	for(j=0;j<=n;j++)
	{	ret.a[i][j]=0;
		for(k=0;k<=n;k++)
		 	ret.a[i][j]=(ret.a[i][j]+(long long)A.a[i][k]*B.a[k][j]%mod)%mod;
	}
 return ret;
}

matrix fpow(matrix A,int j)
{matrix ret=e;
 while(j!=0)
 {	if(j&1) ret=ret*A;
 	A=A*A;
 	j/=2;
 }
 return ret;
}

int fpow(int i,int j)
{int ret=1;
 while(j!=0)
 {	if(j&1) ret=(long long)ret*i%mod;
 	i=(long long)i*i%mod;
 	j/=2;
 }
 return ret;
}

int main()
{freopen("monster.in","r",stdin);
 freopen("monster.out","w",stdout);

 int i,j,k;
 
 c[0][0]=1;
 for(i=1;i<=18;i++)
 {	c[i][0]=1;
 	for(j=1;j<=i;j++) 	
 		c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
 }
 for(i=0;i<=18;i++)
 	for(j=0;j<=i;j++)
 		inv_c[i][j]=fpow(c[i][j],phimod-1);
 for(i=0;i<=18;i++)
 	e.a[i][i]=1;
 for(i=1;i<(1<<18);i++)
 	cnt[i]=cnt[i-(i&(-i))]+1;
 
 scanf("%d%d",&n,&m);
 for(i=0;i<(1<<n);i++)
 	scanf("%d",&a[i]);
 for(i=0;i<=n;i++)
 {	if(i+1<=n) g.a[i][i+1]=n-i;
 	if(i-1>=0) g.a[i][i-1]=i;
	 g.a[i][i]=1;
 }
 g=fpow(g,m);
 /*
 for(i=0;i<=n;i++)
 {	for(j=0;j<=n;j++)
 		cout<<g.a[i][j]<<" ";
 	cout<<endl;
 }
 */
 f.a[0][0]=1;
 f=f*g;
 for(i=0;i<(1<<n);i++)
 	for(j=0;j<(1<<n);j++)
 	{	k=cnt[i^j];
 		b[j]=(b[j]+(long long)a[i]*f.a[0][k]%mod*inv_c[n][k]%mod)%mod;
 		//cout<<i<<" "<<j<<" "<<k<<" "<<f.a[0][k]<<" "<<inv_c[n][k]<<" "<< ""<<c[n][k]<<b[j]<<endl;
 	}
 for(i=0;i<(1<<n);i++)
 {	printf("%d",b[i]);
	if(i!=(1<<n)-1)
		printf(" ");
	else
		printf("\n");		 	
 }
 return 0;
}
