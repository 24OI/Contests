#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,i,j,l=0,maxx,sum,k;
int a[1010],b[1010],c[1010];
double X,Y;
int bri[1010];
double x[1010],y[1010];//第j个点的横纵坐标 亮度
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(i=1;i<=1000;i++) bri[i]=0;
	for(i=1;i<=n-1;i++)
	for(j=i+1;j<=n;j++)
	{
		int m=a[i]*b[j]-a[j]*b[i];
		if(m==0) 
		{
			if(a[i]==0&&b[j]==0) 
			{
				X=-c[j]/a[j];
				Y=-c[i]/b[i];
				bool b=0;
				for(k=1;k<=l;k++) if(x[k]==X&&y[k]==Y) {bri[k]++;b=1;}
				if(b==0) {l++;x[l]=X;y[l]=Y;bri[l]++;}
			}
			else if(a[j]==0&&b[j]==0) 
			{
				X=-c[i]/a[i];
				Y=-c[j]/b[j];
				bool b=0;
				for(k=1;k<=l;k++) if(x[k]==X&&y[k]==Y) {bri[k]++;b=1;}
				if(b==0) {l++;x[l]=X;y[l]=Y;bri[l]++;}
			}
		}
		else
		{
			X=(b[i]*c[j]-b[j]*c[i])/m;
			Y=(a[j]*c[i]-a[i]*c[j])/m;
			bool b=0;
			for(k=1;k<=l;k++) if(x[k]==X&&y[k]==Y) {bri[k]++;b=1;}
			if(b==0) {l++;x[l]=X;y[l]=Y;bri[l]++;}
		}
	}
	
	//for(i=1;i<=l;i++) cout<<x[i]<<' '<<y[i]<<' '<<bri[i]<<endl;
	
	for(i=1;i<=l;i++) if(bri[i]>maxx) maxx=bri[l];
	for(i=1;i<=l;i++) if(bri[i]==maxx) sum++;
	maxx=( sqrt(1+8*maxx)-1 )/2 +1;
	//cout<<l<<endl;
	
	cout<<maxx<<' '<<sum;
} 
/*
5
0 1 0
1 0 0
1 1 0
5 6 1
2 1 0


20
1 1 0
1 2 1
1 5 2
4 6 8
-1 2 4
1 1 -1
2 1 0
5 8 7
1 1 1
0 1 0
1 3 5
8 4 6
9 5 41
1 0 1
0 4 8
6 6 6
7 89 3
8 -5 6
9 45654 21
10 46 90
*/ 
