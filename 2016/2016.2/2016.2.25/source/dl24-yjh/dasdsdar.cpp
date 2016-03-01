#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int f[100001];
int main()
{
	freopen("b.txt","w",stdout);
	f[0]=0;
	f[1]=1;
	for (int i=2; i<10001;i++)
	{f[i]=f[i-1]+f[i-2];
	cout<<f[i]<<endl;}
	f[1]=1 xor 1;
	
	return 0;
	}