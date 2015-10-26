#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 260
using namespace std;

int n,A,B,C,D,E;
int p[4];
long long f[260][260];

void Add(int x,int y,long long z)
{
	f[x][y]=min(f[x][y],z);
}


int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,j,k,x,y,z;
	cin>>A>>B>>C>>D>>E>>n;
	p[0]=A;
	p[1]=A+B;
	p[2]=A+B+C;
	p[3]=A+B+C+D;
	memset(f,0x3f,sizeof f);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		--x;z=y-x;
		Add(x,y,z);
		Add(y,x,z);
	}
	for(k=0;k<=A+B+C+D+E;k++)
		for(i=0;i<=A+B+C+D+E;i++)
			for(j=1;j<=A+B+C+D+E;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	long long ans=min(min(	f[p[0]][p[1]]+f[p[2]][p[3]],
							f[p[0]][p[2]]+f[p[1]][p[3]]),
							f[p[0]][p[3]]+f[p[1]][p[2]]);
	if(ans>=0x3f3f3f3f3f3f3f3fll)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
